/***** ProcessMultiCorrel.hpp *****/

#ifndef CORREL_HPP
#define CORREL_HPP

#include "utilities.hpp"
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

class ProcessMultiCorrel{

public :
  void process(const Matrix<float>& buffer, std::vector<float>& meanCorrelations, Connection conn);
  //ProcessMultiCorrel() : _coeffcorrel(NULL), _colorscale(NULL), _preprocess(NULL){}
  ProcessMultiCorrel(float (*coeffcorrel) (const std::vector<float>& s1, const std::vector<float>& s2) = NULL,
    RGB (*colorscale) (float coeff) = NULL,
    Matrix<float>(*preproc) (const Matrix<float>& buff) = NULL,
    std::vector<float>(*mixLevel) (const Matrix<float>& correlMatrix) = NULL);
  void setColor(RGB (*colorscale) (float coeff)){_colorscale = colorscale;}
  void setPreproc(Matrix<float> (* preprocess) (const Matrix<float>& buff)){ _preprocess = preprocess;}
  void setCoeff(float (*coeffcorrel) (const std::vector<float>& s1, const std::vector<float>& s2)){_coeffcorrel = coeffcorrel;}
  void setMix(std::vector<float> (*mixLevel) (const Matrix<float>& correlMatrix)){ _mixLevel = mixLevel;}
  RGB (*getColor()) (float){ return _colorscale;}
  Matrix<float> (* getPreproc()) (const Matrix<float>& buff) { return _preprocess;}
  float (*getCoeff()) (const std::vector<float>& s1, const std::vector<float>& s2) { return _coeffcorrel;}
  std::vector<float> (*getMix()) (const Matrix<float>& correlMatrix) { return _mixLevel;}
  virtual ~ProcessMultiCorrel();

private :
  float (*_coeffcorrel) (const std::vector<float>& s1, const std::vector<float>& s2);
  RGB (*_colorscale) (float coeff);
  Matrix<float> (* _preprocess) (const Matrix<float>& buff);
  std::vector<float> (*_mixLevel)(const Matrix<float>& correlMatrix);
  Matrix<float> calcul_correl(const Matrix<float>& buffer);
  void process_volume(const Matrix<float>& correlMatrix, std::vector<float>& meanCorrelations);
  Matrix<RGB> color_matrix(const Matrix<float>& correlMatrix);
  std::ofstream matrixfile;
};

#endif //SIMPLECORREL_HPP
