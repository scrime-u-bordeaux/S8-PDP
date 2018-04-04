/**
 *  \file    RGB.cpp
 *  \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  \date    March 2018
 *
 *  \brief  RGB triplet composed by three integers.
 *
 *  The RGB object is an int triplet and used for processing colors for the
 *  output matrix we obtain at the end of our processing function chain.
 *
 */

#include <iomanip>
#include <iostream>
#include <sstream>
#include "RGB.hpp"

/**
  * Constructor for our RGB triplet.
  */
RGB::RGB(int red, int green, int blue)
    : _red(red), _green(green), _blue(blue) {}

RGB::RGB(string hexaCode){
  int start = 1;
  _red = std::stoi(hexaCode.substr(start, 2), nullptr, 16);
  _green = std::stoi(hexaCode.substr(start + 2, 2), nullptr, 16);
  _blue = std::stoi(hexaCode.substr(start + 4, 2), nullptr, 16);
}

/**
 * Getters and setters for each component of the RGB triplet
 */
int RGB::getRed() const { return _red; }
int RGB::getGreen() const { return _green; }
int RGB::getBlue() const { return _blue; }

void RGB::setRed(int red) { _red = red; }
void RGB::setGreen(int green) { _green = green; }
void RGB::setBlue(int blue) { _blue = blue; }

/**
  * Returns the color RGB triplet to a string corresponding to its RGB values.
  */
string RGB::toString(){
  stringstream stream;
  stream << "#";
  if(this->getRed() == 0 && this->getGreen() == 0 && this->getBlue() == 0){
    stream << "000000";
  }else{
    stream << hex << uppercase << this->getRed();
    stream << hex << uppercase << this->getGreen();
    stream << hex << uppercase << this->getBlue();
  }
  return stream.str();
}


RGB::~RGB() {}

/**
  * Operator overloading to print the RGB matrix to the corresponding ostream
  * flux.
  */
ostream & operator<<(ostream &flux, const RGB& rgb) {
  flux << "#" << rgb.getRed() << rgb.getGreen() << rgb.getBlue();
  return flux;
}
