/**
 *  @file    MixMaxCorrelated.cpp
 *  @author  Alexandre Casanova--Franger
 *  @date    04/03/2018
 *
 *  @section DESCRIPTION
 *
 *  This function is used to process the mean correlation
 *  of each instrument. We will use it to mix the volume of each instrument
 *  depending on the correlation it has with others instruments.
 *  Here the least correlated instruments are played louder.
 *
 */

#include "../utilities.hpp"

extern "C" {

// return a vector whose elements are the mean correlations of every instruments
// but it is processed as "1 - mean" to have the complementary coefficient
// between 0 and 1
vector<float> MixMinCorrelated(const Matrix<float>& correlMatrix) {

  int row = correlMatrix.getSize();
  int col = correlMatrix.getRow(0).size();

  // initialize the result vector with zeros
  vector<float> meanCorrelations(row, 0.0f);

  // fill the vector with the mean correlation of each instrument with others
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (i != j){
      	// complementary coefficient between 0 and 1
        meanCorrelations[i] += 1.0f - correlMatrix.getCase(i, j);
      }
    }
    meanCorrelations[i] /= (float)row-1;
  }
  return meanCorrelations;
}

}
