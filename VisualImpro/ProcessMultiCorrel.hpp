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
  void process(std::vector<std::vector<float> > buffer, std::vector<float>& meanCorrelations, Connection conn);
  ProcessMultiCorrel(float (*coeffcorrel) (std::vector<float> s1, std::vector<float> s2) = NULL,
    Triplet (*colorscale) (float coeff) = NULL,
    std::vector<std::vector<float> >(*preproc) (std::vector<std::vector<float> >) = NULL,
    std::vector<float>(*mixLevel) (std::vector<std::vector<float> >) = NULL);
  void setColor(Triplet (*colorscale) (float coeff)){_colorscale = colorscale;}
  void setPreproc(std::vector<std::vector<float> > (* preprocess) (std::vector<std::vector<float> > buff)){ _preprocess = preprocess;}
  void setCoeff(float (*coeffcorrel) (std::vector<float> s1, std::vector<float> s2)){_coeffcorrel = coeffcorrel;}
  void setMix(std::vector<float> (*mixLevel) (std::vector<std::vector<float> > correlMatrix)){ _mixLevel = mixLevel;}
  ~ProcessMultiCorrel();

private :
  float (*_coeffcorrel) (std::vector<float> s1, std::vector<float> s2);
  Triplet (*_colorscale) (float coeff);
  std::vector<std::vector<float> > (* _preprocess) (std::vector<std::vector<float> > buff);
  std::vector<float> (*_mixLevel)(std::vector<std::vector<float> > correlMatrix);
  std::vector<std::vector<float> > calcul_correl(std::vector<std::vector<float > > buffer);
  void process_volume(std::vector<std::vector<float> > correlMatrix, std::vector<float>& meanCorrelations);
  std::vector<std::vector<Triplet> > color_matrix(std::vector<std::vector<float> > correlMatrix);
  std::ofstream matrixfile;
};

#endif //SIMPLECORREL_HPP
