#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "CComplex.hpp"

std::vector<CComplex> werte_einlesen(const char *dateiname);

void werte_ausgeben(const char *dateiname, std::vector<CComplex> werte, double epsilon = -1.);

std::vector<CComplex> transformation(std::vector<CComplex> values, bool enable);

void deviation(std::vector<CComplex> a, std::vector<CComplex> b, double epsilon);
