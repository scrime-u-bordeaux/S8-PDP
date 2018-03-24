/***** ProcessMultiCorrel.hpp *****/

#ifndef CORREL_HPP
#define CORREL_HPP

#include "utilities.hpp"
#include "Connection.hpp"
#include "SquareMatrix.hpp"
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
  void process(const SquareMatrix<float>& buffer, std::vector<float>& meanCorrelations, Connection conn);
  //ProcessMultiCorrel() : _coeffcorrel(NULL), _colorscale(NULL), _preprocess(NULL){}
  ProcessMultiCorrel(float (*coeffcorrel) (const std::vector<float>& s1, const std::vector<float>& s2) = NULL,
    RGB (*colorscale) (float coeff) = NULL,
    SquareMatrix<float>(*preproc) (const SquareMatrix<float>& buff) = NULL,
    std::vector<float>(*mixLevel) (const SquareMatrix<float>& correlMatrix) = NULL);
  void setColor(RGB (*colorscale) (float coeff)){_colorscale = colorscale;}
  void setPreproc(SquareMatrix<float> (* preprocess) (const SquareMatrix<float>& buff)){ _preprocess = preprocess;}
  void setCoeff(float (*coeffcorrel) (const std::vector<float>& s1, const std::vector<float>& s2)){_coeffcorrel = coeffcorrel;}
  void setMix(std::vector<float> (*mixLevel) (const SquareMatrix<float>& correlMatrix)){ _mixLevel = mixLevel;}
  RGB (*getColor()) (float){ return _colorscale;}
  SquareMatrix<float> (* getPreproc()) (const SquareMatrix<float>& buff) { return _preprocess;}
  float (*getCoeff()) (const std::vector<float>& s1, const std::vector<float>& s2) { return _coeffcorrel;}
  std::vector<float> (*getMix()) (const SquareMatrix<float>& correlMatrix) { return _mixLevel;}
  virtual ~ProcessMultiCorrel();

private :
  float (*_coeffcorrel) (const std::vector<float>& s1, const std::vector<float>& s2);
  RGB (*_colorscale) (float coeff);
  SquareMatrix<float> (* _preprocess) (const SquareMatrix<float>& buff);
  std::vector<float> (*_mixLevel)(const SquareMatrix<float>& correlMatrix);
  SquareMatrix<float> calcul_correl(const SquareMatrix<float>& buffer);
  void process_volume(const SquareMatrix<float>& correlMatrix, std::vector<float>& meanCorrelations);
  SquareMatrix<RGB> color_matrix(const SquareMatrix<float>& correlMatrix);
  std::ofstream matrixfile;
};

#endif //SIMPLECORREL_HPP
