#include "RGB.hpp"

RGB::RGB(int red, int green, int blue) :
 _red(red), _green(green), _blue(blue){}

string RGB::toString() {
    return "(,,,)";
}
int RGB::getRed(){
    return _red;
}
int RGB::getGreen(){
    return _green;
}
int RGB::getBlue(){
    return _blue;
}
RGB::~RGB(){}
