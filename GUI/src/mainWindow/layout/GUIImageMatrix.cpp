/**
 * \file GUIImageMatrix.cpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/
#include "GUIImageMatrix.hpp"

GUIImageMatrix::GUIImageMatrix(int sizeMatrix, QWidget *parent) : QGraphicsView(parent) {
  imagePix = new QPixmap(SQUARE_SIZE * sizeMatrix, SQUARE_SIZE * sizeMatrix);
  scene = new QGraphicsScene(this);

  scene->addPixmap(*imagePix);
  setScene(scene);
}

void GUIImageMatrix::updateColor(const Matrix<RGB> &matrixRGB) {
  int sizeMatrix = matrixRGB.getSize();
  QPainter *paint = new QPainter(imagePix);

  paint->setPen(*(new QColor(255, 255, 255)));
  for (int x = 0; x < sizeMatrix; x++) {
    for (int y = 0; y < sizeMatrix; y++) {
      const RGB &color = matrixRGB.getCase(x,y);
      paint->setBrush(
          *(new QColor(color.getRed(), color.getGreen(), color.getBlue())));
      paint->drawRect(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE,
                      SQUARE_SIZE);
    }
  }
  scene->addPixmap(*imagePix);
  delete (paint);
}

GUIImageMatrix::~GUIImageMatrix() {
  delete imagePix;
  delete scene;
}
