#include "A2.hpp"

void newton (CMyVector (*function)(CMyVector x), CMyVector start){
    const double limit = 0.00001;
    CMyVector vec = start, funVec = function(vec), deltaVec = vec;
    CMyMatrix mat = jacobi(vec, function), inv = mat.invers();
    double vecLen = funVec.getLength();
    int cnt = 0;
    
    while(cnt < 50 && vecLen >=limit){
        
        deltaVec = inv*funVec;
        deltaVec = -1*deltaVec;
        
        std::cout << "Schritt " << cnt << ":" << std::endl;
        std::cout << "x = ";
        vec.print();
        std::cout << "f(x) = ";
        funVec.print();
        std::cout << "f'(x) = " << std::endl;
        mat.print();
        std::cout << "(f'(x))^(-1) = " << std::endl;
        inv.print();
        std::cout << "dx = ";
        deltaVec.print();
        std::cout << "||f(x)|| = " << vecLen << std::endl << std::endl;
        
        vec = vec + deltaVec;
        funVec = function(vec);
        mat = jacobi(vec, function);
        inv = mat.invers();
        vecLen = funVec.getLength();
        ++cnt;
    }
    if(cnt == 50){
        std::cout << "Ende wegen Schritte = 50 bei" << std::endl;
    }else std::cout << "Ende wegen ||f(x)||<1e-5 bei" << std::endl;
    
    std::cout << "x = ";
    vec.print();
    std::cout << "f(x) = ";
    funVec.print();
    std::cout << "||f(x)|| = " << vecLen << std::endl << std::endl;
    
}

CMyMatrix jacobi(CMyVector x, CMyVector (*function)(CMyVector x)){
    
    CMyVector *mat = new CMyVector(new double[x.getDimension()], x.getDimension());
    CMyVector *cur = mat;
    
    CMyVector test = function(x);
    int limit = test.getDimension();
    int cnt = 0;
    while(cnt < limit){
        *cur = gradient(x, function, cnt);
        ++cur;
        ++cnt;
    }
    CMyMatrix *res = new CMyMatrix(mat, mat->getDimension(), cnt);
    return *res;
}

CMyVector gradient(CMyVector x, CMyVector (*function)(CMyVector x), int pos){
    try{
        const double h = 0.0001;
        int dim = x.getDimension();
        
        CMyVector res = CMyVector(new double[dim], dim);
        double val;
        
        for(int i=0; i<x.getDimension(); i++){
            CMyVector XandH = x;
            XandH.setComponent(i, XandH.getComponent(i)+h);
            val = function(XandH).getComponent(pos);
            val -= function(x).getComponent(pos);
            val /= h;
            res.setComponent(i, val);
        }
        
        return res;
    }catch(int e){
        throw e;
    }
}

CMyVector f2_1(CMyVector vec){
    double w= vec.getComponent(0);
    double x= vec.getComponent(1);
    double y= vec.getComponent(2);
    double z= vec.getComponent(3);
    CMyVector *res = new CMyVector(new double[3], 3);
    res->setComponent(0, w*x*exp(y));
    res->setComponent(1, x*y*z);
    res->setComponent(2, z);
    return *res;
}

CMyVector f2_2(CMyVector vec){
    double x= vec.getComponent(0);
    double y= vec.getComponent(1);
    CMyVector *res = new CMyVector(new double[2], 2);
    res->setComponent(0, (x*x*x) * (y*y*y) - 2*y);
    res->setComponent(1, x - 2);
    return *res;
}
