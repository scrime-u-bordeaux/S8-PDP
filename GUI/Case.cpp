#include "Case.hpp"

#include <QPainter>

Case::Case(int x, int y, QWidget* parent) :
 QWidget(parent), rect(x,y,SQUARE_SIZE,SQUARE_SIZE), color(Qt::black) {

 }

void Case::updateColor(RGB rgb) {
    color.setRgb(rgb.getRed(), rgb.getGreen(), rgb.getBlue());
}

void Case::paintEvent(QPaintEvent * event){
    QPainter painter(this);
    painter.setBrush(color);
    painter.drawRect(rect);
}

Case::~Case() {}
