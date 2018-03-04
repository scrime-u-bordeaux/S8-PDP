/*
This code is inspired by https://gasstationwithoutpumps.wordpress.com/2011/10/08/making-wav-files-from-c-programs/
*/

#include "ProcessMultiWriteWav.hpp"
#include <assert.h>
#include <vector>

void write_little_endian(unsigned int word, int num_bytes, FILE *stream)
{
    unsigned buf;
    while(num_bytes>0)
    {   buf = word & 0xff;
        fwrite(&buf, 1,1, stream);
        num_bytes--;
    word >>= 8;
    }
}

ProcessMultiWriteWav::ProcessMultiWriteWav(std::string filename, int numchannels, int samplerate, int bytespersample){
  this->filename = filename;
  this->numchannels = numchannels;
  this->samplerate = samplerate;
  this->bytespersample = bytespersample;

  this->numsamples = 0;
  this->stream = fopen(this->filename.c_str(), "w");

  fseek(stream, 44, SEEK_CUR);
}

void ProcessMultiWriteWav::process(std::vector<std::vector<float> > buffer){

fseek(stream, 0, SEEK_END);
  int x = buffer.size();
  if (x != 0){
    int y = buffer[0].size();
    float tmp = 0;
    short int intVal = 0;
    for (int sample = 0 ; sample < y ; sample ++){
    	//float j = buffer[0][sample];
      for (int channel = 0 ; channel < x ; channel++){
      	assert((buffer[channel][sample] - buffer[0][sample])*(buffer[channel][sample] - buffer[0][sample]) <= 0.001);
		tmp += buffer[channel][sample];
    }
      intVal = (short int)(tmp * 32768.0/x);
      //stream << intVal;
      write_little_endian((unsigned int) (intVal),2, stream);
      tmp = 0;
    }

    this->numsamples+=y;

  }
}

void ProcessMultiWriteWav::writeheader(){

  rewind(stream);

  int byterate = samplerate*numchannels*bytespersample;

  fwrite("RIFF", 1, 4, stream);
  write_little_endian(36 + bytespersample* numsamples*numchannels, 4, stream);
  fwrite("WAVE", 1, 4, stream);

  /* write fmt  subchunk */
  fwrite("fmt ", 1, 4, stream);
  write_little_endian(16, 4, stream);   /* SubChunk1Size is 16 */
  write_little_endian(1, 2, stream);    /* PCM is format 1 */
  write_little_endian(numchannels, 2, stream);
  write_little_endian(samplerate, 4, stream);
  write_little_endian(byterate, 4, stream);
  write_little_endian(numchannels*bytespersample, 2, stream);  /* block align */
  write_little_endian(8*bytespersample, 2, stream);  /* bits/sample */
  fwrite("data", 1, 4, stream);
  write_little_endian(bytespersample*numsamples*numchannels, 4, stream);
}

ProcessMultiWriteWav::~ProcessMultiWriteWav(){
	this->writeheader();
  fclose(this->stream);
}
