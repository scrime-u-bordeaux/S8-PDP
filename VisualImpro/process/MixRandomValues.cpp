/**
 *  @file    MixMaxCorrelated.cpp
 *  @author  Alexandre Casanova--Franger
 *  @date    04/03/2018
 *
 *  @section DESCRIPTION
 *
 *  This function is used to process random values that
 *  we will use to mix the volume of each instrument.
 *  This function does not depend on the correlation it has
 *  with others instruments.
 *
 */

#include "../utilities.hpp"
#include <vector>
#include <cstdlib>

using namespace std;

extern "C"{

vector<float> MixRandomValues(vector<vector<float> > correlMatrix){

  // initialize the result vector with zeros
  vector<float> randomValues(correlMatrix.size(), 0.0f);

  // fill the vector with random values;
  for (int i = 0; i < correlMatrix.size(); i++) {
    randomValues[i] = rand() % 2;
  }

  return randomValues;
}

}
