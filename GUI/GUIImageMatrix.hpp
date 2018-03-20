#ifndef DEF_GUIImageMatrix
#define DEF_GUIImageMatrix

#include "RGB.hpp"
#include <QImage>
#include <QWidget>

class GUIImageMatrix : public QImage {
public:
  GUIImageMatrix(int width, int height);
  void updateColor(const vector<vector<RGB> >& matrixRGB);
  ~GUIImageMatrix();

private:

};
#endif // DEF_GUIImageMatrix
