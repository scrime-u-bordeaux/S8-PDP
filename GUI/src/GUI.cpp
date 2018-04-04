/**
 * \file GUI.cpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
 * \brief The main GUI class.
 *
 * The GUI main will create all the windows, one for the settings and one for
 * printing the colored matrix.
 *
*/

#include <QApplication>
#include <vector>
#include "GUISettingWindow.hpp"
#include "GUIWindow.hpp"
#include "RGB.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
  * \fn int main(int argc, char *argv[])
  * \brief Create a settingWindow and a mainWindow
  *
  * \param   argc The number of arguments given to the program.
  * \param   argv The list of arguments given to the program.
  * \return An interger corresponding to EXIT_SUCCESS or EXIT_FAILURE.
  *
  * The main function will create a settings window and wait for the user to
  * give input settings. Once the user has defined the settings a GUI window
  * will appear on screen with the matrix created of size equals to the total
  * number of inputs.
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
