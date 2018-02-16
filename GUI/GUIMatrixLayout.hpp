#ifndef DEF_MATRIXLAYOUT
#define DEF_MATRIXLAYOUT

#include "RGB.hpp"
#include <QWidget>
#include <QtGui>

class MatrixLayout : public QWidget {
public:
  MatrixLayout(QWidget *parent = 0);
  void addWidget(QWidget *widget, int x, int y);
  void updateColor(vector<vector<RGB> > matrixRGB);
  ~MatrixLayout();

private:
  QGridLayout *layout;
};
#endif // DEF_MATRIXLAYOUT
