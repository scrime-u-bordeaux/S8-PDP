/**
 * @file GUIWavFileLayout.cpp
 * @author Lucas VIVAS
*/

#include "GUIWavFileLayout.hpp"

#include <QString>
#include <iostream>
#include <Qt>
#include <dirent.h>
#include <string>

GUIWavFileLayout::GUIWavFileLayout(QWidget *parent) : QGridLayout(parent) {
  fileDialog = new QFileDialog();
  loadButton = new QPushButton("Load");
  removeButton = new QPushButton("Remove");
  wavFilesLabel = new QLabel(tr("Wav file:"));
  wavFilesText = new QTextEdit();
  filesName = new vector<QString *>();

  loadButton->setToolTip("Load a .wav file");
  connect(loadButton, SIGNAL(clicked()), this, SLOT(loadWavFile()));

  wavFilesText->setReadOnly(true);


  this->addWidget(wavFilesLabel, 0, 0, Qt::AlignTop);
  this->addWidget(wavFilesText, 0, 1);
  this->addWidget(loadButton, 1, 0);
  this->addWidget(removeButton, 1, 1);
}

void GUIWavFileLayout::loadWavFile() {
  QString filename = fileDialog->getOpenFileName(
      NULL, "Choisir un fichier wav", "/",
      "WAV files (*.wav*)");
      if (filename != NULL) {
          string str = filename.toStdString();
          filesName->push_back(&filename);
          wavFilesText->append((str.substr(str.find_last_of("/") + 1).c_str()));
      }
}
GUIWavFileLayout::~GUIWavFileLayout() {
  delete(fileDialog);
  delete(loadButton);
  delete(removeButton);
  delete(wavFilesLabel);
  delete(wavFilesText);

}
