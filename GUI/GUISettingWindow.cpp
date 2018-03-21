#include "GUISettingWindow.hpp"

GUISettingWindow::GUISettingWindow(QWidget *parent) : QDialog(parent){
    finishButton = new QPushButton("FIN");
    principalWidget = new QWidget;
    mainLayout = new QGridLayout;
    nbAudioSlider = new QSlider;
    nbAnalogSlider = new QSlider;

    finishButton->setDefault(true);
    connect(finishButton, SIGNAL(clicked()), this, SLOT(accept()));

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
