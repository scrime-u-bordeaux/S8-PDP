#include "../utilities.hpp"

#include <math.h>

using namespace std;

float energy(const vector <float>& f1, int start, int end){
  float en = 0.0;
  for (int i = start; i < end; i++){
    en+=pow(f1[i],2);
  }
  return en/(end-start);
}

vector<float> energyenvelope(const vector<float>& f1, int frame){ //cuts f1 in blocks of length 'frame' and applies norm to get the energy of the signal
  int size = f1.size();
  int nbframes = 0;
  if(size%frame == 0)
  	{
  	nbframes = size/frame;
 	}
  else
  {
	nbframes = size/frame + 1;
  }
  vector<float> energ(nbframes, 0.0);
  for (int i = 0; i < nbframes; i++){
    energ[i] = energy(f1, i*frame, min(i*frame + frame, size));
  }
  return energ;
}

extern "C"{

Matrix<float> PreprocEnergy(const Matrix<float>& input){
  int size = input.getSize();
	Matrix<float> buffer(size);
	for (int i = 0 ; i < size; i++){
		buffer.setRow(i, energyenvelope(input.getRow(i), 1024));
	}
	return buffer;
}

}
