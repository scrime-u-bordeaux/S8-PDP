/**
 * @file SquareMatrix.cpp
 * @author Lucas VIVAS
*/

#include "SquareMatrix.hpp"

SquareMatrix::SquareMatrix(int sizeMatix){
    _sizeMatix = sizeMatix;
    _matrix(_sizeMatix, vector<T>(_sizeMatix));
}
/**
 *
 */
T SquareMatrix:getCase(int x, int y){
    return matrix[x][y];
}

void SquareMatrix::setCase(int x, int y, int val){

}

int SquareMatrix::getSize() {
    return _sizeMatix;
}

string SquareMatrix::toString(){
    return NULL;
}

SquareMatrix::~SquareMatrix(){

}
