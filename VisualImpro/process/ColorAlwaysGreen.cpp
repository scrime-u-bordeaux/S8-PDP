/***** process/ColorAlwaysGreen.cpp *****/

#include "../utilities.hpp"
#include "../RGB.hpp"

extern "C"{

Triplet ColorAlwaysGreen(float coeff){
	RGB green(20,250,20);
	return green;
}

}
