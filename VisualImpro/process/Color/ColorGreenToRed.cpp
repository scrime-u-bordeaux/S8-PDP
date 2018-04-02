/**
 *  @file    ColorGreenToRed.cpp
 *  @author  Jérémy LIXANDRE
 *  @date    July 2017
 *
 *  @section DESCRIPTION
 *
 *  This color function is used to compute, from a float representing the
 *  correlation between two instruments, the RGB triplet corresponding to that
 *  value. The returned value will tend to be an RGB triplet representing red
 *	if the correlation is minimal or an RGB triplet representing green if the
 *	correlation is maximal.
 *
 */

#include "ColorGreenToRed.hpp"

extern "C"{

RGB ColorGreenToRed(float coeff){
  RGB color(0,0,0);
  if (coeff < 0.0000001){
    return color;
  }
  else if (coeff < 0.5){
    color.setRed(250);
    color.setGreen(((int) (235* (coeff * 2))) + 20);
  }
  else{
    color.setRed(((int) 235*(1-coeff)*2) + 20);
    color.setGreen(250);
  }
  color.setBlue(20);
  return color;
}

}
