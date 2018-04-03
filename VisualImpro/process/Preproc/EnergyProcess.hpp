#ifndef ENERGYPROCESS_HPP
#define ENERGYPROCESS_HPP

#include <math.h>
#include <vector>

using namespace std;

inline float energy(const vector <float>& f1, int start, int end){
  float en = 0.0;
  for (int i = start; i < end; i++){
    en+=pow(f1[i],2);
  }
  return en/(end-start);
}

#endif // ENERGYPROCESS_HPP
