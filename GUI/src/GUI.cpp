/**
 * @file GUI.cpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
 * @brief Main interface class.
 *
 * Create all the windows.
 *
*/

#include "GUISettingWindow.hpp"
#include "GUIWindow.hpp"
#include "RGB.hpp"
#include <QApplication>
#include <vector>

using namespace std;

/**
  * @fn int main(int argc, char *argv[])
  * @brief Create settingWindow and mainWindow
  */

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  int res = 1;
  int sizeMatrix;

  GUISettingWindow *settingWindow = new GUISettingWindow();
  if ((sizeMatrix = settingWindow->exec()) > 0) {
    GUIWindow *mainWindow = new GUIWindow(sizeMatrix);
    mainWindow->show();

    vector<vector<RGB> > colorMatrix(sizeMatrix,
                                    vector<RGB>(sizeMatrix, RGB(0, 255, 0)));
    mainWindow->updateColor(colorMatrix);

    vector<vector<RGB> > colorMatrix2(sizeMatrix,
                                     vector<RGB>(sizeMatrix, RGB(255, 0, 255)));
    for (int x = 0; x < sizeMatrix; x++)
      for (int y = 0; y < x; y++)
        colorMatrix2[x][y] = colorMatrix2[y][x] = RGB(0, 255, 0);
    mainWindow->updateColor(colorMatrix2);

    res = app.exec();
    delete(mainWindow);
  }
  delete(settingWindow);
  return res;
}
