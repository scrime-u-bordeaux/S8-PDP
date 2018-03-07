/***** ProcessMultiWriteWav.hpp *****/
#ifndef WRITE_WAV_HPP
#define WRITE_WAV_HPP

#include <stdio.h>
#include <assert.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class ProcessMultiWriteWav{

public :
  void process(std::vector<std::vector<float> > buffer);
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
};

#endif
