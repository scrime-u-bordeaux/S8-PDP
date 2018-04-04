#ifndef MIXMAXCORRELATED_HPP
#define MIXMAXCORRELATED_HPP

#include <vector>

#include "../../Matrix.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \fn     vector<float> MixMaxCorrelated(const Matrix<float>& correlMatrix)
 * \brief  The maximal correlation based function
 *
 * \param  correlMatrix The correlation matrix of signals
 * \return A vector composed of values of the mean correlations of every
 *         instrument.
 */
extern "C" vector<float> MixMaxCorrelated(const Matrix<float>& correlMatrix);

#endif // MIXMAXCORRELATED_HPP
