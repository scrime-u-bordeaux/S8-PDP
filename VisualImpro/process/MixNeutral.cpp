/**
 *  @file    MixNeutral.cpp
 *  @author  Alexandre Casanova--Franger
 *  @date    04/03/2018
 *
 *  @section DESCRIPTION
 *
 *  This function generates a constant
 *  volume mix on each instrument while playing.
 *  This is the default mixing function.
 *
 */

#include "../utilities.hpp"
#include <vector>

using namespace std;

extern "C" {

// return a vector whose elements are the mean correlations of every instruments
vector<float> MixNeutral(vector<vector<float> > correlMatrix) {

  // initialize the result vector with ones, no process here
  vector<float> ones(correlMatrix.size(), 1.0f);
  return ones;
}
}
