/***** ProcessMultiWriteWav.hpp *****/
#ifndef WRITE_WAV_HPP
#define WRITE_WAV_HPP

#include "Matrix.hpp"
#include <stdio.h>
#include <assert.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class ProcessMultiWriteWav{

public :
  void process(const Matrix<float>& buffer);
  void writeheader();
  ProcessMultiWriteWav(std::string filename, int numchannels, int samplerate = 44100, int bytespersample = 2);
  ~ProcessMultiWriteWav();

private :
  std::string filename;
  FILE* stream;
  int numsamples;
  int samplerate;
  int numchannels;
  int bytespersample;
  //std::vector<std::queue<float>> deck;;

};

#endif
