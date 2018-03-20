#include "GUIWindow.hpp"
#include "RGB.hpp"
#include <QApplication>
#include <vector>

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  int sizeMatrix = 6;

  GUIWindow mainWindow(sizeMatrix);
  mainWindow.show();

  vector<vector<RGB> > colorMatrix(sizeMatrix,
      vector<RGB>(sizeMatrix, RGB(0, 255, 0)));

  mainWindow.updateColor(&colorMatrix);

  vector<vector<RGB> >colorMatrix2(sizeMatrix,
     vector<RGB>(sizeMatrix, RGB(255, 0, 255)));

  mainWindow.updateColor(&colorMatrix2);

  return app.exec();
}
