/**
 *  \file    PreprocDefault.cpp
 *  \author  Jérémy LIXANDRE
 *  \date    July 2017
 *
 *  \brief Code containing the default preprocessing function.
 *
 *  This is a preprocessing function returning the default signals given as
 *	parameter. As no preprocessing is applied here, we consider this is the
 *	function we can use when we de not want to preprocess the signals.
 *
 */

#include "PreprocDefault.hpp"

extern "C"{

Matrix<float> PreprocDefault(const Matrix<float>& input){

	return input;

}

}
