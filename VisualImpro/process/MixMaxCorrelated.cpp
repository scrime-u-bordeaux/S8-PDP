// Generate a sound volume mix on each instrument depending on the most
// correlated instruments

#include "../utilities.hpp"
#include <vector>

using namespace std;

extern "C" {

// return a vector whose elements are the mean correlations of every instruments
vector<float> MixMaxCorrelated(const vector<vector<float> >& correlMatrix) {

  // initialize the result vector with zeros
  vector<float> meanCorrelations(correlMatrix.size(), 0.0f);

  // fill the vector with the mean correlation of each instrument with others
  for (int i = 0; i < correlMatrix.size(); i++) {
    for (int j = 0; j < correlMatrix[i].size(); j++) {
      if (i != j)
        meanCorrelations[i] += correlMatrix[i][j];
    }
    meanCorrelations[i] /= correlMatrix.size();
  }

  return meanCorrelations;
}
}
