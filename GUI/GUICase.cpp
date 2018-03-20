#include "GUICase.hpp"



Case::Case(int x, int y, QWidget *parent) : QWidget(parent) {
  QPainter painter();
  rect = new QRect(x, y, SQUARE_SIZE, SQUARE_SIZE);
  color = new QColor(Qt::green);
  resize(SQUARE_SIZE, SQUARE_SIZE);
}

void Case::updateColor(RGB rgb) {
  color->setRgb(rgb.getRed(), rgb.getGreen(), rgb.getBlue());
}

void Case::paintEvent(QPaintEvent *event) {
  painter.begin(this);
  //painter.setBrush(*color);
  painter.drawRect(*rect);
  painter.fillRect(*rect, * color);
  painter.end();
}

Case::~Case() {
  delete rect;
  delete color;
}
