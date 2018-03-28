#include "../utilities.hpp"

extern "C"{

RGB ColorGreenToRed(float coeff) //given a coefficient, computes an RGB triplet, where 0.01 is red (0 is black) and 1 is green
{
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
