#include "Matrix.hpp"

Matrix::Matrix(int size) : size(size){
    for (int x = 0; x < size * SQUARE_SIZE; x += SQUARE_SIZE) {
      for (int y = 0; y < size * SQUARE_SIZE; y += SQUARE_SIZE) {
        Case(ORIGIN_X + x, ORIGIN_Y + y, this);
      }
    }

}
void setMatrixColor(std::vector<std::vector<RGB> > colorMatrix) {}
Matrix::~Matrix() {}
