#ifndef MIXRANDOMVALUES_HPP
#define MIXRANDOMVALUES_HPP

#include <vector>

using namespace std;

extern "C" vector<float> MixRandomValues(const Matrix<float>& correlMatrix);

#endif // MIXRANDOMVALUES_HPP
