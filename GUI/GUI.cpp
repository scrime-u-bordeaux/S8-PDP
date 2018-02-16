#include "GUIWindow.hpp"

#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  int sizeMatrix = 6;

  GUIWindow mainWindow(sizeMatrix);
  mainWindow.show();

  return app.exec();
}
