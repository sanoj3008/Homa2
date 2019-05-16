#pragma once
#include <iostream>
#include <math.h>
#include "CMyMatrix.hpp"
#include "CMyVector.hpp"

CMyMatrix jacobi(CMyVector x, CMyVector (*function)(CMyVector x));

CMyVector f2_1(CMyVector vec);

CMyVector f2_2(CMyVector vec);

CMyVector gradient(CMyVector x, CMyVector (*function)(CMyVector x), int pos);

void newton (CMyVector (*function)(CMyVector x), CMyVector start);
