//
//  CMyVector.cpp
//  Höma
//
//  Created by Jonas Schell on 12.03.19.
//  Copyright © 2019 Jonas Schell. All rights reserved.
//

#include "CMyVector.hpp"
#include <iostream>

CMyVector::CMyVector(const CMyVector& orig){
    dimension = orig.getDimension();
    vector = new double[dimension];
    for(int i=0; i<dimension; i++){
        vector[i] = orig.getComponent(i);
    }
}

void CMyVector::setComponent(int pos, double value){
    if(pos >= 0 && pos < dimension){
        vector[pos] = value;
    }else{
        throw -1;
    }
}

double CMyVector::getComponent(int pos)const{
    if(pos >= 0 && pos < dimension){
        return vector[pos];
    }else{
        throw -1;
    }
}

CMyVector& operator+(const CMyVector a, const CMyVector b){
    int dim = a.getDimension();
    if(dim == b.getDimension()){
        CMyVector *res = new CMyVector(new double[dim], dim);
        double val;
        
        for(int i=0; i<dim; i++){
            val = a.getComponent(i) + b.getComponent(i);
            res->setComponent(i, val);
        }
        return *res;
    }else{
        throw -1;
    }
}

CMyVector& operator*(double lambda, const CMyVector a){
    int dim = a.getDimension();
    CMyVector *res = new CMyVector(new double[dim], dim);
    double val;
    
    for(int i=0; i<dim; i++){
        val = lambda*a.getComponent(i);
        res->setComponent(i, val);
    }
    return *res;
}

CMyVector& CMyVector::operator=(const CMyVector vec){
    dimension = vec.getDimension();
    vector = new double[dimension];
    for(int i=0; i<dimension; i++){
        vector[i] = vec.getComponent(i);
    }
    return *this;
}

double CMyVector::getLength()const{
    double res = 0;
    for(int i=0; i<dimension; i++){
        res += vector[i] * vector[i];
    }
    return sqrt(res);
}

void CMyVector::print()const{
    std::cout << "(";
    for(int i=0; i<dimension; i++){
        std::cout << vector[i];
        if(i<dimension-1) std::cout << ";";
    }
    std::cout << ")" << std::endl;
}
