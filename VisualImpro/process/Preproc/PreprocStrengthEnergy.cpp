/**
 *  @file    PreprocStrengthEnergy.cpp
 *  @author  Jérémy LIXANDRE
 *  @date    July 2017
 *
 *  @section DESCRIPTION
 *
 *  This is a preprocessing function returning a Matrix witch has in every line
 *  the strength energy envelope of each instrument of the original Matrix of
 *  signals given in parameter. It is almost the same as the energy enevelope
 *  process except that this functions returns, for each instrument, the
 *  difference of the energy process between two consecutives frames, or zero
 *  if the difference is negative.
 *
 */

#include "PreprocStrengthEnergy.hpp"

using namespace std;

/* Cuts f1 in blocks of length 'frame' and applies norm to get the energy of the
 *signal
 */
vector<float> strengthenergyenvelope(const vector<float>& f1, int frame){
  int size = f1.size();
  int nbframes = 0;
  if(size%frame == 0)
  	{
  	nbframes = size/frame;
 	}else{
	   nbframes = size/frame + 1;
  }
  vector<float> energ(nbframes, 0.0f);
  float previous = 0;
  float current = 0;
  for (int i = 0; i < nbframes; i++){
	   current = energy(f1, i*frame, min(i*frame + frame, size));
     energ[i] = max(0.0f, current-previous);
     previous = current;
  }
  return energ;
}

extern "C"{

Matrix<float> PreprocStrengthEnergy(const Matrix<float>& input){
  int size = input.getSize();
	Matrix<float> buffer(size, vector<float>(input.getRow(0).size(), 0.0f));
	for (int i=0 ; i<size; i++){
		buffer.setRow(i, strengthenergyenvelope(input.getRow(i), 1024));
	}
	return buffer;
}

}
