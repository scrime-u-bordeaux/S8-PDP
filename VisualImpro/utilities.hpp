#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include "Matrix.hpp"
#include "RGB.hpp"
#include <iostream>
#include <string>
#include <vector>

// Matrix and colors
std::string dectohexa(int dec);
std::string colortohexa(int color);
std::string RGBToString(RGB color);
std::string matrixtostring(Matrix<RGB> matrix);

//Files

bool check_extension(std::string filename, std::string extension);
int getChannelNumber(std::string filename);

float energy(const vector <float>& f1, int start, int end);

#endif //UTILITIES_HPP
