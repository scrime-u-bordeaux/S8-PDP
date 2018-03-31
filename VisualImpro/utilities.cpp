/***** utilities.cpp *****/

#include "utilities.hpp"

/* Function used to check if the filename extension corresponds to the extension
 * given in parameter
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

// Returns the channel number of the filename
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
