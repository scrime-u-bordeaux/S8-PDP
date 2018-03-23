/***** utilities.cpp *****/

#include "utilities.hpp"
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

string RGBToString(Triplet RGB){
  return ("#" + colortohexa(RGB.one) + colortohexa(RGB.two) + colortohexa(RGB.three));
}

string matrixtostring(vector<vector <Triplet> > matrix){
  //all subvectors must be of same size
  string code;
  if (matrix.size() > 0)
    code+=(to_string(matrix.size()) + "-" + to_string(matrix[0].size()));
  for (  vector<vector <Triplet> >::iterator it = matrix.begin(); it != matrix.end(); it++){
    for (vector<Triplet>::iterator it2 = it->begin(); it2 != it->end(); it2++){
      code+=RGBToString(*it2);
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

void test_RGB(Triplet RGB){
  cout << "RGB " << RGB.one << "-" << RGB.two << "-" << RGB.three << "--->" << RGBToString(RGB) << endl;
}

string print_triplet(Triplet tr){
  return "(" + to_string(tr.one) + "," + to_string(tr.two) + ","  + to_string(tr.three) + ")";
}


/*float energy(const vector <float>& f1, int start, int end){
  float en = 0.0;
  for (int i = start; i < end; i++){
    en+=pow(f1[i],2);
  }
  return en/(end-start);
}

vector<float> energyenvelope(const vector<float>& f1, int frame){ //cuts f1 in blocks of length 'frame' and applies norm to get the energy of the signal
  int size = f1.size();
  int nbframes = 0;
  if(size%frame == 0)
  	{
  	nbframes = size/frame;
 	}
  else
  {
	nbframes = size/frame + 1;
  }
  vector<float> energ(nbframes, 0.0);
  for (int i = 0; i < nbframes; i++){
    energ[i] = energy(f1, i*frame, min(i*frame + frame, size));
  }
  return energ;
}*/

std::vector< std::vector <float> > energymatrix(const std::vector < std::vector<float> >& input){
	std::vector< std::vector <float> > buffer(input.size());
	for (unsigned int i = 0 ; i < input.size(); i++){
		buffer[i] = energyenvelope(input[i], 1024);
	}
	return buffer;
}

void print_matrix(std::vector<std::vector <Triplet> > matrix){
  cout << "Matrix :\n";
  for (unsigned int i = 0; i < matrix.size(); i++){
    for (unsigned int j = 0; j < matrix.size(); j++){
      cout << print_triplet(matrix[i][j]) << " ";
    }
    cout << endl;
  }
}


float correlate(const vector<float>& s1, const vector<float>& s2){
  if (s1.size() == s2.size()){
    float corr = 0.0;
    for (unsigned int i = 0; i < s1.size(); i++){
      corr += s1[i]*s2[i];
      //printf("s12 %f %f", s1[i], s2[i]);
    }
    //printf("corr %f\n", corr);
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
  //printf("coucou %f %f %f %f\n", coeff, scal, norm1, norm2);
  return coeff;
}

Triplet greenredscale(float coeff) //given a coefficient, computes an RGB triplet, where 0.01 is red (0 is black) and 1 is green
{
  Triplet rgb(0,0,0);
  if (coeff < 0.0000001){
    return rgb;
  }
  else if (coeff < 0.5){
    rgb.one = 250; //red
    rgb.two = ((int) (235* (coeff * 2))) + 20; //green
  }
  else{
    rgb.one = ((int) 235*(1-coeff)*2) + 20; //red
    rgb.two = 250; //green
  }
  rgb.three = 20; //blue
  return rgb;
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
