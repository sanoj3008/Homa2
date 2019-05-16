#include "CDGLSolver.hpp"

CMyVector CDGLSolver::ableitungen(CMyVector y, double x){
    if(isFO){
        return functionFO(y,x);
    }else{
        int dim = y.getDimension();
        CMyVector res = CMyVector(new double[dim], dim);
        for(int i=0; i<dim-1; i++){
            res.setComponent(i, y.getComponent(i+1));
        }
        res.setComponent(dim-1, functionHO(y,x));
        return res;
    }
}

void CDGLSolver::euler(double start, CMyVector y, double end, int numSteps, double sol){
    double h = (end-start)/numSteps;
    CMyVector pre = y, cur = y;
    double x = start;
    
    std::cout << "Schritt 0:" << std::endl;
    std::cout << "    x = " << x << std::endl;
    std::cout << "    y = ";
    pre.print();
    
    std::cout << "    y' = ";
    cur = ableitungen(pre, x);
    cur.print();
    
    std::cout << std::endl;
    
    cur = pre + h * cur;
    pre = cur;
    
    for(int i=1; i<numSteps; i++){
        x += h;
        std::cout << "Schritt " << i << ":" << std::endl;
        std::cout << "    x = " << x << std::endl;
        std::cout << "    y = ";
        pre.print();
        
        std::cout << "    y' = ";
        cur = ableitungen(pre, x);
        cur.print();
        std::cout << std::endl;
        
        cur = pre + h * cur;
        pre = cur;
    }
    std::cout << "Ende bei:" << std::endl;
    x += h;
    std::cout << "    x = " << x << std::endl;
    std::cout << "    y = ";
    cur.print();
    std::cout << std::endl;
    
    if(!isFO){
        double dev = cur.getComponent(0);
        dev -= sol;
        std::cout << std::endl << "Abweichung bei Euler bei " << numSteps << " Schritten: " << dev << std::endl << std::endl;
    }
}

void CDGLSolver::heun(double start, CMyVector y, double end, int numSteps, double sol){
    double h = (end-start)/numSteps;
    CMyVector cur = y, curStroke = CMyVector(), test = CMyVector(), testStroke = CMyVector(), middle = CMyVector();
    double x = start, x_test = x;
    
    std::cout << "Schritt 0:" << std::endl;
    std::cout << "    x = " << x << std::endl;
    std::cout << "    y = ";
    cur.print();
    
    std::cout << "    y' = ";
    curStroke = ableitungen(cur, x);
    curStroke.print();
    
    std::cout << std::endl;
    std::cout << "    test = ";
    test = cur + h * curStroke;
    test.print();
    
    std::cout << "    test' = ";
    x_test += h;
    testStroke = ableitungen(test, x_test);
    testStroke.print();
    
    std::cout << std::endl;
    std::cout << "    mittel = ";
    middle = 0.5*(curStroke+testStroke);
    middle.print();
    
    for(int i=1; i<numSteps; i++){
        x += h;
        x_test = x;
        
        std::cout << "Schritt " << i << ":" << std::endl;
        std::cout << "    x = " << x << std::endl;
        std::cout << "    y = ";
        cur = cur + h * middle;
        cur.print();
        
        std::cout << "    y' = ";
        curStroke = ableitungen(cur, x);
        curStroke.print();
        
        std::cout << std::endl;
        std::cout << "    test = ";
        test = cur + h * curStroke;
        test.print();
        
        std::cout << "    test' = ";
        x_test += h;
        testStroke = ableitungen(test, x_test);
        testStroke.print();
        
        std::cout << std::endl;
        std::cout << "    mittel = ";
        middle = 0.5*(curStroke+testStroke);
        middle.print();
    }
    std::cout << "Ende bei:" << std::endl;
    x += h;
    std::cout << "    x = " << x << std::endl;
    std::cout << "    y = ";
    cur = cur + h * middle;
    cur.print();
    std::cout << std::endl;
    if(!isFO){
        double dev = cur.getComponent(0);
        dev -= sol;
        std::cout << std::endl << "Abweichung bei Euler bei " << numSteps << " Schritten: " << dev << std::endl << std::endl;
    }
}
