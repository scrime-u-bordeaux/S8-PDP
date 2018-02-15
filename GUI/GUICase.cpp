#include "GUICase.hpp"

#include <QPainter>

Case::Case(int x, int y, QWidget *parent) : QWidget(parent) {
  rect = new QRect(x, y, SQUARE_SIZE, SQUARE_SIZE);
  color = new QColor(Qt::black);
  resize(SQUARE_SIZE, SQUARE_SIZE);
}

void Case::updateColor(RGB rgb) {
  color->setRgb(rgb.getRed(), rgb.getGreen(), rgb.getBlue());
}

void Case::paintEvent(QPaintEvent *event) {
  QPainter *painter = new QPainter(this);
  painter->setBrush(*color);
  painter->drawRect(*rect);
  delete painter;
}

Case::~Case() {
  delete rect;
  delete color;
}
