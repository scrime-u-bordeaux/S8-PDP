/**
 *  @file    CoeffScalar.cpp
 *  @author  Jérémy LIXANDRE
 *  @date    July 2017
 *
 *  @section DESCRIPTION
 *
 *  This is a correlation function used to return a correlation value
 *  corresponding of the scalar product of the two buffers containing the
 *  signals of two differents instruments for one frame of data. The  volume
 *  and the coloration matrix will be affected by this value.
 *
 */


#include "CoeffScalar.hpp"

float correlatescalar(const vector<float>& s1, const vector<float>& s2){
  if (s1.size() != s2.size()){
    fprintf(stderr, "wrong sizes\n");
    exit(EXIT_FAILURE);
  }
  float corr = 0.0;
  for (unsigned int i = 0; i < s1.size(); i++){
    corr += s1[i]*s2[i];
  }
  return corr;
}

extern "C"{

float CoeffScalar(const vector<float>& s1, const vector<float>& s2){
	float scal = correlatescalar(s1,s2);
	float norm1 = correlatescalar(s1,s1);
	float norm2 = correlatescalar(s2,s2);
  float coeff;
  if (norm1 <= 0.000000001 ||  norm2 <= 0.000000001){ //both signal are null
  	coeff = 0.0;
  }else{
  	coeff = fabs(scal)/sqrt(norm1*norm2);
  }
  if (coeff > 1.000000){
	   coeff = 1.0;
  }
  return coeff;
}

}
