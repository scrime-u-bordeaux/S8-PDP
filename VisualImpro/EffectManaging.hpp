/**
 *  @file    EffectManaging.hpp
 *  @author  Jérémy LIXANDRE
 *  @date    July 2017
 *
 *  @section DESCRIPTION
 *
 *  EffectManaging only contais the method genEffect, used in render.cpp, and
 *	takes as parameter a buffer in (pre effect) and a buffer out (post effect),
 *	their indicies, sizes, and an effect function. The used of the genEffect
 *	function stand for generate the effect given through the function effect
 *	given in parameter on the buffer In and the result will be contained in the
 *	Out buffer.
 *
 */

#ifndef EFFECTMANAGING_HPP
#define EFFECTMANAGING_HPP

#include "Matrix.hpp"
#include <assert.h>
#include <vector>

using namespace std;

typedef void (*effectprocess) (Matrix<float>&, Matrix<float>&);

void genEffect(Matrix<float>& In, int indIn, Matrix<float>& Out, int indOut,
							 int size, int globsize, effectprocess effect){
	assert(In.getsize() == Out.getSize());
	Matrix<float> tmpIn(In.getSize(), vector <float> (size, 0.0));
	Matrix<float> tmpOut(In.getSize(), vector <float> (size, 0.0));
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
