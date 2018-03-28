#ifndef PREPROCENERGY_HPP
#define PREPROCENERGY_HPP

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

float energy(const vector <float>& f1, int start, int end);
vector<float> energyenvelope(const vector<float>& f1, int frame);
extern "C" SquareMatrix<float> PreprocEnergy(const SquareMatrix<float>& input);

#endif // PREPROCENERGY_HPP
