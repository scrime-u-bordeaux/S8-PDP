/**
 * @file GUIWindow.cpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#include "GUIWindow.hpp"

/**
 * @fn GUIWindow::GUIWindow(int sizeMatrix, QWidget *parent)
 * @brief Create a main window compose with a matrix inside itself
 *
 * @param sizeMatrix Size of the matrix.
 */
GUIWindow::GUIWindow(int sizeMatrix, QWidget *parent) : QMainWindow(parent),
 view(new GUIImageMatrix(sizeMatrix, this)),
 server(new GUITCPServer()) {
  setWindowTitle("Matrice");
  setCentralWidget(view);
  resize((SQUARE_SIZE * sizeMatrix)+2, (SQUARE_SIZE * sizeMatrix)+2);
}

void GUIWindow::updateColor(const vector<vector<RGB> >& matrixRGB){
  view->updateColor(matrixRGB);
}

GUIWindow::~GUIWindow() {
   delete view;

}
