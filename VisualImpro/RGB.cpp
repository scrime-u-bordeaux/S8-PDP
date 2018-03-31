#include "RGB.hpp"
#include <sstream>

RGB::RGB(int red, int green, int blue)
    : _red(red), _green(green), _blue(blue) {}


int RGB::getRed() const { return _red; }
int RGB::getGreen() const { return _green; }
int RGB::getBlue() const { return _blue; }

void RGB::setRed(int red) { _red = red; }
void RGB::setGreen(int green) { _green = green; }
void RGB::setBlue(int blue) { _blue = blue; }

string RGB::toString(){
  stringstream ss;
  ss << "(" << this->getRed() << ", " << this->getGreen() << ", " << this->getBlue() << ")";
  //ss << this;
  return ss.str();
}

RGB::~RGB() {}

ostream & operator<<(ostream &flux, const RGB& rgb) {
  flux << "#" << "(" << rgb.getRed() << ", " << rgb.getGreen() << ", " << rgb.getBlue()
  << ")";
  return flux;
}
