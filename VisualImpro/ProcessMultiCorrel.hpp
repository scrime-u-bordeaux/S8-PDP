/***** ProcessMultiCorrel.hpp *****/

#ifndef CORREL_HPP
#define CORREL_HPP

#include <stdio.h>
#include <assert.h>
#include "ProcessMulti.hpp"
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>
#include "utilities.hpp"

class ProcessMultiCorrel : public ProcessMulti{

public : 
  void process(std::vector<std::vector<float> > buffer, Connection conn);
  //ProcessMultiCorrel() : _coeffcorrel(NULL), _colorscale(NULL), _preprocess(NULL){}
  ProcessMultiCorrel(float (*coeffcorrel) (std::vector<float> s1, std::vector<float> s2) = NULL, Triplet (*colorscale) (float coeff) = NULL,   std::vector<std::vector<float> >(* preproc) (std::vector<std::vector<float> >) = NULL); 
void setColor(Triplet (*colorscale) (float coeff)){_colorscale = colorscale;}
void setPreproc(std::vector<std::vector<float> > (* preprocess) (std::vector<std::vector<float> > buff)){ _preprocess = preprocess;}
void setCoeff(float (*coeffcorrel) (std::vector<float> s1, std::vector<float> s2)){_coeffcorrel = coeffcorrel;}
~ProcessMultiCorrel();

private :
  float (*_coeffcorrel) (std::vector<float> s1, std::vector<float> s2);
  Triplet (*_colorscale) (float coeff);
  std::vector<std::vector<float> > (* _preprocess) (std::vector<std::vector<float> > buff);
  vector<vector <Triplet> > create_matrix(std::vector<std::vector<float> > buffer);
  std::ofstream matrixfile;
};

#endif //SIMPLECORREL_HPP
