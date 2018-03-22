// Generate a constant sound volume mix, not depending on correlations

#include "../utilities.hpp"
#include <vector>

using namespace std;

extern "C" {

// return a vector whose elements are the mean correlations of every instruments
vector<float> MixNeutral(const vector<vector<float> >& correlMatrix) {

  // initialize the result vector with ones, no process here
  vector<float> ones(correlMatrix.size(), 1.0f);
  return ones;
}
}
