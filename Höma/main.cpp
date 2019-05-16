#include <iostream>
#include <vector>
#include "CLotto.hpp"
#include "A1.hpp"
#include "A2.hpp"
#include "A3.hpp"
#include "A4.hpp"
#include "A5.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    //Test
    //Aufgabe 1
    /*
    CMyVector vec = CMyVector(new double[2], 2);
    vec.setComponent(0, 3);
    vec.setComponent(1, 2);
    optimize(&f1, 'f', vec);
    
    vec = CMyVector(new double[3], 3);
    vec.setComponent(0, 0);
    vec.setComponent(1, 0);
    vec.setComponent(2, 0);
    optimize(&g1, 'g', vec, 0.1);
    */
    
    //Aufgabe 2
    /*
    CMyVector vec = CMyVector(new double[4], 4);
    vec.setComponent(0, 1);
    vec.setComponent(1, 2);
    vec.setComponent(2, 0);
    vec.setComponent(3, 3);
    CMyMatrix mat = jacobi(vec, &f2_1);
    cout << "Jacobimatrix aus Aufgabe 2: "<< endl << endl;
    mat.print();
    cout << endl << endl;
    vec = CMyVector(new double[2], 2);
    vec.setComponent(0, 1);
    vec.setComponent(1, 1);
    
    newton(&f2_2, vec);
    */
//    /*
    //Aufgabe 3
    CDGLSolver solver = CDGLSolver(&func1);
    CMyVector start = CMyVector(new double[2], 2);
    start.setComponent(0, 0);
    start.setComponent(1, 1);
    //solver.euler(0, start, 2, 100,.0);
    //solver.heun(0, start, 2, 100, .0);
    
    solver = CDGLSolver(&func2);
    start = CMyVector(new double[3], 3);
    start.setComponent(0, 1);
    start.setComponent(1, -1);
    start.setComponent(2, 2);
    solver.euler(1, start, 2, 100, 0.5);
    //solver.heun(1, start, 2, 10, 0.5);
//    */
    //Aufgabe 4
    /*
    vector<CComplex> input = werte_einlesen("input.txt");
    vector<CComplex> output = transformation(input, true);
    werte_ausgeben("hin_e_-1_0.txt", output);
    input = werte_einlesen("hin_e_-1_0.txt");
    output = transformation(input, false);
    werte_ausgeben("rück_e_-1_0.txt", output);
    input = werte_einlesen("input.txt");
    deviation(input, output, -1.);
    
    input = werte_einlesen("input.txt");
    output = transformation(input, true);
    werte_ausgeben("hin_e_0_1.txt", output, 0.1);
    input = werte_einlesen("hin_e_0_1.txt");
    output = transformation(input, false);
    werte_ausgeben("rück_e_0_1.txt", output);
    input = werte_einlesen("input.txt");
    deviation(input, output, .1);
    
    input = werte_einlesen("input.txt");
    output = transformation(input, true);
    werte_ausgeben("hin_e_1_0.txt", output, 1.);
    input = werte_einlesen("hin_e_1_0.txt");
    output = transformation(input, false);
    werte_ausgeben("rück_e_1_0.txt", output);
    input = werte_einlesen("input.txt");
    deviation(input, output, 1.);
    */
    //Aufgabe 5
    /*
    CLotto tmp = CLotto(0);
    vector<int> bill;
    bill.resize(6);
    bill[0] = 12;
    bill[1] = 21;
    bill[2] = 49;
    bill[3] = 1;
    bill[4] = 37;
    bill[5] = 15;
    tmp.setBettingSlip(bill);
    testFunctionality();
    monteCarlo(1000000, 3, "bill", tmp);
   */
    return 0;
}
