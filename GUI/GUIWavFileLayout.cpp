/**
 * @file GUIWavFileLayout.cpp
 * @author Lucas VIVAS
*/

#include "GUIWavFileLayout.hpp"

#include <QString>
#include <dirent.h>
#include <iostream>
#include <string>


GUIWavFileLayout::GUIWavFileLayout(QWidget *parent) : QGridLayout(parent) {
  fileDialog = new QFileDialog();
  loadButton = new QPushButton("Load");
  removeButton = new QPushButton("Remove");
  wavFilesLabel = new QLabel("Wav file:");

  nameFile = new QStringList();
  nameFileModel = new QStringListModel(*nameFile);
  listView = new QListView();

  listView->setEditTriggers(QListView::NoEditTriggers);
  listView->setModel(nameFileModel);

  loadButton->setToolTip("Load a .wav file");
  connect(loadButton, SIGNAL(clicked()), this, SLOT(loadWavFile()));
  connect(removeButton, SIGNAL(clicked()), this, SLOT(removeWavFile()));

  this->addWidget(wavFilesLabel, 0, 0, Qt::AlignTop);
  this->addWidget(listView, 0, 1);
  this->addWidget(loadButton, 1, 0);
  this->addWidget(removeButton, 1, 1);
}

void GUIWavFileLayout::loadWavFile() {
  QString filename = fileDialog->getOpenFileName(NULL, "Choisir un fichier wav",
                                                 "/", "WAV files (*.wav*)");
  if (filename != NULL) {
    /*add the path of the file to the nameFile list*/
    *nameFile << filename;

    /*get the name of the file without the absolut path*/
    string str = filename.toStdString();
    str = str.substr(str.find_last_of("/") + 1);
    /*add a new item (row) in the view with the name of the file inside*/
    int ind = nameFileModel->rowCount();
    nameFileModel->insertRow(ind);
    nameFileModel->setData(nameFileModel->index(ind), str.c_str());
  }
}

void GUIWavFileLayout::removeWavFile() {
  cout << "remove" << endl;
}

GUIWavFileLayout::~GUIWavFileLayout() {
  delete (fileDialog);
  delete (loadButton);
  delete (removeButton);
  delete (wavFilesLabel);
  delete (listView);
  delete (nameFileModel);
  delete (nameFile);
}
