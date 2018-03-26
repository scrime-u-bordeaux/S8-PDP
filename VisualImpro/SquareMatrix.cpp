/**
 * @file SquareMatrix.cpp
 * @author Lucas VIVAS
*/

#include "SquareMatrix.hpp"

using namespace std;

template<class T>
SquareMatrix<T>::SquareMatrix(int sizeMatix): _sizeMatix(sizeMatix){
    vector<vector<T> > SquareMatrix(sizeMatix, vector<T>(sizeMatix));
    _matrix = SquareMatrix;
}

template<class T>
SquareMatrix<T>::SquareMatrix(int sizeMatix, vector<T> vec): _sizeMatix(sizeMatix){
    vector<vector<T> > SquareMatrix(sizeMatix, vec);
    _matrix = SquareMatrix;
}

template<>
SquareMatrix<RGB>::SquareMatrix(int sizeMatix): _sizeMatix(sizeMatix){
    RGB color(0,0,0);
    vector<vector<RGB> > SquareMatrix(sizeMatix, vector<RGB>(sizeMatix, color));
    _matrix = SquareMatrix;
}


template<class T>
T SquareMatrix<T>::getCase(int x, int y) const{
    return _matrix[x][y];
}

template<class T>
void SquareMatrix<T>::setCase(int x, int y, T val){
    _matrix[x][y] = val;
}

template<class T>
int SquareMatrix<T>::getSize() const{
    return _sizeMatix;
}

template<class T>
vector<T> SquareMatrix<T>::getColumn(int index) const{
  return _matrix[index];
}

template<class T>
vector<T>& SquareMatrix<T>::getColumnRef(int index){
  return _matrix[index];
}

template<class T>
void SquareMatrix<T>::setColumn(int index, vector<T> column){
  _matrix[index] = column;
}

template<class T>
void SquareMatrix<T>::swap(SquareMatrix<T>& mat){
  SquareMatrix<T> tmp(mat.getSize());
  for(int i=0; i<mat.getSize(); i++){
    for(int j=0; j<mat.getSize(); j++){
      tmp.setCase(i, j, mat.getCase(i, j));
      mat.setCase(i, j, this->getCase(i, j));
      this->setCase(i, j, tmp.getCase(i, j));
    }
  }
}

template<class T>
string SquareMatrix<T>::toString(){
  return "SquareMatrix";
}

template<class T>
SquareMatrix<T>::~SquareMatrix(){
  vector<vector<T> > empty;
  empty.swap(_matrix);
}

template class SquareMatrix<int>;
template class SquareMatrix<float>;
template class SquareMatrix<RGB>;
