#pragma once
#include <iostream>
#include <vector>
#include <time.h>
#include <string.h>
#include "CRandom.hpp"
#include "CLotto.hpp"

void testFunctionality();

void monteCarlo(int N, int according, std::string cmpWith, CLotto lotto);
