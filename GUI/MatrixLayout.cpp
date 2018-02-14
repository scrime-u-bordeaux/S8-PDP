#include "MatrixLayout.hpp"

MatrixLayout::MatrixLayout(QWidget* parent) :QWidget(parent), layout(this){
    setLayout(&layout);
}

void MatrixLayout::addWidget(QWidget *widget, int x, int y){
    layout.addWidget(widget,x,y);
}

MatrixLayout::~MatrixLayout(){

}
