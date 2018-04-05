/**
 * \file GUISettingWindow.cpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#include <QPalette>
#include <string>
#include <fstream>

#include "GUIConfigFileSettingBuilder.hpp"
#include "GUISettingLayoutFactory.hpp"
#include "GUISettingWindow.hpp"

/**
 * \fn GUISettingWindow(QWidget *parent)
 * \brief Constructor for GUISettingWindow class.
 *
 * \param parent the parent of this layout.
 */
GUISettingWindow::GUISettingWindow(QWidget *parent) : QDialog(parent) {
  finishButton = new QPushButton("FIN");
  finishLabel = new QLabel();
  mainLayout = new QVBoxLayout(this);

  /*get all the layouts*/
  processSettingLayout =
      GUISettingLayoutFactory::createGUIProcessSettingLayout();
  inputSettingLayout = GUISettingLayoutFactory::createGUIInputSettingLayout();
  wavFileLayout = GUISettingLayoutFactory::createGUIWavFileSettingLayout();

  /*set differents parts of the process layout*/
  processSettingLayout->addSetting("Coeff");
  processSettingLayout->addSetting("Preproc");
  processSettingLayout->addSetting("Color");
  processSettingLayout->addSetting("Mix");

  /*set differents parts of the input  layout*/
  inputSettingLayout->addSetting("Number of audio input", MIN_AUDIO_INPUT,
                                 MAX_AUDIO_INPUT);
  inputSettingLayout->addSetting("Number of analog input", MIN_ANALOG_INPUT,
                                 MAX_ANALOG_INPUT);

  /*set the settings of finish button*/
  finishButton->setDefault(true);
  connect(finishButton, SIGNAL(clicked()), this, SLOT(checkInput()));

  /*set the settings of finish label*/
  finishLabel->setAlignment(Qt::AlignCenter);

  /*add all the layout in a global layout*/
  mainLayout->addLayout(inputSettingLayout, 0);
  mainLayout->addLayout(processSettingLayout, 1);
  mainLayout->addLayout(wavFileLayout, 2);
  mainLayout->addWidget(finishLabel, 3);
  mainLayout->addWidget(finishButton, 4);

  /*add the global layout to this window*/
  setLayout(mainLayout);
}

/**
 * \fn checkInput()
 * \brief Check if the number of inputs more then MIN_ENTRIES if it is not
 * print on the window a error message else build the config file and close
 * this window return the number of inputs.
 *
 * \param
 */
void GUISettingWindow::checkInput() {
  int nbInput = getNumInput();
  /*print an error*/
  if (nbInput < MIN_ENTRIES) {
    /*color the label text*/
    QPalette sample_palette;
    sample_palette.setColor(QPalette::WindowText, Qt::red);
    finishLabel->setAutoFillBackground(true);
    finishLabel->setPalette(sample_palette);
    string str = "Minimum number of entries is ";
    str += to_string(MIN_ENTRIES);
    finishLabel->setText(str.c_str());
    /*build and exit*/
  } else {
    buildConfigFile();
    done(nbInput);
  }
}

/**
 * \fn buildConfigFile()
 * \brief Get all the settings and build the config file with its.
 *
 * \param
 */
void GUISettingWindow::buildConfigFile() {
  /*get all the settings*/
  QStringList inputList = inputSettingLayout->getSettings();
  QStringList processList = processSettingLayout->getSettings();
  QStringList wavList = wavFileLayout->getSettings();
  GUIConfigFileSettingBuilder builder;
  /*call all the function to builde the config file*/
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
  /*create the config file*/
  string fileStr = builder.getResult();
  ofstream configFile;
  configFile.open("./config_qt.cfg");
  configFile << fileStr;
  configFile.close();

}

/**
 * \fn getNumInput()
 * \brief Return the number of input which are the number of audio, analog
 * inputs and the number of wav files.
 *
 * \param
 */
int GUISettingWindow::getNumInput() {
  int nbInput = 0;
  /*get the number of inputs*/
  QStringList inputList = inputSettingLayout->getSettings();
  for (int i = 0; i < inputList.size(); i++) {
    nbInput += inputList.at(i).toInt();
  }

  /*get the number of wav files*/
  nbInput += wavFileLayout->getSettings().size();
  return nbInput;
}

/**
 * \fn ~GUISettingWindow()
 * \brief Destructor for GUISettingWindow class.
 *
 * \param
 */
GUISettingWindow::~GUISettingWindow() {
  delete (finishButton);
  delete (wavFileLayout);
  delete (inputSettingLayout);
  delete (processSettingLayout);
  delete (mainLayout);
}
