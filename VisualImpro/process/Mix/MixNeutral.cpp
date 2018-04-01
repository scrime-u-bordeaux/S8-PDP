/**
 *  @file    MixNeutral.cpp
 *  @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date    04/03/2018
 *
 *  @section DESCRIPTION
 *
 *  This function is used for returning a neutral mix on each instrument. We can
 *  use this function if we don't want any changes of the mix volume during the
 *  process.
 *
 */

#include "MixNeutral.hpp"

extern "C" {

// Returns a vector whose elements are the mean correlations of every instruments
vector<float> MixNeutral(const Matrix<float>& correlMatrix) {

  // Initialize the result vector with ones, no process here
  vector<float> ones(correlMatrix.getSize(), 1.0f);
  return ones;
}
}
