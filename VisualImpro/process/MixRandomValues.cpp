// Generate a random sound volume mix on each instrument while playing

#include "../utilities.hpp"
#include <vector>
#include <cstdlib>

using namespace std;

extern "C"{

vector<float> MixRandomValues(const vector<vector<float> >& correlMatrix){

  // initialize the result vector with zeros
  vector<float> randomValues(correlMatrix.size(), 0.0f);

  // fill the vector with random values;
  for (int i = 0; i < correlMatrix.size(); i++) {
    randomValues[i] = rand() % 2;
  }

  return randomValues;
}

}
