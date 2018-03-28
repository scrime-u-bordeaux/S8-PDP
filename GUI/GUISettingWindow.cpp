/**
 * @file GUISettingWindow.cpp
 * @author Lucas VIVAS
*/
#include "GUISettingWindow.hpp"

#include <iostream>

#include "GUISettingLayoutFactory.hpp"

GUISettingWindow::GUISettingWindow(QWidget *parent) : QDialog(parent){
    finishButton = new QPushButton("FIN");
    mainLayout = new QVBoxLayout(this);

    processSettingLayout = GUISettingLayoutFactory::createGUIProcessSettingLayout();
    inputSettingLayout = GUISettingLayoutFactory::createGUIInputSettingLayout();
    wavFileLayout = GUISettingLayoutFactory::createGUIWavFileSettingLayout();

    processSettingLayout->addSetting("Coeff");
    processSettingLayout->addSetting("Preproc");
    processSettingLayout->addSetting("Color");
    processSettingLayout->addSetting("Mix");

    inputSettingLayout->addSetting("Number of audio input", 0, 2);
    inputSettingLayout->addSetting("Number of analog input", 0, 8);

    finishButton->setDefault(true);
    connect(finishButton, SIGNAL(clicked()), this, SLOT(getParam()));
    connect(finishButton, SIGNAL(clicked()), this, SLOT(accept()));


    mainLayout->addLayout(inputSettingLayout, 0);
    mainLayout->addLayout(processSettingLayout, 1);
    mainLayout->addLayout(wavFileLayout, 2);
    mainLayout->addWidget(finishButton, 3);
    setLayout(mainLayout);
}

void GUISettingWindow::getParam(){
    QStringList inputList = inputSettingLayout->getSetting();
    for (int i = 0; i < inputList.size(); i++) {
        cout << inputList.at(i).toStdString() << endl;
    }

    QStringList processList = processSettingLayout->getSetting();
    for (int i = 0; i < processList.size(); i++) {
        cout << processList.at(i).toStdString() << endl;
    }
    cout << endl;
    QStringList wavList = wavFileLayout->getSetting();
    for (int i = 0; i < wavList.size(); i++) {
        cout << wavList.at(i).toStdString() << endl;
    }
}

GUISettingWindow::~GUISettingWindow(){
    delete(finishButton);
    delete(wavFileLayout);
    delete(inputSettingLayout);
    delete(processSettingLayout);
    delete(mainLayout);
}
