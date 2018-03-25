/**
 * @file GUIWavFileLayout.hpp
 * @author Lucas VIVAS
*/

#include "GUIWavFileLayout.hpp"

#include <QString>
#include <iostream>
#include <Qt>

GUIWavFileLayout::GUIWavFileLayout(QWidget *parent) : QGridLayout(parent) {
  fileDialog = new QFileDialog();
  loadButton = new QPushButton("Load");
  loadButton->setToolTip("Load a .wav file");
  connect(loadButton, SIGNAL(clicked()), this, SLOT(loadWavFile()));

  wavFilesLabel = new QLabel(tr("Wav file:"));
  wavFilesText = new QTextEdit;
  wavFilesText->setReadOnly(true);

  this->addWidget(wavFilesLabel, 0, 0, Qt::AlignTop);
  this->addWidget(wavFilesText, 0, 1);
  this->addWidget(loadButton, 1, 0);
}

void GUIWavFileLayout::loadWavFile() {
  cout << "cacasa" << endl;
  QString filename = fileDialog->getOpenFileName(
      NULL, "Choisir un fichier wav", "/",
      "WAV files (*.wav*)"); // comprends pas NULL et pas this
}
GUIWavFileLayout::~GUIWavFileLayout() {}
