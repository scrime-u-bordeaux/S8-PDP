#ifndef DEF_MATRIX
#define DEF_MATRIX

#include "RGB.hpp"
#include <QRect>
#include <QtGui>

class Matrix : public QWidget {
public:
  Matrix();
  void setMatrixColor(std::vector<std::vector<RGB> > colorMatrix);
  ~Matrix();

private:
};
#endif // DEF_MATRIX
