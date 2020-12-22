#ifndef WRITE_WAV_HPP
#define WRITE_WAV_HPP

#include <stdio.h>
#include <assert.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "Matrix.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \class ProcessMultiWriteWav
 * \brief Class used to write wavefiles
 *
 * This class write wavefiles with little endian mode.
 */
class ProcessMultiWriteWav{

public:
  void process(const Matrix<float>& buffer);
  void writeheader();
  ProcessMultiWriteWav(string filename, int numchannels, int samplerate =\
  44100, int bytespersample = 2);
  ~ProcessMultiWriteWav();
private:
  string filename;
  FILE* stream;
  int numsamples;
  int samplerate;
  int numchannels;
  int bytespersample;
  //vector<queue<float>> deck;
};

#endif
