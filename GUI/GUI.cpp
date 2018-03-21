/**
 * @file GUI.cpp
 * @author Lucas VIVAS
*/

#include "GUIWindow.hpp"
#include "RGB.hpp"
#include <QApplication>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  int sizeMatrix = 6;

  GUIWindow *mainWindow = new GUIWindow(sizeMatrix);
  mainWindow->show();

  vector<vector<RGB> > colorMatrix(sizeMatrix,
                                  vector<RGB>(sizeMatrix, RGB(0, 255, 0)));

  mainWindow->updateColor(colorMatrix);

  vector<vector<RGB> > colorMatrix2(sizeMatrix,
                                   vector<RGB>(sizeMatrix, RGB(255, 0, 255)));
  for (int x = 0; x < sizeMatrix; x++) {
    for (int y = 0; y < x; y++) {
      colorMatrix2[x][y] = colorMatrix2[y][x] = RGB(0, 255, 0);
    }
  }
  mainWindow->updateColor(colorMatrix2);

  return app.exec();
}
