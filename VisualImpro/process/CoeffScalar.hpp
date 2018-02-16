#ifndef COEFFSCALAR_HPP
#define COEFFSCALAR_HPP

#include "CoeffScalar.hpp"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

float correlatescalar(vector<float> s1, vector<float> s2);
extern "C" float CoeffScalar(vector<float> s1, vector<float> s2);

#endif // COEFFSCALAR_HPP
