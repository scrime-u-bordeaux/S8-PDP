/**
 *  @file    RGB.cpp
 *  @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date    March 2018
 *
 *  @section DESCRIPTION
 *
 *  The RGB object is an int triplet and used for processing colors for the
 *  output matrix we obtain at the end of our processing function chain.
 *
 */

#include "RGB.hpp"
#include <sstream>
//#include <iomanip>

string hexa[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

RGB::RGB(int red, int green, int blue)
    : _red(red), _green(green), _blue(blue) {}


int RGB::getRed() const { return _red; }
int RGB::getGreen() const { return _green; }
int RGB::getBlue() const { return _blue; }

void RGB::setRed(int red) { _red = red; }
void RGB::setGreen(int green) { _green = green; }
void RGB::setBlue(int blue) { _blue = blue; }

string RGB::toString(){
  return ("#" + colortohexa(this->getRed()) + colortohexa(this->getGreen()) +
  colortohexa(this->getBlue()));
}

string RGB::colortohexa(int color){
  if ((color < 0) || (color > 255))
    return "00";
  else
    return (hexa[color/16] + hexa[color%16]);
}

/*string RGB::toString(){
stringstream stream;
stream << "#";
stream << hex << this->getRed();
stream << hex << this->getGreen();
stream << hex << this->getBlue();
return stream.str();
}*/

/*unsigned long RGB::createRGB(int r, int g, int b){
  return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}*/

RGB::~RGB() {}

ostream & operator<<(ostream &flux, const RGB& rgb) {
  flux << "#" << "(" << rgb.getRed() << ", " << rgb.getGreen() << ", " <<
  rgb.getBlue() << ")";
  return flux;
}
