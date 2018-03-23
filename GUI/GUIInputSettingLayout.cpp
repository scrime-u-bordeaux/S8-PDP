/**
 * @file GUIInputSettingLayout.cpp
 * @author Lucas VIVAS
*/

#include "GUIInputSettingLayout.hpp"

#include <Qt>

GUIInputSettingLayout::GUIInputSettingLayout(QWidget *parent) : QGridLayout(parent){
  allLabel = new vector<QLabel *>();
  allSlider = new vector<QSlider *>();
  allSpinBox = new vector<QSpinBox *>();
}

void GUIInputSettingLayout::addSetting(string name, int min, int max){
  allLabel->push_back(new QLabel(name.c_str()));
  allSlider->push_back(new QSlider(Qt::Horizontal));
  allSpinBox->push_back(new QSpinBox());

  allSlider->back()->setMinimum(min);
  allSlider->back()->setMaximum(max);

  allSpinBox->back()->setMinimum(min);
  allSpinBox->back()->setMaximum(max);

  connect(allSlider->back(), SIGNAL(valueChanged(int)), allSpinBox->back(), SLOT(setValue(int)));
  connect(allSpinBox->back(), SIGNAL(valueChanged(int)), allSlider->back(), SLOT(setValue(int)));

  int pos = allLabel->size();
  addWidget(allLabel->back(), (pos - 1) * 2, 0);
  addWidget(allSlider->back(), pos + pos - 1, 0);
  addWidget(allSpinBox->back(), pos + pos - 1, 1);
}

GUIInputSettingLayout::~GUIInputSettingLayout(){

}
