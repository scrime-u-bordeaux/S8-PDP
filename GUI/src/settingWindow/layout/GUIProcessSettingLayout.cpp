/**
 * @file GUIProcessSettingLayout.cpp
 * @author Lucas VIVAS
*/

#include <dirent.h>
#include <iostream>
#include <string>

#include "GUIProcessSettingLayout.hpp"

GUIProcessSettingLayout::GUIProcessSettingLayout(QWidget *parent)
    : QFormLayout(parent) {
  allBox = new QVector<QComboBox *>();
}

void GUIProcessSettingLayout::addSetting(string name) {
  allBox->push_back(new QComboBox(this->parentWidget()));
  QStringList str = getFilename(name);
  for (int i = 0; i < str.size(); i++) {
    allBox->back()->addItem(str[i]);
  }
  this->addRow(name.c_str(), allBox->back());
}

const QStringList GUIProcessSettingLayout::getSetting(){
  QStringList str;
  for (int i = 0; i < allBox->size(); i++) {
    str << allBox->at(i)->currentText();
  }
  return str;
}

QStringList GUIProcessSettingLayout::getFilename(string nameFile) {
  QStringList strList;
  DIR *pDIR;
  string str = "../VisualImpro/process/" + nameFile + "/";
  struct dirent *entry;
  /*open the directory in pDIR*/
  if ((pDIR = opendir(str.c_str())) != NULL) {
    while ((entry = readdir(pDIR)) != NULL) {
      string name = entry->d_name;
      /*Check if the filename begins by nameFile*/
      if (name.compare(0, nameFile.size(), nameFile) == 0 &&
      /*check if the extension is ".cpp"*/
      name.substr(name.find_last_of(".") + 1) == "cpp") {
        /*delete the extension*/
        name = name.substr(0, name.find(".cpp"));
        strList << QString::fromStdString(name);
      }
    }
    closedir(pDIR);
  }
  return strList;
}

GUIProcessSettingLayout::~GUIProcessSettingLayout() {
    QComboBox* box;
    while ( !allBox->isEmpty() && ( (box = allBox->first()) != 0 )) {
        allBox->remove(0);
        delete (box);
    }
    allBox->clear();
}
