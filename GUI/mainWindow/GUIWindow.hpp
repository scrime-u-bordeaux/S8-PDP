/**
 * @file GUIWindow.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_GUIWINDOW
#define DEF_GUIWINDOW

#include "GUIImageMatrix.hpp"
#include "RGB.hpp"
#include <QWidget>
#include <QtGui>
#include <vector>

using namespace std;

class GUIWindow : public QMainWindow {
    Q_OBJECT
public:
  GUIWindow(int sizeMatrix, QWidget *parent = 0);
  void updateColor(const vector<vector<RGB> >& matrixRGB);
  ~GUIWindow();

private:
  vector<vector<RGB> > color_matrix(const std::vector<std::vector<float> >& correlMatrix);
  GUIImageMatrix *view;

};
#endif // DEF_GUIWINDOW
