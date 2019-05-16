#pragma once
#include <time.h>
#include <vector>
#include <math.h>
#include <time.h>
#include "CRandom.hpp"

class CLotto{
private:
    std::vector<int> bettingSlip;
    CRandom random;
public:
    CLotto(int n);
    void setBettingSlip(std::vector<int> bill){bettingSlip = bill;}
    std::vector<int> simulate();
    int cmpWithBettingSlip();
    int cmpTwoGames();
};
