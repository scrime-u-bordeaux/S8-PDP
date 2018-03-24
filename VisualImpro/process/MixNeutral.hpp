#ifndef MIXNEUTRAL_HPP
#define MIXNEUTRAL_HPP

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

extern "C" vector<float> MixNeutral(const SquareMatrix<float>& correlMatrix);

#endif // MIXNEUTRAL_HPP
