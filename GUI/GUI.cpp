#include "Case.hpp"
#include "MatrixLayout.hpp"

#include <QApplication>
#include <QGraphicsScene>
#include <QRect>
#include <QtGui>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  int sizeMatrix = 2;

  QMainWindow mainWindow;
  mainWindow.setWindowTitle("Matrice");
  mainWindow.resize(SQUARE_SIZE * sizeMatrix, SQUARE_SIZE * sizeMatrix);

  MatrixLayout *layout = new MatrixLayout;

  Case* tableau [sizeMatrix][sizeMatrix];
  for (int x = 0; x < sizeMatrix ; x++) {
    for (int y = 0; y < sizeMatrix ; y++) {
      tableau[x][y] = new Case(0,0, &mainWindow);
      layout->addWidget(tableau[x][y], x, y);
      }
    }
   mainWindow.setCentralWidget(layout);
   mainWindow.show();

  return app.exec();
}
