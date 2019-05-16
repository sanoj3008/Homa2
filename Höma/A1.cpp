#include <iostream>
#include "A1.hpp"

void optimize(double (*function)(CMyVector x), char name, CMyVector start, double lambda){
    std::cout << "Berechnungen beim Gradientenverfahren zur Testfunktion " << name << ":" << std::endl << std::endl;
    
    const double lim = 0.00001;
    CMyVector cur = start, next = cur, test = cur, grad = gradient(cur, function);
    double gradLen = grad.getLength();
    double funCur = 0.0, funNext = 0.0, funTest = 0.0;
    int cnt = 0;
    
    while(cnt < 50 && gradLen >= lim){
        cur = next;
        next = cur + lambda*grad;
        funCur = function(cur);
        funNext = function(next);
        
        std::cout << "Schritt " << cnt << std::endl;
        std::cout << "x = ";
        cur.print();
        std::cout << "Lambda = " << lambda << std::endl;
        std::cout << name << "(x) = " << funCur << std::endl;
        std::cout << "grad " << name << "(x) = ";
        grad.print();
        std::cout << "||grad "<<name<<"(x)|| = " << gradLen << std::endl << std::endl;
        std::cout << "x_neu = ";
        next.print();
        std::cout << "f(x_neu) = " << funNext << std::endl << std::endl;
        
        if(funNext > funCur){
            std::cout << "Test mit doppelter Schrittweite (lambda = " << lambda*2 << "):" << std::endl;
            test = cur + 2*lambda*grad;
            funTest = function(test);
            std::cout << "x_test = ";
            test.print();
            std::cout << "f(x_test) = " << funTest << std::endl;
            if(funTest > funNext){
                lambda *= 2;
                next = test;
                std::cout << "verdoppele Schrittweite!" << std::endl << std::endl;
            }else{
                std::cout << "behalte alte Schrittweite!" << std::endl << std::endl;
            }
        }else{
            while (funNext <= funCur) {
                lambda *= 0.5;
                next = cur + lambda*grad;
                funNext = function(next);
                std::cout << "halbiere Schrittweite (lambda = " << lambda <<"):" << std::endl;
                std::cout << "x_neu = ";
                next.print();
                std::cout << "f(x_neu) = " << funNext << std::endl << std::endl;
            }
        }
        grad = gradient(next, function);
        gradLen = grad.getLength();
        cnt++;
    }
    if(cnt == 50){
        std::cout << "Ende wegen Schrittanzahl = 50 bei" << std::endl;
    }else{
        std::cout << "Ende wegen ||grad f(x)||<1e-5 bei" << std::endl;
    }
    std::cout << "x = ";
    next.print();
    std::cout << "lambda = " << lambda << std::endl;
    std::cout << name << "(x) = " << funNext << std::endl;
    std::cout << "grad " << name << "(x) = ";
    grad.print();
    std::cout << "||grad "<<name<<"(x)|| = " << gradLen << std::endl << std::endl;
}

CMyVector gradient(CMyVector x, double (*function)(CMyVector x)){
    const double h = 0.00000001;
    int dim = x.getDimension();
    
    CMyVector res = CMyVector(new double[dim], dim);
    double val;
    
    for(int i=0; i<x.getDimension(); i++){
        CMyVector XandH = x;
        XandH.setComponent(i, XandH.getComponent(i)+h);
        val = function(XandH);
        val -= function(x);
        val /= h;
        res.setComponent(i, val);
    }
    
    return res;
}

double f1(CMyVector vec){
    double x = vec.getComponent(0);
    double y = vec.getComponent(1);
    double res = sin(x + (y*y));
    res += y*y*y;
    res -= 6*y*y;
    res += 9*y;
    return  res;
}

double g1(CMyVector vec){
    double x = vec.getComponent(0);
    double y = vec.getComponent(1);
    double z = vec.getComponent(2);
    double res = 2*x*x;
    res -= 2*x*y;
    res += y*y;
    res += z*z;
    res -= 2*x;
    res -= 4*z;
    res *= -1;
    return  res;
}
