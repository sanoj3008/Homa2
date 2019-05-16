#pragma once
#include <iostream>
#include "CMyVector.hpp"

class CMyMatrix{
private:
    CMyVector *matrix;
    int dimensionX, dimensionY;
public:
    CMyMatrix(CMyVector *mat, int x=2, int y=2): matrix(mat), dimensionX(x), dimensionY(y){}
    
    void setComponent(double val, int x, int y);
    double getComponent(int x, int y) const;
    int getDimX(){return dimensionX;}
    int getDimY(){return dimensionY;}
    
    CMyMatrix invers()const;
    void print()const;
    
    friend CMyVector operator*(CMyMatrix A, CMyVector x);
};
