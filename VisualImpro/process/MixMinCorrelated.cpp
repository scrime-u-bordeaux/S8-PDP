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

extern "C"{

/* float MixMinCorrelated(float correlValue){
vector<float> MixMinCorrelated(vector<vector<float> > correlMatrix) {

  int size = correlMatrix.getSize();

	return 1-(1*correlValue);
  vector<float> meanCorrelations(correlMatrix.size(), 0.0f);

} */
  for (int i = 0; i < correlMatrix.size(); i++) {
    for (int j = 0; j < correlMatrix[i].size(); j++) {

        meanCorrelations[i] += correlMatrix[i][j];
    // complementary coefficient between 0 and 1
    meanCorrelations[i] = 1 - meanCorrelations[i];
    }
    meanCorrelations[i] /= size;
}

}
