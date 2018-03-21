#include "GUIWindow.hpp"
#include "GUIImageMatrix.hpp"

#include <QPainter>
#include <QPixmap>
#include <QColor>
#include <QGraphicsView>

#include <iostream>

GUIWindow::GUIWindow(int sizeMatrix, QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("Matrice");

  QWidget *principalWidget = new QWidget;
  imagePix = new QPixmap(SQUARE_SIZE * sizeMatrix, SQUARE_SIZE * sizeMatrix);

  scene = new QGraphicsScene(this);

  scene->addPixmap(*imagePix);

  QGraphicsView *view = new QGraphicsView;
  view->setScene(scene);

  setCentralWidget(view);
  resize((SQUARE_SIZE * sizeMatrix)+2, (SQUARE_SIZE * sizeMatrix)+2);
}


void GUIWindow::updateColor(vector<vector<RGB> >* matrixRGB) {
  int sizeMatrix = matrixRGB->size();

  cout << matrixRGB[0][0][0].getRed() << endl;

  QPainter *paint = new QPainter(imagePix);
  paint->setPen(*(new QColor(255,255,255)));
  for (int x = 0; x < sizeMatrix*SQUARE_SIZE; x+=SQUARE_SIZE) {
    for (int y = 0; y < sizeMatrix*SQUARE_SIZE; y+=SQUARE_SIZE) {
      RGB color = matrixRGB[0][0][0];
      paint->setBrush(*(new QColor(color.getRed(), color.getGreen(), color.getBlue())));
      paint->drawRect(x,y,SQUARE_SIZE,SQUARE_SIZE);
    }
  }
  scene->addPixmap(*imagePix);
  delete(paint);
}


GUIWindow::~GUIWindow() {}
