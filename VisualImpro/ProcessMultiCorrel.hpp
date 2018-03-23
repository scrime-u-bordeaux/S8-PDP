/***** ProcessMultiCorrel.hpp *****/

#ifndef CORREL_HPP
#define CORREL_HPP

#include <stdio.h>
#include <assert.h>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>
#include "utilities.hpp"
#include "Connection.hpp"

class ProcessMultiCorrel{

public :
  void process(const std::vector<std::vector<float> >& buffer, std::vector<float>& meanCorrelations, Connection conn);
  //ProcessMultiCorrel() : _coeffcorrel(NULL), _colorscale(NULL), _preprocess(NULL){}
  ProcessMultiCorrel(float (*coeffcorrel) (const std::vector<float>& s1, const std::vector<float>& s2) = NULL,
    Triplet (*colorscale) (float coeff) = NULL,
    std::vector<std::vector<float> >(*preproc) (const std::vector<std::vector<float> >& buff) = NULL,
    std::vector<float>(*mixLevel) (const std::vector<std::vector<float> >& correlMatrix) = NULL);
  void setColor(Triplet (*colorscale) (float coeff)){_colorscale = colorscale;}
  void setPreproc(std::vector<std::vector<float> > (* preprocess) (const std::vector<std::vector<float> >& buff)){ _preprocess = preprocess;}
  void setCoeff(float (*coeffcorrel) (const std::vector<float>& s1, const std::vector<float>& s2)){_coeffcorrel = coeffcorrel;}
  void setMix(std::vector<float> (*mixLevel) (const std::vector<std::vector<float> >& correlMatrix)){ _mixLevel = mixLevel;}
  Triplet (*getColor()) (float){ return _colorscale;}
  std::vector<std::vector<float> > (* getPreproc()) (const std::vector<std::vector<float> >& buff) { return _preprocess;}
  float (*getCoeff()) (const std::vector<float>& s1, const std::vector<float>& s2) { return _coeffcorrel;}
  std::vector<float> (*getMix()) (const std::vector<std::vector<float> >& correlMatrix) { return _mixLevel;}
  virtual ~ProcessMultiCorrel();

private :
  float (*_coeffcorrel) (const std::vector<float>& s1, const std::vector<float>& s2);
  Triplet (*_colorscale) (float coeff);
  std::vector<std::vector<float> > (* _preprocess) (const std::vector<std::vector<float> >& buff);
  std::vector<float> (*_mixLevel)(const std::vector<std::vector<float> >& correlMatrix);
  std::vector<std::vector<float> > calcul_correl(const std::vector<std::vector<float > >& buffer);
  void process_volume(const std::vector<std::vector<float> >& correlMatrix, std::vector<float>& meanCorrelations);
  std::vector<std::vector<Triplet> > color_matrix(const std::vector<std::vector<float> >& correlMatrix);
  std::ofstream matrixfile;
};

#endif //SIMPLECORREL_HPP
