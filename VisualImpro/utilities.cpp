/***** utilities.cpp *****/

#include "utilities.hpp"
#include "Matrix.hpp"
#include "RGB.hpp"
#include <cmath>
#include <algorithm>
#include "assert.h"
#include <sndfile.h>

using namespace std;

string hexa[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};

string dectohexa(int dec){
  string code;
  if (dec < 0)
    return ("-" + dectohexa(-dec));
  else if(dec <= 15){
    return hexa[dec];
  }
  else
    return (dectohexa(dec/16) + hexa[dec%16]);
}

string colortohexa(int color){
  if ((color < 0) || (color > 255))
    return "00";
  else
    return (hexa[color/16] + hexa[color%16]);
}

string RGBToString(RGB color){;
  return ("#" + colortohexa(color.getRed()) + colortohexa(color.getGreen()) + colortohexa(color.getBlue()));
}

string matrixtostring(Matrix<RGB> matrix){
  //all subvectors must be of same size
  string code;
  if (matrix.getSize() > 0)
    code += (to_string(matrix.getSize()) + "-" + to_string(matrix.getSize()));
  for (int i=0; i<matrix.getSize(); i++){
      for (int j=0; j<matrix.getSize(); j++){
      code += RGBToString(matrix.getCase(i, j));
    }
  }
  return code;
}

bool check_extension(string filename, string extension){
  int i = filename.size()-1;
  while (i != -1){
    if (filename[i] == '.')
      return (filename.substr(i+1, filename.size()-i-1) == extension);
    i--;
  }
  return false;
}

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
