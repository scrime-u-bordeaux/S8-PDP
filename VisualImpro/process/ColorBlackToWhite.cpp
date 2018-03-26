/***** process/ColorBlackToWhite.cpp *****/

#include "../utilities.hpp"

extern "C"{

RGB ColorBlackToWhite(float coeff){
	 int val = (int) 255*coeff;
	RGB color(val,val,val);
	return color;
}

}
