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
    nbAudioSlider = new QSlider(Qt::Horizontal, this);
    nbAnalogSlider = new QSlider(Qt::Horizontal, this);

    finishButton->setDefault(true);
    connect(finishButton, SIGNAL(clicked()), this, SLOT(accept()));

    nbAudioSlider->setTickInterval(2);

    mainLayout->addWidget(nbAudioSlider, 0, 0);
    mainLayout->addWidget(nbAnalogSlider, 1, 0);
    mainLayout->addWidget(finishButton, 1, 1);
    setLayout(mainLayout);
}

GUISettingWindow::~GUISettingWindow(){
    delete(finishButton);
    delete(principalWidget);
    delete(mainLayout);
    delete(nbAudioSlider);
    delete(nbAnalogSlider);
}
