/**
 * @file GUISettingWindow.cpp
 * @author Lucas VIVAS
*/
#include "GUISettingWindow.hpp"
#include <iostream>

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

    inputSettingLayout->addSetting("Number of audio input", 0, 2);
    inputSettingLayout->addSetting("Number of analog input", 0, 8);

    finishButton->setDefault(true);
    connect(finishButton, SIGNAL(clicked()), this, SLOT(accept()));

    mainLayout->addLayout(inputSettingLayout, 0);
    mainLayout->addLayout(processSettingLayout, 1);
    mainLayout->addLayout(wavFileLayout, 2);
    mainLayout->addWidget(finishButton, 3);
    setLayout(mainLayout);
}

GUISettingWindow::~GUISettingWindow(){
    cout << "finishButton" << endl;
    delete(finishButton);
    cout << "wavFileLayout" << endl;
    delete(wavFileLayout);
    cout << "inputSettingLayout" << endl;
    delete(inputSettingLayout);
    cout << "processSettingLayout" << endl;
    delete(processSettingLayout);
    cout << "mainLayout" << endl;
    delete(mainLayout);
}
