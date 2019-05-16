#pragma once
#include <iostream>
#include "CMyVector.hpp"

class CDGLSolver{
private:
    CMyVector (*functionFO)(CMyVector y, double x);
    double (*functionHO)(CMyVector y, double x);
    bool isFO;
public:
    CDGLSolver(CMyVector (*func)(CMyVector y, double x)): functionFO(func), functionHO(nullptr), isFO{true}{}
    CDGLSolver(double (*func)(CMyVector y, double x)): functionFO(nullptr), functionHO(func), isFO{false}{}
    
    CMyVector ableitungen(CMyVector y, double x);
    void euler(double start, CMyVector y, double end, int numSteps, double sol);
    void heun(double start, CMyVector y, double end, int numSteps, double sol);
};
