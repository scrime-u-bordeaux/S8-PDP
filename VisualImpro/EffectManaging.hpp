/***** EffectManaging.hpp *****/

#ifndef EFFECTMANAGING_HPP
#define EFFECTMANAGING_HPP

#include "SquareMatrix.hpp"
#include "utilities.hpp"
#include <assert.h>
#include <vector>

typedef void (*effectprocess) (SquareMatrix<float>&, SquareMatrix<float>&);

void genEffect(SquareMatrix<float>& In, int indIn, SquareMatrix<float>& Out, int indOut, int size, int globsize, effectprocess effect){
	assert(In.size() == Out.size());
	SquareMatrix<float> tmpIn(In.size(), std::vector <float> (size, 0.0));
	SquareMatrix<float> tmpOut(In.size(), std::vector <float> (size, 0.0));
	for (int i = 0 ; i < size; i++){
		for (int j = 0 ; j < In.size(); j++){
			tmpIn.setCase(j, i, In.getCase(j, (indIn + i)%globsize));
		}
	}
	effect(tmpIn, tmpOut);

	for (int i = 0 ; i < size; i++){
		for (int j = 0 ; j < In.size(); j++){
			Out.setCase(j, (indOut + i)%globsize, tmpOut.getCase(j, i));
		}
	}
}


#endif //EFFECTMANAGING_HPP
