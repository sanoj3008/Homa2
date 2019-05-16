#pragma once
#include <math.h>

class CComplex{
private:
    double real;
    double imaginary;
public:
    CComplex(): real{0}, imaginary{0} {}
    CComplex(double r, double i): real{r}, imaginary{i}{}
    CComplex(double phi): real{cos(phi)}, imaginary{sin(phi)}{}
    
    double getReal(){return real;}
    double getImaginary(){return imaginary;}
    
    double abs();
    
    friend CComplex operator+(CComplex a, CComplex b);
    friend CComplex operator*(CComplex a, CComplex b);
    friend CComplex operator*(double a, CComplex b);
};
