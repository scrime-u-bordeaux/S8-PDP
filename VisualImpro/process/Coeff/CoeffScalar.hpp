#ifndef COEFFSCALAR_HPP
#define COEFFSCALAR_HPP

#include <cstdlib>
#include <vector>
#include <math.h>
#include <stdio.h>

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \fn     float correlatescalar(const vector<float>& s1,
 *                               const vector<float>& s2)
 * \brief  Process the scalar products of s1 and s2
 *
 * \param  s1 The first vector to process
 * \param  s2 The second vector to process
 * \return A float containing the sum of the index of s1 multiplied to
 *         the same index of s2 for every indices.
 */
float correlatescalar(const vector<float>& s1, const vector<float>& s2);

/**
 * \fn     float CoeffScalar(const vector<float>& s1, const vector<float>& s2)
 * \brief  The scalar correlation function
 *
 * \param  s1 The first vector to process
 * \param  s2 The second vector to process
 * \return A float corresponding to the correlation ranged between 0 and 1 of
 *         s1 and s2.
 */
extern "C" float CoeffScalar(const vector<float>& s1, const vector<float>& s2);

#endif // COEFFSCALAR_HPP
