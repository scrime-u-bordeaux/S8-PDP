#include "GUIMatrixLayout.hpp"


#include "GUICase.hpp"

MatrixLayout::MatrixLayout(QWidget *parent) : QWidget(parent) {
  layout = new QGridLayout(this);
  setLayout(layout);
}

void MatrixLayout::addWidget(QWidget *widget, int x, int y) {
  layout->addWidget(widget, x, y);
}


void MatrixLayout::updateColor(const vector<vector<RGB> >& matrixRGB) {
    int size = matrixRGB.size();
    for (int x = 0; x < size; x++) {
      for (int y = 0; y < size; y++) {
        ((Case*)layout->itemAtPosition(x,y))->updateColor(matrixRGB[x][y]);
      }
    }
}

MatrixLayout::~MatrixLayout() { delete layout; }
