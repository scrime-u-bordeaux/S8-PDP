/**
 *  @file    CoeffRandom.cpp
 *  @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date    March 2018
 *
 *  @section DESCRIPTION
 *
 *  This is a correlation function used to return a random correlation value.
 *  The volume and the coloration matrix will be affected by this value.
 *
 */

#include "CoeffRandom.hpp"

#include <cstdlib>
#include <cmath>

extern "C"{

float CoeffRandom(const vector<float>& s1, const vector<float>& s2){
  float coeff;
  coeff = rand() / RAND_MAX;
  coeff += std::abs(s1[0]-s2[0]);
  return coeff;
}

}
