/**
 * @file GUIImageMatrix.hpp
 * @author Lucas VIVAS
*/
#ifndef DEF_GUIImageMatrix
#define DEF_GUIImageMatrix

#include "RGB.hpp"
#include <QWidget>
#include <QtGui>
#include <QImage>
#include <QGraphicsScene>
#include <vector>

using namespace std;

#define SQUARE_SIZE 200

class GUIImageMatrix : public QGraphicsView {
public:
  GUIImageMatrix(int sizeMatrix, QWidget *parent = 0);
  void updateColor(const vector<vector<RGB> > &matrixRGB);
  ~GUIImageMatrix();

private:
  QPixmap *imagePix;
  QGraphicsScene *scene;
};
#endif // DEF_GUIImageMatrix
