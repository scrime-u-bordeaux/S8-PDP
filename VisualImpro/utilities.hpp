#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <string>
#include <vector>

class Triplet{
public:
  int one, two, three;
  Triplet(int _one, int _two, int _three) : one(_one), two(_two), three(_three){}
};


// Matrix and colors
std::string dectohexa(int dec);
std::string colortohexa(int color);
std::string RGBToString(Triplet RGB);
std::string matrixtostring(std::vector<std::vector <Triplet> > matrix);
std::string print_triplet(Triplet t);
void print_matrix(std::vector<std::vector <Triplet> > matrix);

//Files

bool check_extension(std::string filename, std::string extension);
int getChannelNumber(std::string filename);
std::vector<float> readwav(std::string file);

//Correlation examples

float correlate(const std::vector<float>& s1, const std::vector<float>& s2);
float coeffcorrel(const std::vector<float>& s1, const std::vector<float>& s2);
Triplet greenredscale(float coeff);
float energy(const std::vector <float>& f1, int start, int end);
std::vector<float> energyenvelope(const std::vector<float>& f1, int frame); //cuts f1 in blocks of length 'frame' and applies norm to get the energy of the signal
std::vector< std::vector <float> > energymatrix(const std::vector < std::vector<float> >&);


#endif //UTILITIES_HPP

