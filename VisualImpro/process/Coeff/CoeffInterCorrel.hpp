#ifndef COEFFINTERCORREL_HPP
#define COEFFINTERCORREL_HPP

#include <cstdlib>
#include <vector>
#include <math.h>
#include <stdio.h>

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

extern "C" vector<float> CoeffInterCorrel(const vector<float>& s1, const vector<float>& s2);
#endif
