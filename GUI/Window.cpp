#include "Window.hpp"

#include <QtGui>

Window::Window(int sizeMatrix) : scene() {
  scene = new QGraphicsScene();
  for (int x = 0; x < sizeMatrix * SQUARE_SIZE; x += SQUARE_SIZE) {
    for (int y = 0; y < sizeMatrix * SQUARE_SIZE; y += SQUARE_SIZE) {
      scene->addRect(ORIGIN_X + x, ORIGIN_Y + y, SQUARE_SIZE, SQUARE_SIZE);
    }
  }

  QGraphicsView(scene);
  int sizeWindow = (SQUARE_SIZE + 1) * sizeMatrix;
  QGraphicsView::resize(sizeWindow, sizeWindow);
  QGraphicsView::setWindowTitle("Matrice");
}

Window::~Window() {}
