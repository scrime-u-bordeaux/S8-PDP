#ifndef DEF_MATRIX
#define DEF_MATRIX

#include "../VisualImpro/utilities.hpp"
#include <QRect>
#include <QtGui>

class Matrix : public QGraphicsScene {
public:
  Matrix();
  void setMatrixColor(std::vector<std::vector<Triplet> > colorMatrix);
  ~Matrix();

private:
};
#endif // DEF_MATRIX
