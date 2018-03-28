/**
 * @file GUIWindow.cpp
 * @author Lucas VIVAS
*/

#include "GUIWindow.hpp"

#include <iostream>

/**
 * @fn GUIWindow::GUIWindow(int sizeMatrix, QWidget *parent)
 * @brief Create a main window compose with a matrix inside itself
 *
 * @param sizeMatrix Size of the matrix.
 */
GUIWindow::GUIWindow(int sizeMatrix, QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("Matrice");
  view = new GUIImageMatrix(sizeMatrix, this);
  setCentralWidget(view);
  resize((SQUARE_SIZE * sizeMatrix)+2, (SQUARE_SIZE * sizeMatrix)+2);
}

void GUIWindow::updateColor(const vector<vector<RGB> >& matrixRGB){
  view->updateColor(matrixRGB);
}

vector<vector<RGB> >
GUIWindow::color_matrix(const std::vector<std::vector<float> >& correlMatrix) {
  int size = correlMatrix.size();
  vector<vector<RGB> > RGBmatrix(size, vector<RGB>(size, RGB(0,0,0)));
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i; j++) {
      //color = this->_colorscale(correlMatrix[i][j]);
      //RGBmatrix[i][j] = RGBmatrix[j][i] = color;
    }
  }
  return RGBmatrix;
}

GUIWindow::~GUIWindow() {
  delete view;
  delete this;
}
