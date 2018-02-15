#ifndef DEF_GUIWINDOW
#define DEF_GUIWINDOW

#include "GUICase.hpp"
#include "GUIMatrixLayout.hpp"
#include <QWidget>
#include <QtGui>

class GUIWindow : public QMainWindow {
public:
  GUIWindow(int sizeMatrix, QWidget *parent = 0);
  void updateColor(vector<vector<RGB> > matrixRGB);
  ~GUIWindow();

private:
  MatrixLayout *layout;
};
#endif // DEF_GUIWINDOW
