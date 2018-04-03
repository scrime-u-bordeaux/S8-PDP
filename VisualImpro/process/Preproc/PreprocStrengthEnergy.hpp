#ifndef PREPROCSTRENGTHENERGY_HPP
#define PREPROCSTRENGTHENERGY_HPP

#include <vector>

#include "EnergyProcess.hpp"
#include "../../Matrix.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \fn     vector<float> strengthenergyenvelope(const vector<float>& f1,
 *                                              int frame)
 * \brief  process a vector's strength energy envelope
 *
 * \param  f1 The vector to process
 * \param  frame The length of one frame to process
 * \return A vector corresponding to the strength energy envelope of f1.
 */
vector<float> strengthenergyenvelope(const vector<float>& f1, int frame);

/**
 * \fn     Matrix<float> PreprocStrengthEnergy(const Matrix<float>& input)
 * \brief  process a Matrix's strength energy envelope
 *
 * \param  input The matrix to process
 * \return A matrix corresponding to the strength energy envelope of input.
 */
extern "C" Matrix<float> PreprocStrengthEnergy(const Matrix<float>& input);

#endif // PREPROCSTRENGTHENERGY_HPP
