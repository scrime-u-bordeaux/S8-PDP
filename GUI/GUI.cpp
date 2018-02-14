#include "Window.hpp"
#include "Case.hpp"
#include <QApplication>
#include <QGraphicsScene>
#include <QRect>
#include <QtGui>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  // int sizeMatrix = 5;
  // QGraphicsScene scene;
  // for (int x = 0; x < sizeMatrix * SQUARE_SIZE; x += SQUARE_SIZE) {
  //   for (int y = 0; y < sizeMatrix * SQUARE_SIZE; y += SQUARE_SIZE) {
  //     scene.addRect(ORIGIN_X + x, ORIGIN_Y + y, SQUARE_SIZE, SQUARE_SIZE);
  //   }
  // }
  // QGraphicsView view(&scene);
  // int sizeWindow = (SQUARE_SIZE + 1) * sizeMatrix;
  // view.resize(sizeWindow, sizeWindow);
  // view.setWindowTitle("Matrice");

  Case myCase(0,0);
  myCase.show();
  myCase.updateColor(RGB(125,125,125));

  return app.exec();
}
