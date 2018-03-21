#include "RGB.hpp"

RGB::RGB(int red, int green, int blue)
    : _red(red), _green(green), _blue(blue) {}


int RGB::getRed() const { return _red; }
int RGB::getGreen() const { return _green; }
int RGB::getBlue() const { return _blue; }
RGB::~RGB() {}

ostream & operator<<(ostream &flux, const RGB& rgb) {
  flux << "(" << rgb.getRed() << ", " << rgb.getGreen() << ", " << rgb.getBlue()
  << ")";
  return flux;
}
