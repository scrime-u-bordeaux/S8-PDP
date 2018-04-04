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
  connect(server, SIGNAL(sendToGUI(vector<vector<RGB>>)), view, SLOT(updateColor(vector<vector<RGB>>)));
}

GUIWindow::~GUIWindow() {
   delete view;

}
