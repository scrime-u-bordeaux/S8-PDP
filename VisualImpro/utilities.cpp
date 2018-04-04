/**
 *  \file    utilities.cpp
 *  \author  Jérémy LIXANDRE
 *  \date    July 2017
 *
 *  \brief utilities functions.
 *
 *  This code contain utilities functions used in the main an render files.
 *
 */

#include "utilities.hpp"

/**
 * \fn     bool check_extension(string filename, string extension)
 * \brief  Check if the filename extension corresponds to the extension given
 *         in parameter
 *
 * \param  filename  The name of the file
 * \param  extension The extension (ex: .wav)
 */
bool check_extension(string filename, string extension){
  int i = filename.size()-1;
  while (i != -1){
    if (filename[i] == '.')
      return (filename.substr(i+1, filename.size()-i-1) == extension);
    i--;
  }
  return false;
}

/**
 * \fn     int getChannelNumber(string filename)
 * \brief  Returns the channel number of the filename.
 *
 * \param  filename  The name of the file
 */
int getChannelNumber(string filename){
  if (check_extension(filename, "wav")){
      FILE* stream = fopen(filename.c_str(), "r");
      char buff[2];
      fseek(stream, 22, SEEK_CUR);
      fread(buff,sizeof(char), 2, stream);
      return buff[0] + buff[1]*256;
  }
  return 0;
}
