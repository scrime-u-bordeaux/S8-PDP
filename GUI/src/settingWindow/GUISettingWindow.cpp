/**
 * @file GUISettingWindow.cpp
 * @author Lucas VIVAS
*/

#include "GUISettingWindow.hpp"

#include <iostream>

#include "GUIConfigFileSettingBuilder.hpp"
#include "GUISettingLayoutFactory.hpp"

#define MIN_ENTRIES 2

#define MIN_AUDIO_INPUT 0
#define MAX_AUDIO_INPUT 2
#define MIN_ANALOG_INPUT 0
#define MAX_ANALOG_INPUT 8

#define PORT 12345
#define IPADDRESS "192.168.7.1"
#define PROCESSLEN 32768
#define EFFECTBUFFERLEN 32

GUISettingWindow::GUISettingWindow(QWidget *parent) : QDialog(parent) {
  finishButton = new QPushButton("FIN");
  finishLabel = new QLabel();
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
  mainLayout->addWidget(finishLabel, 3);
  mainLayout->addWidget(finishButton, 4);
  setLayout(mainLayout);
}

void GUISettingWindow::getParam() {
  int nbInput = 0;
  QStringList inputList = inputSettingLayout->getSetting();
  for (int i = 0; i < inputList.size(); i++) {
    nbInput += inputList.at(i).toInt();
  }

  QStringList processList = processSettingLayout->getSetting();

  QStringList wavList = wavFileLayout->getSetting();
  nbInput += wavList.size();

  if (nbInput < MIN_ENTRIES)
    finishLabel->setText("bad");
  else {
    GUIConfigFileSettingBuilder builder;
    builder.beginFile();
    builder.addPort(PORT);
    builder.addAddress(IPADDRESS);
    builder.addProcessLen(PROCESSLEN);
    builder.addEffect(false, EFFECTBUFFERLEN);
    builder.addAnalogInput(inputList.at(0).toInt());
    builder.addAudioInput(inputList.at(1).toInt());
    for (int i = 0; i < wavList.size(); i++) {
      builder.addWavFile(wavList.at(i).toStdString());
    }
    builder.addCoeffFunction(processList.at(0).toStdString());
    builder.addPreProcFunction(processList.at(1).toStdString());
    builder.addColorFunction(processList.at(2).toStdString());
    builder.addMixFunction(processList.at(3).toStdString());
    builder.endFile();
    cout << builder.getResult() << endl;
  }
}

GUISettingWindow::~GUISettingWindow() {
  delete (finishButton);
  delete (wavFileLayout);
  delete (inputSettingLayout);
  delete (processSettingLayout);
  delete (mainLayout);
}
