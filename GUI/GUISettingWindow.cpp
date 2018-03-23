/**
 * @file GUISettingWindow.cpp
 * @author Lucas VIVAS
*/
#include "GUISettingWindow.hpp"

GUISettingWindow::GUISettingWindow(QWidget *parent) : QDialog(parent){
    finishButton = new QPushButton("FIN");
    mainLayout = new QVBoxLayout(this);
    processSettingLayout = new GUIProcessSettingLayout();
    inputSettingLayout = new GUIInputSettingLayout();
    wavFileLayout = new GUIWavFileLayout();

    processSettingLayout->addSetting("Coeff");
    processSettingLayout->addSetting("Preproc");
    processSettingLayout->addSetting("Color");
    processSettingLayout->addSetting("Mix");

    inputSettingLayout->addSetting("Nombre d\'entrees audio", 0, 2);
    inputSettingLayout->addSetting("Nombre d\'entrees analogique", 0, 8);

    finishButton->setDefault(true);
    connect(finishButton, SIGNAL(clicked()), this, SLOT(accept()));

    mainLayout->addLayout(inputSettingLayout, 0);
    mainLayout->addLayout(processSettingLayout, 1);
    mainLayout->addLayout(wavFileLayout, 2);
    mainLayout->addWidget(finishButton, 3);
    setLayout(mainLayout);
}

GUISettingWindow::~GUISettingWindow(){
    delete(finishButton);
    delete(mainLayout);
    delete(processSettingLayout);
    delete(inputSettingLayout);
}
