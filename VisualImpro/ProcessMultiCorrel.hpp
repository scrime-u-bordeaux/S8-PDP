#ifndef CORREL_HPP
#define CORREL_HPP

#include "Connection.hpp"
#include "Matrix.hpp"
#include "RGB.hpp"
#include <stdio.h>
#include <assert.h>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>

using namespace std;

class ProcessMultiCorrel{

public :
  void process(const Matrix<float>& buffer, vector<float>&\
  meanCorrelations, Connection conn);
  //ProcessMultiCorrel() : _coeffcorrel(NULL), _colorscale(NULL),\
  //_preprocess(NULL){}
  ProcessMultiCorrel(float (*coeffcorrel) (const vector<float>& s1,
  const vector<float>& s2) = NULL, RGB (*colorscale) (float coeff) = NULL,
  Matrix<float>(*preproc) (const Matrix<float>& buff) = NULL,
  vector<float>(*mixLevel) (const Matrix<float>& correlMatrix) = NULL);

  void setColor(RGB (*colorscale) (float coeff)){
    _colorscale = colorscale;
  }
  void setPreproc(Matrix<float> (* preprocess) (const Matrix<float>& buff)){
    _preprocess = preprocess;
  }
  void setCoeff(float (*coeffcorrel) (const vector<float>& s1,
                                      const vector<float>& s2)){
    _coeffcorrel = coeffcorrel;
  }
  void setMix(vector<float> (*mixLevel) (const Matrix<float>&
                                              correlMatrix)){
    _mixLevel = mixLevel;
  }

  RGB (*getColor()) (float){
    return _colorscale;
  }
  Matrix<float> (* getPreproc()) (const Matrix<float>& buff){
    return _preprocess;
  }
  float (*getCoeff()) (const vector<float>& s1,
                       const vector<float>& s2){
    return _coeffcorrel;
  }
  vector<float> (*getMix()) (const Matrix<float>& correlMatrix){
    return _mixLevel;
  }

  virtual ~ProcessMultiCorrel();

private :
  float (*_coeffcorrel) (const vector<float>& s1,
                         const vector<float>& s2);
  RGB (*_colorscale) (float coeff);
  Matrix<float> (* _preprocess) (const Matrix<float>& buff);
  vector<float> (*_mixLevel)(const Matrix<float>& correlMatrix);
  Matrix<float> calcul_correl(const Matrix<float>& buffer);
  void process_volume(const Matrix<float>& correlMatrix,
                      vector<float>& meanCorrelations);
  Matrix<RGB> color_matrix(const Matrix<float>& correlMatrix);
  ofstream matrixfile;
};

#endif //SIMPLECORREL_HPP
