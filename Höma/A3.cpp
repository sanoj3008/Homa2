#include "A3.hpp"

CMyVector funcTest(CMyVector y, double x){
    CMyVector res = CMyVector(new double[1], 1);
    res.setComponent(0, -x*y.getComponent(0));
    return res;
}

CMyVector func1(CMyVector y, double x){
    CMyVector res = CMyVector(new double[2], 2);
    double tmp = 2*y.getComponent(1) - x*y.getComponent(0);
    res.setComponent(0, tmp);
    tmp = y.getComponent(0)*y.getComponent(1)-2*x*x*x;
    res.setComponent(1, tmp);
    return res;
}

double func2(CMyVector y, double x){
    return 2*x*y.getComponent(1)*y.getComponent(2) + 2*y.getComponent(0)*y.getComponent(0)*y.getComponent(1);
}
