/**
 * @file GUIWindow.cpp
 * @author Lucas VIVAS
*/

#include "GUIWindow.hpp"

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

GUIWindow::~GUIWindow() {
   delete view;

}
