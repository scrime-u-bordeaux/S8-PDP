#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Matrix.hpp"
#include "RGB.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

bool check_extension(string filename, string extension);
int getChannelNumber(string filename);

#endif //UTILITIES_HPP
