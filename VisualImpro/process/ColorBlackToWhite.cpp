/***** process/ColorBlackToWhite.cpp *****/

#include "../utilities.hpp"

extern "C"{
	
Triplet ColorBlackToWhite(float coeff){
	int val = (int) 255*coeff;
	Triplet rgb(val,val,val);
	return rgb;
}
	
}