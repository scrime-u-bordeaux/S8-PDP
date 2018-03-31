#include "../utilities.hpp"

#include <cstdlib>
#include <cmath>

using namespace std;

extern "C"{

float CoeffRandom(const vector<float>& s1, const vector<float>& s2){
  float coeff;
  coeff = rand() / RAND_MAX;
  coeff += std::abs(s1[0]-s2[0]);
  return coeff;
}

}
