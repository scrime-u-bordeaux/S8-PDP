/**
 * \file GUIInputSettingLayout.cpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#include <Qt>
#include "GUIInputSettingLayout.hpp"


template class QVector<QLabel *>;
template class QVector<QSlider *>;
template class QVector<QSpinBox *>;

GUIInputSettingLayout::GUIInputSettingLayout(QWidget *parent) :
  QGridLayout(parent),
  allLabel(new QVector<QLabel *>()),
  allSlider(new QVector<QSlider *>()),
  allSpinBox(new QVector<QSpinBox *>())
{}

void GUIInputSettingLayout::addSetting(string name, int min, int max){
  allLabel->push_back(new QLabel(name.c_str()));
  allSlider->push_back(new QSlider(Qt::Horizontal));
  allSpinBox->push_back(new QSpinBox());

  /*set the minimum and maximum of the slider*/
  allSlider->back()->setMinimum(min);
  allSlider->back()->setMaximum(max);
  /*set the minimum and maximum of the box*/
  allSpinBox->back()->setMinimum(min);
  allSpinBox->back()->setMaximum(max);

  connect(allSlider->back(), SIGNAL(valueChanged(int)), allSpinBox->back(), SLOT(setValue(int)));
  connect(allSpinBox->back(), SIGNAL(valueChanged(int)), allSlider->back(), SLOT(setValue(int)));

  int pos = allLabel->size();
  addWidget(allLabel->back(), (pos - 1) * 2, 0);
  addWidget(allSlider->back(), pos + pos - 1, 0);
  addWidget(allSpinBox->back(), pos + pos - 1, 1);
}

const QStringList GUIInputSettingLayout::getSettings(){
    QStringList strList;
    for (int i = 0; i < allSpinBox->size(); i++) {
      strList << QString::number((allSpinBox->at(i))->value());
    }
    return strList;
}

GUIInputSettingLayout::~GUIInputSettingLayout(){
    QLabel* label;
    while ( !allLabel->isEmpty() && ( (label = allLabel->first()) != 0 )) {
        allLabel->remove(0);
        delete (label);
    }
    allLabel->clear();

    QSlider* slider;
    while ( !allSlider->isEmpty() && ( (slider = allSlider->first()) != 0 )) {
        allSlider->remove(0);
        delete (slider);
    }
    allSlider->clear();

    QSpinBox* box;
    while ( !allSpinBox->isEmpty() && ( (box = allSpinBox->first()) != 0 )) {
        allSpinBox->remove(0);
        delete (box);
    }
    allSpinBox->clear();

    delete(allLabel);
    delete(allSlider);
    delete(allSpinBox);
}
