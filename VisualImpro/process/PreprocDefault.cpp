/***** process/PreprocDefault.cpp *****/

#include "../utilities.hpp"
#include "../SquareMatrix.hpp"

extern "C"{

SquareMatrix<float> PreprocDefault(const SquareMatrix<float>& input){

	return input;

}

}
