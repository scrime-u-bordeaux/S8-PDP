#ifndef DEF_MATRIX
#define DEF_MATRIX

#include "RGB.hpp"
#include "Case.hpp"
#include <QtGui>

class Matrix : public QWidget {
public:
  Matrix(int size);
  void setMatrixColor(std::vector<std::vector<RGB> > colorMatrix);
  ~Matrix();

private:
  int size;
};
#endif // DEF_MATRIX
