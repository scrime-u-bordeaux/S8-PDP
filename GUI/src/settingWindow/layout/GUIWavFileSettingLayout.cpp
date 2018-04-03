/**
 * @file GUIWavFileSettingLayout.cpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#include "GUIWavFileSettingLayout.hpp"

#include <QString>
#include <dirent.h>
#include <string>

GUIWavFileSettingLayout::GUIWavFileSettingLayout(QWidget *parent) : QGridLayout(parent) {
  leftLayout = new QVBoxLayout();

  fileDialog = new QFileDialog();
  loadButton = new QPushButton("Load");
  removeButton = new QPushButton("Remove");
  clearButton = new QPushButton("Clear");
  wavFilesLabel = new QLabel("Wav file:");

  nameFile = new QStringList();
  nameFileModel = new QStringListModel(*nameFile);
  listView = new QListView();

  listView->setEditTriggers(QListView::NoEditTriggers);
  listView->setModel(nameFileModel);

  loadButton->setToolTip("Load a .wav file");
  connect(loadButton, SIGNAL(clicked()), this, SLOT(loadWavFile()));
  connect(removeButton, SIGNAL(clicked()), this, SLOT(removeWavFile()));
  connect(clearButton, SIGNAL(clicked()), this, SLOT(clearWavFile()));

  leftLayout->addWidget(wavFilesLabel, 0, Qt::AlignTop);
  leftLayout->addWidget(loadButton, 1);
  leftLayout->addWidget(removeButton, 2);
  leftLayout->addWidget(clearButton, 3);

  this->addLayout(leftLayout, 0, 0);
  this->addWidget(listView, 0, 1);
}

const QStringList GUIWavFileSettingLayout::getSettings() { return *nameFile; }

void GUIWavFileSettingLayout::loadWavFile() {
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

void GUIWavFileSettingLayout::removeWavFile() {
  // remove from the list
  int ind = listView->currentIndex().row();
  nameFile->removeAt(ind);
  nameFileModel->removeRow(ind);
}

void GUIWavFileSettingLayout::clearWavFile() {
  // remove everything from the list
  // int ind = listView->currentIndex().row();
  while (!nameFile->isEmpty()){
    nameFile->removeFirst();
    nameFileModel->removeRow(0);
  }
}

GUIWavFileSettingLayout::~GUIWavFileSettingLayout() {
  delete (fileDialog);
  delete (loadButton);
  delete (removeButton);
  delete (wavFilesLabel);
  delete (listView);
  delete (nameFileModel);
  delete (nameFile);
}
