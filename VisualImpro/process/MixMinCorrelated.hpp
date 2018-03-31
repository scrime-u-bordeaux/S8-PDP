#ifndef MIXMINCORRELATED_HPP
#define MIXMINCORRELATED_HPP

#include <vector>

using namespace std;

extern "C" vector<float> MixMinCorrelated(const Matrix<float>& correlMatrix);

#endif // MIXMINCORRELATED_HPP
