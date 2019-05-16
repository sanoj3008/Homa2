#pragma once
#include "CMyVector.hpp"

void optimize(double (*function)(CMyVector x), char name, CMyVector start, double lambda = 1.0);

CMyVector gradient(CMyVector x, double (*function)(CMyVector x));

double f1(CMyVector vec);
double g1(CMyVector vec);
