#include "CRandom.hpp"

int CRandom::value(int a, int b){
    int res = b - a + 1;
    res = rand()%res;
    res += a;
    return res;
}

void CRandom::init(int n){
    srand(n);
}

std::vector<int> CRandom::test(int a, int b, int N){
    int limit = b - a + 1, tmp = 0;
    std::vector<int> res;
    res.resize(limit);
    for(int i=0; i<limit; i++){
        res[i] = 0;
    }
    for(int i=0; i<N; i++){
        tmp = value(a, b);
        ++res[tmp-a];
    }
    return res;
}

std::vector<int> CRandom::test_wrong(int a, int b, int N){
    int limit = b - a + 1, tmp = 0;
    std::vector<int> res;
    res.resize(limit);
    for(int i=0; i<limit; i++){
        res[i] = 0;
    }
    for(int i=0; i<N; i++){
        init(time(NULL));
        tmp = value(a, b);
        ++res[tmp-a];
    }
    return res;
}
