#ifndef COLORBLACKTOWHITE_HPP
#define COLORBLACKTOWHITE_HPP

#include "../../RGB.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \fn     RGB ColorBlackToWhite(float coeff)
 * \brief  The black to white coloration function
 *
 * \param  coeff A float coefficient corresponding to a correlation which has
 *               a value ranged between 0 and 1.
 * \return An RGB triplet corresponding to that coefficient. It tends to be more
 *         white if coeff is high or black if coeff is low.
 */
extern "C" RGB ColorBlackToWhite(float coeff);

#endif // COLORBLACKTOWHITE_HPP
