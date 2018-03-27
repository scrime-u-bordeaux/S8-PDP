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
  QVector<string> str = getFilename(name);
  for (int i = 0; i < str.size(); i++) {
    allBox->back()->addItem(str[i].c_str());
  }
  this->addRow(name.c_str(), allBox->back());
}

QVector<string> GUIProcessSettingLayout::getFilename(string nameFile) {
  QVector<string> strList;
  DIR *pDIR;
  struct dirent *entry;
  /*open the directory in pDIR*/
  if ((pDIR = opendir("../VisualImpro/process/")) != NULL) {
    while ((entry = readdir(pDIR)) != NULL) {
      string name = entry->d_name;
      /*Check if the filename begins by nameFile*/
      if (name.compare(0, nameFile.size(), nameFile) == 0 &&
      /*check if the extension is ".cpp"*/
      name.substr(name.find_last_of(".") + 1) == "cpp") {
        /*delete the extension*/
        name = name.substr(0, name.find(".cpp"));
        strList.push_back(name);
      }
    }
    closedir(pDIR);
  }
  return strList;
}

#include <typeinfo>

GUIProcessSettingLayout::~GUIProcessSettingLayout() {
    cout << "processSettingLayout is deleting" << endl;
    QComboBox* box;
    while ( !allBox->isEmpty() && ( (box = allBox->first()) != 0 )) {
        allBox->remove(0);
        delete (box);
    }
    allBox->clear();
}
