#ifndef MIXMINCORRELATED_HPP
#define MIXMINCORRELATED_HPP

#include <vector>

#include "../../Matrix.hpp"

using namespace std;

extern "C" vector<float> MixMinCorrelated(const Matrix<float>& correlMatrix);

#endif // MIXMINCORRELATED_HPP
