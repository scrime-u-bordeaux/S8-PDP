/**
 *  \file    PreprocEnergy.cpp
 *  \author  Jérémy LIXANDRE
 *  \date    July 2017
 *
 *  \brief Code containing the preprocessing based on energy function.
 *
 *  This is a preprocessing function returning a Matrix which has in every line
 *  the energy envelope of each instrument of the original Matrix of signals
 *  given in parameter.
 *
 */

#include "PreprocEnergy.hpp"

/**
 *  Cuts f1 in blocks of length 'frame' and applies norm to get the energy of
 *  the signal
 */
vector<float> energyenvelope(const vector<float>& f1, int frame){
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
		buffer.setRow(i, energyenvelope(input.getRow(i), 64));
	}
	return buffer;
}

}
