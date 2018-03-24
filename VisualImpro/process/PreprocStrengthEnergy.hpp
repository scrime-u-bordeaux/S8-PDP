#ifndef PREPROCSTRENGTHENERGY_HPP
#define PREPROCSTRENGTHENERGY_HPP

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

vector<float> strengthenergyenvelope(const vector<float>& f1, int frame);
extern "C" SquareMatrix<float> PreprocStrengthEnergy(const SquareMatrix<float>& input);

#endif // PREPROCSTRENGTHENERGY_HPP
