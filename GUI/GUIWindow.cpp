#include "GUIWindow.hpp"

GUIWindow::GUIWindow(int sizeMatrix, QWidget *parent) : QMainWindow(parent) {
  layout = new MatrixLayout();
  setWindowTitle("Matrice");
  resize(SQUARE_SIZE * sizeMatrix, SQUARE_SIZE * sizeMatrix);

  for (int x = 0; x < sizeMatrix; x++) {
    for (int y = 0; y < sizeMatrix; y++) {
      layout->addWidget(new Case(0, 0, this), x, y);
    }
  }

  setCentralWidget(layout);
}
void GUIWindow::updateColor(vector<vector<RGB> > matrixRGB) {
  layout->updateColor(matrixRGB);
}

GUIWindow::~GUIWindow() { delete layout; }
