/***** ProcessMultiCorrel.cpp *****/

#include "ProcessMultiCorrel.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sys/time.h>

struct timeval tv10;
struct timeval tv20;
struct timeval tv11;
struct timeval tv12;
struct timeval tv13;
struct timeval tv14;
struct timeval tv15;

ProcessMultiCorrel::ProcessMultiCorrel(
    float (*coeffcorrel)(std::vector<float> s1, std::vector<float> s2),
    Triplet (*colorscale)(float coeff),
    std::vector<std::vector<float>> (*preproc)(std::vector<std::vector<float>>))
    : _coeffcorrel(coeffcorrel), _colorscale(colorscale), _preprocess(preproc) {
  matrixfile.open(string("log/log"), std::ios::app);
}

ProcessMultiCorrel::~ProcessMultiCorrel() { matrixfile.close(); }

vector<vector<Triplet>>
ProcessMultiCorrel::create_matrix(std::vector<std::vector<float>> buffer) {
  int size = buffer.size();
  Triplet zeros(0, 0, 0);
  float coeffcorrel;
  Triplet color(0, 0, 0);
  vector<vector<Triplet>> matrix(size, vector<Triplet>(size, zeros));
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i; j++) {
      coeffcorrel = this->_coeffcorrel(buffer[i], buffer[j]);
      matrixfile << std::to_string(coeffcorrel) << " ";
      color = this->_colorscale(coeffcorrel);
      matrix[i][j] = matrix[j][i] = color;
    }
  }
  matrixfile << std::endl;
  return matrix;
}

// POSSIBILITE DE RECUPERER LES COEFFICIENTS DE CORRELATION AFIN DE LES INTEGRER
// AU RENDER.CPP ?

void ProcessMultiCorrel::process(std::vector<std::vector<float>> buffer,
                                 Connection conn) {
  std::vector<std::vector<float>> copy = buffer;
  if (_preprocess != NULL) {
    copy = _preprocess(buffer);
  }
  vector<vector<Triplet>> mat = create_matrix(copy);
  string str = matrixtostring(mat);
  conn.send(str);
}
