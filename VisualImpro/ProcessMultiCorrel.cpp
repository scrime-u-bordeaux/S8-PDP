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
    float (*coeffcorrel)(const vector<float>&, const vector<float>&),
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
Matrix<float> ProcessMultiCorrel::calcul_correl(const Matrix<float>& buffer){
  int size = buffer.getSize();
  Matrix<float> correlMatrix(size);
  float coeffcorrel;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i; j++) {
      coeffcorrel = this->_coeffcorrel(buffer.getRow(i), buffer.getRow(j));
      correlMatrix.setCase(i, j, coeffcorrel);
      correlMatrix.setCase(j, i, coeffcorrel);
      matrixfile << to_string(coeffcorrel) << " ";
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
 * Calling every processing function sequentially.
 */
void ProcessMultiCorrel::process(const Matrix<float>& buffer,
                                 vector<float>& meanCorrelations,
                                 Connection conn){
  Matrix<float> copy = buffer;

  // Processing functions
  copy = _preprocess(buffer);
  Matrix<float> correlMatrix = calcul_correl(copy);
  process_volume(correlMatrix, meanCorrelations);
  Matrix<RGB> mat = color_matrix(correlMatrix);

  // Send data
  string str = mat.toString();
  conn.send(str);
}
