#include "01_02.hpp"
#include "CMyVector.hpp"

CMyVector gradient(CMyVector x, double (*function)(CMyVector x)){
    const double h = 0.00000001;
    int dim = x.getDimension();
    
    CMyVector XandH = CMyVector(nullptr, 0);
    CMyVector res = CMyVector(new double[dim], dim);
    double val;
    
    for(int i=0; i<x.getDimension(); i++){
        XandH = x;
        XandH.setComponent(i, XandH.getComponent(i)+h);
        val = (function(XandH)-function(x))/h;
        res.setComponent(i, val);
    }
    
    return res;
}
