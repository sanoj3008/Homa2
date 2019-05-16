#include "A4.hpp"

std::vector<CComplex>  werte_einlesen(const char *dateiname){
    int i, N, idx;
    double re, im;
    std::vector<CComplex> werte;
    // File oeffnen
    std::ifstream fp;
    fp.open(dateiname);
    // Dimension einlesen
    fp >> N;
    // Werte-Vektor anlegen
    werte.resize(N);
    CComplex null = CComplex();
    for (i = 0; i<N; i++)
        werte[i] = null;
    // Eintraege einlesen und im Werte-Vektor ablegen
    while (!fp.eof())
    {
        fp >> idx >> re >> im;
        CComplex a(re,im);
        werte[idx] = a;
    }
    // File schliessen
    fp.close();
    
    return werte;
}

void werte_ausgeben(const char *dateiname, std::vector<CComplex> werte, double epsilon){
    int i;
    int N = werte.size();
    // File oeffnen
    std::ofstream fp;
    fp.open(dateiname);
    // Dimension in das File schreiben
    fp << N << std::endl;
    // Eintraege in das File schreiben
    fp.precision(10);
    for (i = 0; i < N; i++)
        if (werte[i].abs() > epsilon)
            fp << i << "\t" << werte[i].getReal() << "\t" << werte[i].getImaginary() << std::endl;
        //else fp << i << "\t" << INT_MIN << "\t" << INT_MIN << std::endl;
    // File schliessen
    fp.close();
}

double rnd(double val){
    const int points = 5;
    int tmp = val*pow(10, points);
    double res = (tmp) / pow(10.0, points);
    return res;
}

CComplex hin(std::vector<CComplex> values, long len, int pos){
    double reRes = 0, imRes = 0;
    
    for(int i=0; i<len; i++){
        reRes += values[i].getReal()*cos((2.*pos*i*M_PI)/len);
    }
    reRes *= (2./len);
    
    for(int i=0; i<len; i++){
        imRes += sin((2.*pos*i*M_PI)/len) * values[i].getReal();
    }
    imRes *= (2./len);
    
    /*reRes = rnd(reRes);
     imRes = rnd(imRes);*/
    
    return CComplex(reRes, imRes);
}

double re(std::vector<CComplex> values, long len, int pos){
    if(values[pos].getReal() == 0){
        return 0;
    }
    double res = 0.5*values[0].getReal();
    if(len%2 == 0){
        for(int i=1; i<=((len/2)-1); i++){
           //if(values[i].getReal() != INT_MIN){
                res += values[i].getReal()*cos((2.*pos*i*M_PI)/len) + values[i].getImaginary()*sin((2.*pos*i*M_PI)/len);
            //}
        }
        res += 0.5*values[len/2].getReal()*cos(M_PI*pos);
    }else{
        for(int i=1; i<=((len-1)/2); i++){
            res += values[i].getReal() * cos((2.*pos*i*M_PI)/len) + values[i].getImaginary()*sin((2.*pos*i*M_PI)/len);
        }
    }
    return res;
}

CComplex hinNew(std::vector<CComplex> values, long len, int pos){
    CComplex res = CComplex();
    for(int k=0; k<=(len-1); k++){
        res = res + values[k].getReal()*CComplex((-2.*M_PI*k*pos)/len);
    }
    return (1/sqrt(len))*res;
}

double reNew(std::vector<CComplex> values, long len, int pos){
    double res = 0;
    for(int n=0; n<=(len-1); n++){
        res = res + (values[n] * CComplex((2.*M_PI*n*pos)/len)).getReal();
    }
    return (1/sqrt(len))*res;
}

std::vector<CComplex> transformation(std::vector<CComplex> values, bool enable){
    std::vector<CComplex> res;
    long length = values.size();
    res.resize(length);
    CComplex tmp = CComplex();
    for(int i=0; i<length; i++){
        res[i] = tmp;
    }
    
    if(enable){
        for(int i=0; i<length; i++){
            res[i] = hinNew(values, length, i);
        }
    }else{
        for(int i=0; i<length; i++){
            tmp = CComplex(reNew(values, length, i), 0);
            res[i] = tmp;
        }
    }
    return res;
}

void deviation(std::vector<CComplex> a, std::vector<CComplex> b, double epsilon){
    double max = 0, tmp = 0;
    for(int i=0; i<a.size(); i++){
        if(b[i].getReal() != 0){
            tmp = a[i].getReal()-b[i].getReal();
            if(tmp < 0){
                tmp *= -1;
            }
            if(tmp > max){
                max = tmp;
            }
        }
    }
    std::cout << "Die maximale Abweichung bei e = " << epsilon << " liegt bei " << max << std::endl;
}

