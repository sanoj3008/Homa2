#pragma once
#include <stdio.h>
#include <math.h>

class CMyVector{
private:
    double *vector;
    int dimension;
    
public:
    CMyVector():vector{nullptr},dimension{0}{}
    CMyVector(double *vec, int dim): vector(vec), dimension(dim){}
    CMyVector(const CMyVector& orig);
    
    int getDimension()const{return dimension;}
    void setComponent(int pos, double value);
    double getComponent(int pos)const;
    
    double getLength()const;
    void print()const;
    
    friend CMyVector& operator+(const CMyVector a, const CMyVector b);
    friend CMyVector& operator*(double lambda, const CMyVector a);
    CMyVector& operator=(const CMyVector vec);
};
