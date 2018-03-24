#ifndef MIXRANDOMVALUES_HPP
#define MIXRANDOMVALUES_HPP

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

extern "C" vector<float> MixRandomValues(const SquareMatrix<float>& correlMatrix);

#endif // MIXRANDOMVALUES_HPP
