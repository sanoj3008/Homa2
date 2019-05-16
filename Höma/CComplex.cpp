//
//  CComplex.cpp
//  Höma
//
//  Created by Jonas Schell on 21.03.19.
//  Copyright © 2019 Jonas Schell. All rights reserved.
//

#include "CComplex.hpp"

double CComplex::abs(){
    double realSq = real*real;
    double imSq = imaginary*imaginary;
    return sqrt(realSq+imSq);
}

CComplex operator+(CComplex a, CComplex b){
    double reNew = a.getReal() + b.getReal();
    double imNew = a.getImaginary() + b.getImaginary();
    CComplex *res = new CComplex(reNew, imNew);
    return *res;
}

CComplex operator*(CComplex a, CComplex b){
    double reNew = (a.getReal()*b.getReal()) - (a.getImaginary()*b.getImaginary());
    double imNew = (a.getReal()*b.getImaginary()) + (b.getReal()*a.getImaginary());
    CComplex *res = new CComplex(reNew, imNew);
    return *res;
}

CComplex operator*(double a, CComplex b){
    double reNew = b.getReal()*a;
    double imNew = b.getImaginary()*a;
    CComplex *res = new CComplex(reNew, imNew);
    return *res;
}
