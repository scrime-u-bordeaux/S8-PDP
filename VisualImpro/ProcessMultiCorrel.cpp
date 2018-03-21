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
    std::vector<std::vector<float> > (*preproc)(std::vector<std::vector<float> >),
    std::vector<float> (*mixLevel)(std::vector<std::vector<float> >))
    : _coeffcorrel(coeffcorrel), _colorscale(colorscale), _preprocess(preproc),
    _mixLevel(mixLevel) { matrixfile.open(string("log/log"), std::ios::app); }

ProcessMultiCorrel::~ProcessMultiCorrel() { matrixfile.close(); }

vector<vector<float> > ProcessMultiCorrel::calcul_correl(const vector<vector<float> >& buffer){
  int size = buffer.size();
  vector<vector<float> > correlMatrix(size, vector<float>(size, 0.0f));
  float coeffcorrel;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i; j++) {
      coeffcorrel = this->_coeffcorrel(buffer[i], buffer[j]);
      correlMatrix[i][j] = correlMatrix[j][i] = coeffcorrel;
      matrixfile << std::to_string(coeffcorrel) << " ";
    }
  }
  matrixfile << std::endl;
  return correlMatrix;
}

void ProcessMultiCorrel::process_volume(const std::vector<std::vector<float> >& correlMatrix, std::vector<float>& meanCorrelations) {
  meanCorrelations = this->_mixLevel(correlMatrix);
}

vector<vector<Triplet> >
ProcessMultiCorrel::color_matrix(const std::vector<std::vector<float> >& correlMatrix) {
  int size = correlMatrix.size();
  Triplet zeros(0, 0, 0);
  Triplet color(0, 0, 0);
  vector<vector<Triplet> > RGBmatrix(size, vector<Triplet>(size, zeros));
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i; j++) {
      color = this->_colorscale(correlMatrix[i][j]);
      RGBmatrix[i][j] = RGBmatrix[j][i] = color;
    }
  }
  return RGBmatrix;
}

void ProcessMultiCorrel::process(const std::vector<std::vector<float> >& buffer,
  std::vector<float>& meanCorrelations, Connection conn) {
  std::vector<std::vector<float> > copy = buffer;
  //Preprocessing
  if (_preprocess != NULL) {
    copy = _preprocess(buffer);
  }
  //Calcul de corrélation
  vector<vector<float> > correlMatrix = calcul_correl(copy);
  //Ajustement des volumes selon les moyennes de corrélations
  if (_mixLevel != NULL) {
    process_volume(correlMatrix, meanCorrelations);
  }
  //Coloration de la matrice
  vector<vector<Triplet> > mat = color_matrix(correlMatrix);
  string str = matrixtostring(mat);
  conn.send(str);
}
