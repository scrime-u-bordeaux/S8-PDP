/***** EffectManaging.hpp *****/

#ifndef EFFECTMANAGING_HPP
#define EFFECTMANAGING_HPP

#include "Matrix.hpp"
#include <assert.h>
#include <vector>

typedef void (*effectprocess) (Matrix<float>&, Matrix<float>&);

void genEffect(Matrix<float>& In, int indIn, Matrix<float>& Out, int indOut, int size, int globsize, effectprocess effect){
	assert(In.getsize() == Out.getSize());
	Matrix<float> tmpIn(In.getSize(), std::vector <float> (size, 0.0));
	Matrix<float> tmpOut(In.getSize(), std::vector <float> (size, 0.0));
	for (int i = 0 ; i < size; i++){
		for (int j = 0 ; j < In.getSize(); j++){
			tmpIn.setCase(j, i, In.getCase(j, (indIn + i)%globsize));
		}
	}
	effect(tmpIn, tmpOut);

	for (int i = 0 ; i < size; i++){
		for (int j = 0 ; j < In.getSize(); j++){
			Out.setCase(j, (indOut + i)%globsize, tmpOut.getCase(j, i));
		}
	}
}


#endif //EFFECTMANAGING_HPP
