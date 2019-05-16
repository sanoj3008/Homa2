#include "CMyMatrix.hpp"

void CMyMatrix::setComponent(double val, int x, int y){
    if(x >= 0 && x < dimensionX && y >= 0 && y < dimensionY){
        CMyVector vec = matrix[y];
        vec.setComponent(x, val);
    }
}

double CMyMatrix::getComponent(int x, int y)const{
    double res = 0;
    if(x >= 0 && x < dimensionX && y >= 0 && y < dimensionY){
        CMyVector vec = matrix[y];
        res = vec.getComponent(x);
    }
    return res;
}

CMyMatrix CMyMatrix::invers()const{
    if(dimensionX == 2 && dimensionY == 2){
        CMyVector z1 = matrix[0];
        CMyVector z2 = matrix[1];
        double det = (z1.getComponent(0)*z2.getComponent(1) - z1.getComponent(1)*z2.getComponent(0));
        if(det == 0) throw 0;
        det = 1/det;
        
        /*CMyVector *mat = new CMyVector(new double[2],2), *cur = mat;
        cur->setComponent(0, det*z2.getComponent(1));
        cur->setComponent(1, -1*det*z1.getComponent(1));
        ++cur;
        cur = new CMyVector(new double[2], 2);
        cur->setComponent(0, -1*det*z2.getComponent(0));
        cur->setComponent(1, det*z1.getComponent(0));*/
        
        CMyVector *mat = new CMyVector[2];
        mat[0] = CMyVector(new double[2], 2);
        mat[0].setComponent(0, det*z2.getComponent(1));
        mat[0].setComponent(1, -1*det*z1.getComponent(1));
        mat[1] = CMyVector(new double[2], 2);
        mat[1].setComponent(0, -1*det*z2.getComponent(0));
        mat[1].setComponent(1, det*z1.getComponent(0));

        
        CMyMatrix *res = new CMyMatrix(mat, 2, 2);
        return *res;
    }else{
        throw -1;
    }
}

CMyVector operator*(CMyMatrix A, CMyVector x){
    int dimX = A.getDimX();
    int dimY = A.getDimY();
    double val = 0;
    int cnt = 0;
    
    CMyVector *res = new CMyVector(new double[dimY], dimY);
    for(int i=0; i<A.getDimY(); i++){
        for(int j=0; j< dimX; j++){
            val += x.getComponent(cnt) * A.getComponent(j, i);
            ++cnt;
        }
        res->setComponent(i, val);
        val = 0;
        cnt = 0;
    }
    return *res;
}

void CMyMatrix::print()const{
    std::cout << "( ";
    for(int i=0; i<dimensionY; i++){
        for(int j=0; j<dimensionX; j++){
            std::cout << matrix[i].getComponent(j);
            if(j<dimensionX-1) std::cout << "; ";
        }
        if(i<dimensionY-1) std::cout << std::endl;
    }
    std::cout << " )" << std::endl;
}
