#ifndef MIXNEUTRAL_HPP
#define MIXNEUTRAL_HPP

#include <vector>

using namespace std;

extern "C" vector<float> MixNeutral(const Matrix<float>& correlMatrix);

#endif // MIXNEUTRAL_HPP
