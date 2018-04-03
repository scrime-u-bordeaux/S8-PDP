#ifndef MIXNEUTRAL_HPP
#define MIXNEUTRAL_HPP

#include <vector>

#include "../../Matrix.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \fn     vector<float> MixNeutral(const Matrix<float>& correlMatrix)
 * \brief  The neutral mix function
 *
 * \param  correlMatrix The correlation matrix of signals
 * \return A vector composed of floats equals 1.0
 */
extern "C" vector<float> MixNeutral(const Matrix<float>& correlMatrix);

#endif // MIXNEUTRAL_HPP
