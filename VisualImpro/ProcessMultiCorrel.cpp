/***** ProcessMultiCorrel.cpp *****/

#include "ProcessMultiCorrel.hpp"
#include "SquareMatrix.hpp"
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
    float (*coeffcorrel)(const std::vector<float>&, const std::vector<float>&),
    RGB (*colorscale)(float),
    SquareMatrix<float> (*preproc)(const SquareMatrix<float>&),
    std::vector<float> (*mixLevel)(const SquareMatrix<float>&))
    : _coeffcorrel(coeffcorrel), _colorscale(colorscale), _preprocess(preproc),
    _mixLevel(mixLevel) { matrixfile.open(string("log/log"), std::ios::app); }

ProcessMultiCorrel::~ProcessMultiCorrel() { matrixfile.close(); }

SquareMatrix<float> ProcessMultiCorrel::calcul_correl(const SquareMatrix<float>& buffer){
  int size = buffer.getSize();
  SquareMatrix<float> correlMatrix(size);
  float coeffcorrel;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i; j++) {
      coeffcorrel = this->_coeffcorrel(buffer.getColumn(i), buffer.getColumn(j));
      correlMatrix.setCase(i, j, coeffcorrel);
      correlMatrix.setCase(j, i, coeffcorrel);
      matrixfile << std::to_string(coeffcorrel) << " ";
    }
  }
  matrixfile << std::endl;
  return correlMatrix;
}

void ProcessMultiCorrel::process_volume(const SquareMatrix<float>& correlMatrix, std::vector<float>& meanCorrelations) {
  meanCorrelations = this->_mixLevel(correlMatrix);
}

SquareMatrix<RGB>
ProcessMultiCorrel::color_matrix(const SquareMatrix<float>& correlMatrix) {
  int size = correlMatrix.getSize();
  SquareMatrix<RGB> RGBmatrix(size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i; j++) {
      RGB color = this->_colorscale(correlMatrix.getCase(i, j));
      RGBmatrix.getCase(i, j) = RGBmatrix.getCase(j, i) = color;
    }
  }
  return RGBmatrix;
}

void ProcessMultiCorrel::process(const SquareMatrix<float>& buffer,
  std::vector<float>& meanCorrelations, Connection conn) {
  SquareMatrix<float> copy = buffer;
  //Preprocessing
  if (_preprocess != NULL) {
    copy = _preprocess(buffer);
  }
  //Calcul de corrélation
  SquareMatrix<float> correlMatrix = calcul_correl(copy);
  //Ajustement des volumes selon les moyennes de corrélations
  if (_mixLevel != NULL) {
    process_volume(correlMatrix, meanCorrelations);
  }
  //Coloration de la matrice
  SquareMatrix<RGB> mat = color_matrix(correlMatrix);
  string str = matrixtostring(mat);
  conn.send(str);
}
