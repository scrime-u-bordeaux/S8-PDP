#ifndef MIXMINCORRELATED_HPP
#define MIXMINCORRELATED_HPP

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

extern "C" vector<float> MixMinCorrelated(const SquareMatrix<float>& correlMatrix);

#endif // MIXMINCORRELATED_HPP
