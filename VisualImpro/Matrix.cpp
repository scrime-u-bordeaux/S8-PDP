/**
 *  @file    Matrix.cpp
 *  @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date    March 2018
 *
 *  @section DESCRIPTION
 *
 *  The Matrix object is used several times in this program, and replace the
 *  vector<vector<TYPE> > objects. As we process Matrices of signal, this class
 *  was clearly needed by the program.
 *
 */

#include "Matrix.hpp"

using namespace std;

template<class T>
Matrix<T>::Matrix(int sizeMatix): _sizeMatix(sizeMatix){
    vector<vector<T> > Matrix(sizeMatix, vector<T>(sizeMatix));
    _matrix = Matrix;
}

template<class T>
Matrix<T>::Matrix(int sizeMatix, vector<T> vec): _sizeMatix(sizeMatix){
    vector<vector<T> > Matrix(sizeMatix, vec);
    _matrix = Matrix;
}

template<class T>
Matrix<T>::Matrix(int sizeMatix, T value): _sizeMatix(sizeMatix){
    vector<vector<T> > Matrix(sizeMatix, vector<T>(sizeMatix, value));
    _matrix = Matrix;
}

template<>
Matrix<RGB>::Matrix(int sizeMatix): _sizeMatix(sizeMatix){
    RGB color(0,0,0);
    vector<vector<RGB> > Matrix(sizeMatix, vector<RGB>(sizeMatix, color));
    _matrix = Matrix;
}

template<class T>
T Matrix<T>::getCase(int x, int y) const{
    return _matrix[x][y];
}

template<class T>
void Matrix<T>::setCase(int x, int y, T val){
    _matrix[x][y] = val;
}

template<class T>
int Matrix<T>::getSize() const{
    return _sizeMatix;
}

template<class T>
vector<T> Matrix<T>::getRow(int index) const{
  return _matrix[index];
}

template<class T>
vector<T>& Matrix<T>::getRowRef(int index){
  return _matrix[index];
}

template<class T>
void Matrix<T>::setRow(int index, vector<T> column){
  _matrix[index] = column;
}

template<>
void Matrix<float>::swap(Matrix<float>& mat){
  for(int i=0; i<mat.getSize(); i++){
      mat.getRow(i).swap(this->getRowRef(i));
    }
}

template<>
string Matrix<RGB>::toString(){
  string str;
  int row = this->getSize();
  int col = this->getRow(0).size();
  if (row > 0)
    str += (to_string(row) + "-" + to_string(row));
  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
      str += this->getCase(i, j).toString();
    }
  }
  return str;
}

template<class T>
string Matrix<T>::toString(){
  return "Matrix";
}

template<class T>
Matrix<T>::~Matrix(){
  vector<vector<T> > empty;
  empty.swap(_matrix);
}

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<RGB>;
