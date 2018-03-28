#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include "SquareMatrix.hpp"
#include "RGB.hpp"
#include <iostream>
#include <string>
#include <vector>

// Matrix and colors
std::string dectohexa(int dec);
std::string colortohexa(int color);
std::string RGBToString(RGB color);
std::string matrixtostring(SquareMatrix<RGB> matrix);
std::string print_triplet(RGB t);
void print_matrix(std::vector<std::vector <RGB> > matrix);

//Files

bool check_extension(std::string filename, std::string extension);
int getChannelNumber(std::string filename);
std::vector<float> readwav(std::string file);

//Correlation examples

float correlate(const std::vector<float>& s1, const std::vector<float>& s2);
float coeffcorrel(const std::vector<float>& s1, const std::vector<float>& s2);
float energy(const std::vector <float>& f1, int start, int end);
std::vector<float> energyenvelope(const std::vector<float>& f1, int frame); //cuts f1 in blocks of length 'frame' and applies norm to get the energy of the signal
SquareMatrix<float> energymatrix(const SquareMatrix<float>&);


#endif //UTILITIES_HPP
