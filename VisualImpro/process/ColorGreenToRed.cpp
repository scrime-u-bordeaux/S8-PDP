#include "../utilities.hpp"

extern "C"{

Triplet ColorGreenToRed(float coeff) //given a coefficient, computes an RGB triplet, where 0.01 is red (0 is black) and 1 is green 
{
  Triplet rgb(0,0,0);
  if (coeff < 0.0000001){
    return rgb;
  }
  else if (coeff < 0.5){
    rgb.one = 250; //red
    rgb.two = ((int) (235* (coeff * 2))) + 20; //green
  }
  else{
    rgb.one = ((int) 235*(1-coeff)*2) + 20; //red
    rgb.two = 250; //green
  }
  rgb.three = 20; //blue
  return rgb;
}

}