#include "GUIWindow.hpp"
#include "RGB.hpp"
#include <QApplication>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  int sizeMatrix = 6;

vector<vector<RGB> > colorMatrix(sizeMatrix, vector<RGB>(sizeMatrix, RGB(0, 255, 0)));
for (int i = 0; i < sizeMatrix; i++) {
  for (int j = 0; j < sizeMatrix; j++) {
    colorMatrix[i][j] = RGB(125,125,0);
  }
}
  GUIWindow mainWindow(sizeMatrix);
  mainWindow.show();

  //mainWindow.updateColor(colorMatrix);

  return app.exec();
}
