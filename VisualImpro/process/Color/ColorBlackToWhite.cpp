/**
 *  @file    ColorGreenToRed.cpp
 *  @author  Jérémy LIXANDRE
 *  @date    04/03/2018
 *
 *  @section DESCRIPTION
 *
 *  This color function is used to compute, from a float representing the
 *  correlation between two instruments, the RGB triplet corresponding to that
 *  value. The returned value will tend to be an RGB triplet representing black
 *	if the correlation is minimal or an RGB triplet representing white if the
 *	correlation is maximal.
 *
 */

#include "ColorBlackToWhite.hpp"

extern "C"{

RGB ColorBlackToWhite(float coeff){
	 int val = (int) 255*coeff;
	RGB color(val,val,val);
	return color;
}

}
