#include "../utilities.hpp"

#include <cstdlib>
#include <cmath>

using namespace std;

extern "C"{

float CoeffRandom(const vector<float>& s1, const vector<float>& s2){
  float coeff;
  coeff = 0.15f + static_cast <float> (rand()) / static_cast <float> (RAND_MAX/0.85f);
  coeff += std::abs(s1[0]-s2[0]);
  return coeff;
}

}
