/**
 *  \file    RGB.cpp
 *  \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date    March 2018
 *
 *  @section DESCRIPTION
 *
 *  The RGB object is an int triplet and used for processing colors for the
 *  output matrix we obtain at the end of our processing function chain.
 *
 */

//#include <iomanip>
#include <sstream>
#include "RGB.hpp"

// Every possible hexadecimal values
string hexa[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

//Constructor for our RGB triplet
RGB::RGB(int red, int green, int blue)
    : _red(red), _green(green), _blue(blue) {}

RGB::RGB(string hexaCode){
  int start = 1;
  _red = std::stoi(hexaCode.substr(start, 2), nullptr, 16);
  _green = std::stoi(hexaCode.substr(start + 2, 2), nullptr, 16);
  _blue = std::stoi(hexaCode.substr(start + 4, 2), nullptr, 16);
}

// Getters and setters for each component of the RGB triplet
int RGB::getRed() const { return _red; }
int RGB::getGreen() const { return _green; }
int RGB::getBlue() const { return _blue; }

void RGB::setRed(int red) { _red = red; }
void RGB::setGreen(int green) { _green = green; }
void RGB::setBlue(int blue) { _blue = blue; }

// Returns the color RGB triplet to a string corresponding to its RGB values
// string RGB::to_String(RGB color){
//   return ("#" + colortohexa(color.getRed()) + colortohexa(color.getGreen()) +
//   colortohexa(color.getBlue()));
// }

// Transforms an int into an hexadecimal value
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

// Operator overloading to print the RGB matrix to the corresponding stream flux
ostream & operator<<(ostream &flux, const RGB& rgb) {
  flux << "#" << "(" << rgb.getRed() << ", " << rgb.getGreen() << ", " <<
  rgb.getBlue() << ")";
  return flux;
}
