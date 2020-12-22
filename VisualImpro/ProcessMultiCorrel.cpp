 
/**
 *  \file    ProcessMultiCorrel.cpp
 *  \author  Jérémy LIXANDRE
 *  \date    July 2017
 *
 *  \brief Processing object composed by function pointers members.
 *
 *  Here are the constructor and all the process functions used in our program.
 *  The render.cpp file will call the process function, as an auxiliary task
 *  accomplished by another thread than the master thread, every time the buffer
 *  is filled with signals of length given in parameter of the program.
 *  The process function will call sequentially every processing function one
 *  by one.
 *
 */

#include <ctime>
#include <iomanip>
#include <sys/time.h>
#include <AuxTaskRT.h>
#include <algorithm>
#include "Matrix.hpp"
#include "ProcessMultiCorrel.hpp"

struct timeval tv10;
struct timeval tv20;
struct timeval tv11;
struct timeval tv12;
struct timeval tv13;
struct timeval tv14;
struct timeval tv15;


ProcessMultiCorrel::ProcessMultiCorrel(
    vector<float> (*coeffcorrel)(const vector<float>&, const vector<float>&),
    RGB (*colorscale)(float),
    Matrix<float> (*preproc)(const Matrix<float>&),
    vector<float> (*mixLevel)(const Matrix<float>&))
    : _coeffcorrel(coeffcorrel), _colorscale(colorscale), _preprocess(preproc),
    _mixLevel(mixLevel) { matrixfile.open(string("log/log"), ios::app); }

/**
 * Destructor for the ProcessMultiCorrel object. It will also close the
 * logfile called matrixfile.
 */
 
ProcessMultiCorrel::~ProcessMultiCorrel() { matrixfile.close(); }

/**
 * Correlation process function.
 */
 
Matrix<vector<float>> ProcessMultiCorrel::calcul_correl(const Matrix<float>& buffer){

  int size = buffer.getSize();
  Matrix<vector<float>> correlMatrix(size);
  vector<float> coeffcorrel;
	
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
    	
      coeffcorrel = this->_coeffcorrel(buffer.getRow(i), buffer.getRow(j));
      correlMatrix.setCase(i, j, coeffcorrel);
      correlMatrix.setCase(j, i, coeffcorrel);
      //matrixfile << to_string(coeffcorrel) << " ";
    }
  }
  matrixfile << endl;
  return correlMatrix;
}

/**
 * Mix volume process function.
 */
 
void ProcessMultiCorrel::process_volume(const Matrix<float>& correlMatrix,
                                        vector<float>& meanCorrelations){
  meanCorrelations = this->_mixLevel(correlMatrix);
}

/**
 * Coloration process function.
 */
 
Matrix<RGB> ProcessMultiCorrel::color_matrix(const Matrix<float>& correlMatrix){
  int size = correlMatrix.getSize();
  Matrix<RGB> RGBmatrix(size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i; j++) {
      RGB color = this->_colorscale(correlMatrix.getCase(i, j));
      RGBmatrix.setCase(i, j, color);
      RGBmatrix.setCase(j, i, color);
    }
  }
  return RGBmatrix;
}


  /**
 * Compute compute the time delay and maximal correlation for each correlation vector.
 */
 void ProcessMultiCorrel::timeDelay(vector<float> c, float* delay, float * max)
 {
 	int maxIndex = std::max_element(c.begin(),c.end()) - c.begin();
 	 *max = *std::max_element(c.begin(),c.end());
 	 *delay = abs((maxIndex - frameSize) / (1.0 * samplerate));
 }
 
 /**
 * Compute different informations from the correlation matrix.
 */
vector<vector<float>> ProcessMultiCorrel::calcul(Matrix<vector<float>> correlMatrix)
{
	
	 vector<float> timeDelays;
	 vector<float> correl;
	 vector<vector<float>> res;
	 float t;
	 float corr; 
	for(int i = 0; i < correlMatrix.getSize(); i++){
		for(int j = 0; j < correlMatrix.getSize(); j++){
			 timeDelay(correlMatrix.getCase(i,j), &t, &corr);
			 cout << corr << endl;
			 timeDelays.push_back(t);
			 correl.push_back(corr);
		}
	}
	res.push_back(timeDelays);
	res.push_back(correl);
	return res;
}

/**
 * Return a string of the entering vector formated in JSON.
 */
string toJson(vector<vector<float>> vec)
{
	JSONObject root;
	JSONObject tensor;
	JSONArray array;
	int k =0;
	

    	JSONArray arr;
    	for(vector<float> v : vec){
    		
    		for(float l : v){
			arr.push_back(new JSONValue(l));
		}
		string s = to_string(k);
		wstring ws= wstring(s.begin(), s.end());
		root[L"vec "+ws] = new JSONValue(arr);
		arr.clear();
		k++;
	}
	
	
	JSONValue *value = new JSONValue(root);
	std::wstring wide = value->Stringify().c_str();
	std::string str( wide.begin(), wide.end() );
	delete value;
	
	return str;
}

/**
 * Calling every processing function sequentially.
 */
void ProcessMultiCorrel::process(const Matrix<float>& buffer,
                                 vector<float>& meanCorrelations,
                                 Connection conn, int factor, int frameSize){
  if(factor == 1)
	samplerate = 22050;
  else 
	samplerate = 44100;
	
  this->frameSize = frameSize;
  Matrix<float> copy = buffer;
  // Processing functions
  copy = _preprocess(buffer);
  Matrix<vector<float>> correlMatrix = calcul_correl(copy);
  //process_volume(correlMatrix, meanCorrelations);
  //Matrix<RGB> mat = color_matrix(correlMatrix);
  vector<vector<float>> cal = calcul(correlMatrix);
  // Send data
  string str = toJson(cal);
  sendTask =  std::unique_ptr<AuxTaskRT>(new AuxTaskRT());
  sendTask->create("send-task", [conn, str]() mutable {conn.send(str);},75);
  sendTask->schedule();
  
}
