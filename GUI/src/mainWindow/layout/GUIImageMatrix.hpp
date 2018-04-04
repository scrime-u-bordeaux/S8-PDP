/**
 * @file GUIImageMatrix.hpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
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
    Q_OBJECT
public:
  GUIImageMatrix(int sizeMatrix, QWidget *parent = 0);
  ~GUIImageMatrix();

public slots:
  void updateColor(const vector<vector<RGB> > &matrixRGB);
private:
  QPixmap *imagePix;
  QGraphicsScene *scene;
};
#endif // DEF_GUIImageMatrix
