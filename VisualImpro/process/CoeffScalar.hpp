#ifndef COEFFSCALAR_HPP
#define COEFFSCALAR_HPP

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

float correlatescalar(const vector<float>& s1, const vector<float>& s2);
extern "C" float CoeffScalar(const vector<float>& s1, const vector<float>& s2);

#endif // COEFFSCALAR_HPP
