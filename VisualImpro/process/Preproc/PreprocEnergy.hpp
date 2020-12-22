#ifndef PREPROCENERGY_HPP
#define PREPROCENERGY_HPP

#include <vector>

#include "EnergyProcess.hpp"
#include "../../Matrix.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \fn     vector<float> energyenvelope(const vector<float>& f1, int frame)
 * \brief  process a vector's energy envelope
 *
 * \param  f1 The vector to process
 * \param  frame The length of one frame to process
 * \return A vector corresponding to the energy envelope of f1.
 */
vector<float> energyenvelope(const vector<float>& f1, int frame);

/**
 * \fn     Matrix<float> PreprocEnergy(const Matrix<float>& input)
 * \brief  process a Matrix's energy envelope
 *
 * \param  input The matrix to process
 * \return A matrix corresponding to the energy envelope of input.
 */
extern "C" Matrix<float> PreprocEnergy(const Matrix<float>& input);

#endif // PREPROCENERGY_HPP
