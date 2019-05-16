#include "CLotto.hpp"

CLotto::CLotto(int n){
    random = CRandom();
    if(n==0) random.init(time(NULL));
    else random.init(n);
}

bool contains(std::vector<int> vec, int lim, int val){
    for(int i=0; i<lim; i++){
        if(vec[i] == val) return true;
    }
    return false;
}

std::vector<int> CLotto::simulate(){
    std::vector<int> res;
    res.resize(6);
    int cnt = 0, tmp;
    while(cnt<6){
        tmp = random.value(1, 49);
        if(!contains(res, cnt, tmp)){
            res[cnt] = tmp;
            cnt++;
        }
    }
    return res;
}

int CLotto::cmpWithBettingSlip(){
    int res = 0;
    std::vector<int> vec = simulate();
    for(int i=0; i<6; i++){
        if(contains(bettingSlip, 6, vec[i])) ++res;
    }
    return res;
}

int CLotto::cmpTwoGames(){
    int res = 0;
    std::vector<int> vec1 = simulate(), vec2 = simulate();
    for(int i=0; i<6; i++){
        if(contains(vec2, 6, vec1[i])) ++res;
    }
    return res;
}
