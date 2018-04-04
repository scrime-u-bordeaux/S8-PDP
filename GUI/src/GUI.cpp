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

    res = app.exec();
    delete(mainWindow);
  }
  delete(settingWindow);
  return res;
}
