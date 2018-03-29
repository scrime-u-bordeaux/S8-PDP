/**
 * @file GUISettingWindow.cpp
 * @author Lucas VIVAS
*/

#include "GUISettingWindow.hpp"

#include <iostream>

#include "GUISettingLayoutFactory.hpp"

#define MIN_ENTRIES 2

#define MIN_AUDIO_INPUT 0
#define MAX_AUDIO_INPUT 2
#define MIN_ANALOG_INPUT 0
#define MAX_ANALOG_INPUT 8

GUISettingWindow::GUISettingWindow(QWidget *parent) : QDialog(parent) {
  finishButton = new QPushButton("FIN");
  mainLayout = new QVBoxLayout(this);

  processSettingLayout =
      GUISettingLayoutFactory::createGUIProcessSettingLayout();
  inputSettingLayout = GUISettingLayoutFactory::createGUIInputSettingLayout();
  wavFileLayout = GUISettingLayoutFactory::createGUIWavFileSettingLayout();

  processSettingLayout->addSetting("Coeff");
  processSettingLayout->addSetting("Preproc");
  processSettingLayout->addSetting("Color");
  processSettingLayout->addSetting("Mix");

  inputSettingLayout->addSetting("Number of audio input", MIN_AUDIO_INPUT,
                                 MAX_AUDIO_INPUT);
  inputSettingLayout->addSetting("Number of analog input", MIN_ANALOG_INPUT,
                                 MAX_ANALOG_INPUT);

  finishButton->setDefault(true);
  connect(finishButton, SIGNAL(clicked()), this, SLOT(getParam()));
  connect(finishButton, SIGNAL(clicked()), this, SLOT(accept()));

  mainLayout->addLayout(inputSettingLayout, 0);
  mainLayout->addLayout(processSettingLayout, 1);
  mainLayout->addLayout(wavFileLayout, 2);
  mainLayout->addWidget(finishButton, 3);
  setLayout(mainLayout);
}

void GUISettingWindow::getParam() {
  int nbInput = 0;
  QStringList inputList = inputSettingLayout->getSetting();
  for (int i = 0; i < inputList.size(); i++) {
    cout << inputList.at(i).toStdString() << endl;
    nbInput += inputList.at(i).toInt();
  }

  QStringList processList = processSettingLayout->getSetting();
  for (int i = 0; i < processList.size(); i++) {
    cout << processList.at(i).toStdString() << endl;
  }
  cout << endl;
  QStringList wavList = wavFileLayout->getSetting();
  for (int i = 0; i < wavList.size(); i++) {
    cout << wavList.at(i).toStdString() << endl;
    nbInput++;
  }
  if (nbInput < MIN_ENTRIES)
    cout << "bad" << endl;
  else
    cout << "good" << endl;
}

GUISettingWindow::~GUISettingWindow() {
  delete (finishButton);
  delete (wavFileLayout);
  delete (inputSettingLayout);
  delete (processSettingLayout);
  delete (mainLayout);
}
