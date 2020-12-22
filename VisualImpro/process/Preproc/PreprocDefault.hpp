#ifndef PREPROCDEFAULT_HPP
#define PREPROCDEFAULT_HPP

#include <vector>

#include "../../Matrix.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \fn     Matrix<float> PreprocDefault(const Matrix<float>& input)
 * \brief  Applies no preprocessing to the input buffer
 *
 * \param  input The matrix to "process"
 * \return A matrix corresponding to the exact same matrix as input.
 */
extern "C" Matrix<float> PreprocDefault(const Matrix<float>& input);

#endif // PREPROCDEFAULT_HPP
