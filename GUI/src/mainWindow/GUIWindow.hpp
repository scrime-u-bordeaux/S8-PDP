/**
 * @file GUIWindow.hpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#ifndef DEF_GUIWINDOW
#define DEF_GUIWINDOW

#include <QWidget>
#include <QtGui>
#include <vector>

#include "RGB.hpp"
#include "GUIImageMatrix.hpp"
#include "GUITCPServer.hpp"

using namespace std;

class GUIWindow : public QMainWindow {
    Q_OBJECT
public:
  GUIWindow(int sizeMatrix, QWidget *parent = 0);
  void updateColor(const vector<vector<RGB> >& matrixRGB);
  ~GUIWindow();

private:
  GUIImageMatrix *view;
  GUITCPServer *server;

};
#endif // DEF_GUIWINDOW
