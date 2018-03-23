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
  allBox = new vector<QComboBox *>();
}

void GUIProcessSettingLayout::addSetting(string name) {
  allBox->push_back(new QComboBox());
  vector<string> str = getFilename(name);
  for (unsigned i = 0; i < str.size(); i++) {
    allBox->back()->addItem(str[i].c_str());
  }
  this->addRow(name.c_str(), allBox->back());
}

vector<string> GUIProcessSettingLayout::getFilename(string nameFile) {
  //TODO: check extension
  vector<string> strList;
  DIR *pDIR;
  struct dirent *entry;
  if ((pDIR = opendir("../VisualImpro/process/")) != NULL) {
    while ((entry = readdir(pDIR)) != NULL) {
      string name = entry->d_name;
      /*Check if the filename begin by nameFile*/
      if (name.compare(0, nameFile.size(), nameFile) == 0 &&
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

GUIProcessSettingLayout::~GUIProcessSettingLayout() {
    for (size_t i = 0; i < allBox->size(); i++) {
        //delete (allBox->pull_back);
    }
    delete allBox;
}
