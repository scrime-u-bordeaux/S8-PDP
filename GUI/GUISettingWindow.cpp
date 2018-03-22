/**
 * @file GUISettingWindow.cpp
 * @author Lucas VIVAS
*/
#include "GUISettingWindow.hpp"

#include <Qt>

GUISettingWindow::GUISettingWindow(QWidget *parent) : QDialog(parent){
    finishButton = new QPushButton("FIN");
    principalWidget = new QWidget(this);
    mainLayout = new QGridLayout(this);
    nbAudioLabel = new QLabel("Nombre Audio", this);
    nbAnalogLabel = new QLabel("Nombre Analog", this);
    nbAudioSlider = new QSlider(Qt::Horizontal, this);
    nbAnalogSlider = new QSlider(Qt::Horizontal, this);
    nbAudioBox = new QSpinBox(this);
    nbAnalogBox = new QSpinBox(this);

    nbAudioBox->setMinimum(0);
    nbAudioBox->setMaximum(2);

    nbAnalogBox->setMinimum(0);
    nbAnalogBox->setMaximum(8);

    finishButton->setDefault(true);
    connect(finishButton, SIGNAL(clicked()), this, SLOT(accept()));

    nbAudioSlider->setTickInterval(2);

    mainLayout->addWidget(nbAudioLabel, 0, 0);
    mainLayout->addWidget(nbAudioSlider, 1, 0);
    mainLayout->addWidget(nbAudioBox, 1, 1);
    mainLayout->addWidget(nbAnalogLabel, 2, 0);
    mainLayout->addWidget(nbAnalogSlider, 3, 0);
    mainLayout->addWidget(nbAnalogBox, 3, 1);
    mainLayout->addWidget(finishButton, 4, 1);
    setLayout(mainLayout);
}

void setSpinBox(){

}

GUISettingWindow::~GUISettingWindow(){
    delete(finishButton);
    delete(principalWidget);
    delete(mainLayout);
    delete(nbAudioSlider);
    delete(nbAnalogSlider);
}
