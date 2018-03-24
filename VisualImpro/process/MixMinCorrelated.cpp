// Generate a sound volume mix on each instrument depending on the least
// correlated instruments

#include "../utilities.hpp"
#include "../SquareMatrix.hpp"
#include <vector>

using namespace std;

extern "C" {

// return a vector whose elements are the mean correlations of every instruments
// but it is processed as "1 - mean" to have the complementary coefficient
// between 0 and 1
vector<float> MixMinCorrelated(const SquareMatrix<float>& correlMatrix) {

  int size = correlMatrix.getSize();

  // initialize the result vector with zeros
  vector<float> meanCorrelations(size , 0.0f);

  // fill the vector with the mean correlation of each instrument with others
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i != j)
        meanCorrelations[i] += correlMatrix.getCase(i, j);
    }
    meanCorrelations[i] /= size;

    // complementary coefficient between 0 and 1
    meanCorrelations[i] = 1 - meanCorrelations[i];
  }
  return meanCorrelations;
}
}
