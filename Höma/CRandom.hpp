#pragma once
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <time.h>

class CRandom{
public:
    int value(int a, int b);
    void init(int n);
    std::vector<int> test(int a, int b, int N);
    std::vector<int> test_wrong(int a, int b, int N);
};
