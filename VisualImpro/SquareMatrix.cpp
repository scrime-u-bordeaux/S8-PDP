/**
 * @file SquareMatrix.cpp
 * @author Lucas VIVAS
*/

#include "SquareMatrix.hpp"

template<class T>
SquareMatrix<T>::SquareMatrix(int sizeMatix): _sizeMatix(sizeMatix),
    _matrix(sizeMatix, vector<T>(sizeMatix)) {}


template<class T>
T SquareMatrix<T>::getCase(int x, int y){
    return _matrix[x][y];
}

template<class T>
void SquareMatrix<T>::setCase(int x, int y, T val){
    _matrix[x][y] = val;
}

template<class T>
int SquareMatrix<T>::getSize() {
    return _sizeMatix;
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
