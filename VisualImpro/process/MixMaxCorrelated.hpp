#ifndef MIXMAXCORRELATED_HPP
#define MIXMAXCORRELATED_HPP

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

extern "C" vector<float> MixMaxCorrelated(const SquareMatrix<float>& correlMatrix);

#endif // MIXMAXCORRELATED_HPP
