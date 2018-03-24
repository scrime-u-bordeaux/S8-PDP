/***** utilities.cpp *****/

#include "utilities.hpp"
#include "SquareMatrix.hpp"
#include "RGB.hpp"
#include <cmath>
#include <algorithm>
#include "assert.h"
#include <sndfile.h>

//converts matrix to string
//(r,g,b) to #rrggbb
//echelle rouge->vert

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
  return color.to_String();
}

string matrixtostring(SquareMatrix<RGB> matrix){
  //all subvectors must be of same size
  string code;
  if (matrix.getSize() > 0)
    code += (to_string(matrix.getSize()) + "-" + to_string(matrix.getSize()));
  for (int i=0; i<matrix.getSize(); i++){
      for (int j=0; j<matrix.getSize(); j++){
      code += matrix.getCase(i, j).to_String();
    }
  }
  return code;
}

void test_colortohexa(int dec){
  cout << dec << "--->" << colortohexa(dec) << endl;
}

void test_dectohexa(int dec){
  cout << dec << "--->" << dectohexa(dec) << endl;
}

void test_RGB(RGB color){
  cout << "RGB " << "--->" << color << endl;
}

SquareMatrix<float> energymatrix(const SquareMatrix<float>& input){
	SquareMatrix<float> buffer(input.getSize());
	for (int i = 0 ; i < input.getSize(); i++){
		buffer.setColumn(i, energyenvelope(input.getColumn(i), 1024));
	}
	return buffer;
}

void print_matrix(SquareMatrix<RGB> matrix){
  cout << "Matrix :\n";
  for (int i = 0; i < matrix.getSize(); i++){
    for (int j = 0; j < matrix.getSize(); j++){
      cout << matrix.getCase(i, j) << " ";
    }
    cout << endl;
  }
}


float correlate(const vector<float>& s1, const vector<float>& s2){
  if (s1.size() == s2.size()){
    float corr = 0.0;
    for (unsigned int i = 0; i < s1.size(); i++){
      corr += s1[i]*s2[i];
    }
    return corr;
  }
  printf("wrong sizes");
  return 0;
}

// (x|y) < sqrt((x|x)(y|y))

float coeffcorrel(const vector<float>& s1, const vector<float>& s2){
	float scal = correlate(s1,s2);
	float norm1 = correlate(s1,s1);
	float norm2 = correlate(s2,s2);
  float coeff = fabs(scal)/sqrt(norm1*norm2);
  assert(coeff <= 1.0);
  return coeff;
}

bool check_extension(string filename, string extension){
  int i = filename.size()-1;
  while (i != -1){
    if (filename[i] == '.'){
      //std::cout << filename.substr(i+1, filename.size()-i-2) << std::endl;
      return (filename.substr(i+1, filename.size()-i-1) == extension);
    }
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


std::vector<float> readwav(std::string file){
  SNDFILE *sf;
  SF_INFO info;
  int num, num_items;
  int i,j;
  info.format = 0;
  sf = sf_open(file.c_str(), SFM_READ, &info);
  if (sf == NULL)
    {
      printf("Failed to open the file.\n");
      exit(-1);
    }
  num_items = info.frames * info.channels;
  float buff[num_items];
  num = sf_read_float(sf, buff, num_items);
  std::vector<float>  buffer(info.frames);
  for (i = 0; i < info.frames; i++){
    for (j = 0 ; j < info.channels; j++){
      buffer[i]+=buff[info.channels * i + j];
    }
  }
  sf_close(sf);
  return buffer;
}
