// Generate a sound volume mix on each instrument depending on the most
// correlated instruments

#include "../utilities.hpp"

using namespace std;

extern "C" {

// return a vector whose elements are the mean correlations of every instruments
vector<float> MixMaxCorrelated(const Matrix<float>& correlMatrix) {

  int row = correlMatrix.getSize();
  int col = correlMatrix.getRow(0).size();

  // initialize the result vector with zeros
  vector<float> meanCorrelations(row, 0.0f);

  // fill the vector with the mean correlation of each instrument with others
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (i != j)
        meanCorrelations[i] += correlMatrix.getCase(i, j);
    }
    meanCorrelations[i] /= (float)row-1;
  }

  return meanCorrelations;
}
}
