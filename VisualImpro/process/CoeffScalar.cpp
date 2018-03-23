#include "../utilities.hpp"


#include <assert.h>
#include <math.h>
#include <stdio.h>

using namespace std;

float correlatescalar(const vector<float>& s1, const vector<float>& s2){
  if (s1.size() == s2.size()){
    float corr = 0.0;
    for (unsigned int i = 0; i < s1.size(); i++){
      corr += s1[i]*s2[i];
    }
    return corr;
  }
  printf("wrong sizes");
  return 0;
}

// (x|y) < sqrt((x|x)(y|y))

extern "C"{

float CoeffScalar(const vector<float>& s1, const vector<float>& s2){
	float scal = correlatescalar(s1,s2);
	float norm1 = correlatescalar(s1,s1);
	float norm2 = correlatescalar(s2,s2);
float coeff;
  if (norm1 <= 0.000000001 ||  norm2 <= 0.000000001){ //both signal are null
  	coeff = 0.0;
  }
  else
  {
  	coeff = fabs(scal)/sqrt(norm1*norm2);
  }
  if (coeff > 1.000000){
	coeff = 1.0;
  }
  return coeff;
}

}
