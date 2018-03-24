// Generate a random sound volume mix on each instrument while playing

#include "../utilities.hpp"
#include "../SquareMatrix.hpp"
#include <vector>
#include <cstdlib>

using namespace std;

extern "C"{

vector<float> MixRandomValues(const SquareMatrix<float>& correlMatrix){

  int size = correlMatrix.getSize();

  // initialize the result vector with zeros
  vector<float> randomValues(size, 0.0f);

  // fill the vector with random values;
  for (int i = 0; i < size; i++) {
    randomValues[i] = rand() % 2;
  }

  return randomValues;
}

}
