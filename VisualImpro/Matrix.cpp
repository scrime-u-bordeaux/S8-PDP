/**
 *  \file    Matrix.cpp
 *  \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  \date    March 2018
 *
 *  \brief Matrix object composed by rows and columns.
 *
 *  The Matrix object is used several times in this program, and replace the
 *  vector<vector<TYPE> > objects. As we process Matrices of signal, this class
 *  was clearly needed by the program.
 *
 */

#include "Matrix.hpp"

/**
 * Constructs a squared matrix with size equals to sizeMatix.
 */
template<class T>
Matrix<T>::Matrix(){
    vector<vector<T> > matrix;
    _matrix = matrix;
}

/**
 * Constructs a squared matrix with size equals to sizeMatix.
 */
template<class T>
Matrix<T>::Matrix(int sizeMatix): _sizeMatix(sizeMatix){
    vector<vector<T> > Matrix(sizeMatix, vector<T>(sizeMatix));
    _matrix = Matrix;
}

/**
 * Constructs a RGB squared matrix with size equals to sizeMatix and each case
 * Initialized with a RGB triplet eqauls to (0,0,0).
 */
template<>
Matrix<RGB>::Matrix(int sizeMatix): _sizeMatix(sizeMatix){
  RGB color(0,0,0);
  vector<vector<RGB> > Matrix(sizeMatix, vector<RGB>(sizeMatix, color));
  _matrix = Matrix;
}

/**
 * Constructs a squared matrix with size equals to sizeMatix and each case
 * Initialized with the value value.
 */
template<class T>
Matrix<T>::Matrix(int sizeMatix, T value): _sizeMatix(sizeMatix){
  vector<vector<T> > Matrix(sizeMatix, vector<T>(sizeMatix, value));
  _matrix = Matrix;
}

/**
 * Constructs a matrix with size equals to sizeMatix and each line equals to
 * the vector vec.
 */
template<class T>
Matrix<T>::Matrix(int sizeMatix, vector<T> vec): _sizeMatix(sizeMatix){
    vector<vector<T> > Matrix(sizeMatix, vec);
    _matrix = Matrix;
}

/**
 * Returns the value of the case of coordonates (x,y) in the matrix.
 */
template<class T>
T Matrix<T>::getCase(int x, int y) const{
    return _matrix[x][y];
}

/**
 * Set the value of the case of coordonates (x,y) in the matrix with val.
 */
template<class T>
void Matrix<T>::setCase(int x, int y, T val){
    _matrix[x][y] = val;
}

/**
 * Returns the size of the matrix.
 */
template<class T>
int Matrix<T>::getSize() const{
    return _sizeMatix;
}

/**
 * Returns the row number index of the matrix.
 */
template<class T>
vector<T> Matrix<T>::getRow(int index) const{
  return _matrix[index];
}

/**
 * Returns a reference to the row number index of the matrix.
 */
template<class T>
vector<T>& Matrix<T>::getRowRef(int index){
  return _matrix[index];
}

/**
 * Set the row number index of the matrix with row.
 */
template<class T>
void Matrix<T>::setRow(int index, vector<T> row){
  _matrix[index] = row;
}

/**
 * Returns the entire matrix.
 */
template<class T>
vector<vector<T> > Matrix<T>::getMatrix(){
  return _matrix;
}

/**
 * Returns a reference to the entire matrix.
 */
template<class T>
vector<vector<T> >& Matrix<T>::getMatrixRef(){
  return _matrix;
}

/**
 * Swap the matrix mat with the matrix calling the function.
 */
template<>
void Matrix<float>::swap(Matrix<float>& mat){
  mat.getMatrix().swap(thix->getMatrixRef());
/*  for(int i=0; i<mat.getSize(); i++){
      mat.getRow(i).swap(this->getRowRef(i));
    }*/
}

/**
 * Returns a string corresponding to the dimension and the matrix values of
 * each case.
 */
template<class T>
string Matrix<T>::toString(){
  string str;
  int row = this->getSize();
  int col = this->getRow(0).size();
  if (row > 0)
    str += (to_string(row) + "-" + to_string(row));
  for (int i = 0; i < row; i++){
    for (int j = 0; j < col; j++){
      str += to_string(this->getCase(i, j));
    }
  }
  return str;
}

/**
 * Destrucs the matrix and free the memory by swapping our matrix by another
 * empty matrix.
 */
template<class T>
Matrix<T>::~Matrix(){
  Matrix empty;
  empty.swap(_matrix);
}

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<RGB>;
