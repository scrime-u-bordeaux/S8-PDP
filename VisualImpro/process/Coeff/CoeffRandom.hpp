#ifndef COEFFRANDOM_HPP
#define COEFFRANDOM_HPP

#include <cmath>
#include <cstdlib>
#include <vector>

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \fn     float CoeffRandom(const vector<float>& s1, const vector<float>& s2)
 * \brief  The random correlation function
 *
 * \param  s1 The first vector to process
 * \param  s2 The second vector to process
 * \return A float corresponding to a random number ranged between 0 and 1.
 */
extern "C" float CoeffRandom(const vector<float>& s1, const vector<float>& s2);

#endif // COEFFRANDOM_HPP
