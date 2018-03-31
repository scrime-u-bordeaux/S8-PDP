#ifndef MIXMAXCORRELATED_HPP
#define MIXMAXCORRELATED_HPP

#include <vector>

#include "../../Matrix.hpp"

using namespace std;

extern "C" vector<float> MixMaxCorrelated(const Matrix<float>& correlMatrix);

#endif // MIXMAXCORRELATED_HPP
