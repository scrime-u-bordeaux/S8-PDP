#ifndef COLORGREENTORED_HPP
#define COLORGREENTORED_HPP

#include "../../RGB.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \fn     RGB ColorGreenToRed(float coeff)
 * \brief  The green to red coloration function
 *
 * \param  coeff A float coefficient corresponding to a correlation which has
 *               a value ranged between 0 and 1.
 * \return An RGB triplet corresponding to that coefficient. It tends to be more
 *         green if coeff is high or red if coeff is low.
 */
extern "C" RGB ColorGreenToRed(float coeff);

#endif // COLORGREENTORED_HPP
