#include "GUIImageMatrix.hpp"

GUIImageMatrix::GUIImageMatrix(int width, int height) :
 QImage(width,height,QImage::Format_RGB32){}

void GUIImageMatrix::updateColor(const vector<vector<RGB> >& matrixRGB){}

GUIImageMatrix::~GUIImageMatrix(){
    delete(this);
}
