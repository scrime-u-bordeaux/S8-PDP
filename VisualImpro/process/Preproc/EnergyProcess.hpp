#ifndef ENERGYPROCESS_HPP
#define ENERGYPROCESS_HPP

#include <math.h>
#include <vector>

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \fn     inline float energy(const vector <float>& f1, int start, int end)
 * \brief  The energy process function
 *
 * \param  f1 The vector to process
 * \param  start The starting coordonate of the vector for processing
 * \param  end The ending coordonate of the vector for processing
 * \return A float corresponding to the mean of all the vector's squared values.
 */
inline float energy(const vector <float>& f1, int start, int end){
  float en = 0.0;
  for (int i = start; i < end; i++){
    en+=pow(f1[i],2);
  }
  return en/(end-start);
}

#endif // ENERGYPROCESS_HPP
