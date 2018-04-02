/**
 * @file GUISettingWindow.cpp
 * @author Lucas VIVAS
*/

#include "GUISettingWindow.hpp"

#include <QPalette>
#include <iostream>
#include <string>

#include "GUIConfigFileSettingBuilder.hpp"
#include "GUISettingLayoutFactory.hpp"

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
  connect(finishButton, SIGNAL(clicked()), this, SLOT(checkInput()));

  finishLabel->setAlignment(Qt::AlignCenter);

  mainLayout->addLayout(inputSettingLayout, 0);
  mainLayout->addLayout(processSettingLayout, 1);
  mainLayout->addLayout(wavFileLayout, 2);
  mainLayout->addWidget(finishLabel, 3);
  mainLayout->addWidget(finishButton, 4);
  setLayout(mainLayout);
}


void GUISettingWindow::checkInput() {
  int nbInput = getNumInput();
  if (nbInput < MIN_ENTRIES) {
    /*color the label text*/
    QPalette sample_palette;
    sample_palette.setColor(QPalette::WindowText, Qt::red);
    finishLabel->setAutoFillBackground(true);
    finishLabel->setPalette(sample_palette);
    finishLabel->setText("Minimum number of entries is 2");
  } else {
    buildConfigFile();
    done(nbInput);
  }
}

void GUISettingWindow::buildConfigFile() {
  QStringList inputList = inputSettingLayout->getSetting();
  QStringList processList = processSettingLayout->getSetting();
  QStringList wavList = wavFileLayout->getSetting();
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

int GUISettingWindow::getNumInput() {
  int nbInput = 0;
  QStringList inputList = inputSettingLayout->getSetting();
  for (int i = 0; i < inputList.size(); i++) {
    nbInput += inputList.at(i).toInt();
  }

  nbInput += wavFileLayout->getSetting().size();
  return nbInput;
}

GUISettingWindow::~GUISettingWindow() {
  delete (finishButton);
  delete (wavFileLayout);
  delete (inputSettingLayout);
  delete (processSettingLayout);
  delete (mainLayout);
}
