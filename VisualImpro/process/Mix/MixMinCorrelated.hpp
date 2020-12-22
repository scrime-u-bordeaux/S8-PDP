#ifndef MIXMINCORRELATED_HPP
#define MIXMINCORRELATED_HPP

#include <vector>

#include "../../Matrix.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \fn     vector<float> MixMinCorrelated(const Matrix<float>& correlMatrix)
 * \brief  The minimal correlation based function
 *
 * \param  correlMatrix The correlation matrix of signals
 * \return A vector composed of values of 1.0 minus the mean correlations of
 *         every instrument.
 *
 * Return a vector whose elements are the mean correlations of every instruments
 * but it is processed as "1 - mean" to have the complementary coefficient
 * between 0 and 1.
 */
extern "C" vector<float> MixMinCorrelated(const Matrix<float>& correlMatrix);

#endif // MIXMINCORRELATED_HPP
