/**
 * @file GUIConfigFileSettingBuilder.cpp
 * @author Lucas VIVAS
*/

#include "GUIConfigFileSettingBuilder.hpp"

#include <string>
#include <fstream>

GUIConfigFileSettingBuilder::GUIConfigFileSettingBuilder()
    : fileBuffer(new stringstream()) {}

void GUIConfigFileSettingBuilder::beginFile() {
  string str = "# Configuration file for ./VisualImpro";
  *fileBuffer << str << endl;
}

void GUIConfigFileSettingBuilder::addPort(int port) {
  string str = "PORT " + std::to_string(port);
  *fileBuffer << str << endl;
}

void GUIConfigFileSettingBuilder::addAddress(string address) {
  string str = "ADDRESS " + address;
  *fileBuffer << str << endl;
}

void GUIConfigFileSettingBuilder::addProcessLen(int length) {
  string str = "PROCESSLEN " + std::to_string(length);
  *fileBuffer << str << endl;
}

void GUIConfigFileSettingBuilder::addEffect(bool effect, int bufferLen) {
  string str;
  if (effect)
    str = "EFFECTS Y";
  else
    str = "EFFECTS N";
  *fileBuffer << str << endl;
  str = "EFFECT_BUFFER_LEN " + std::to_string(bufferLen);
  *fileBuffer << str << endl;
}

void GUIConfigFileSettingBuilder::addAnalogInput(int nb) {
  string str = "ANALOG " + std::to_string(nb);
  *fileBuffer << str << endl;
}

void GUIConfigFileSettingBuilder::addAudioInput(int nb) {
  string str = "AUDIO " + std::to_string(nb);
  *fileBuffer << str << endl;
}

void GUIConfigFileSettingBuilder::addWavFile(string path) {
  string str = "FILE " + path;
  *fileBuffer << str << endl;
}

void GUIConfigFileSettingBuilder::addColorFunction(string functionName) {
  string str = "COLOR " + functionName;
  *fileBuffer << str << endl;
}

void GUIConfigFileSettingBuilder::addCoeffFunction(string functionName) {
  string str = "COEFF " + functionName;
  *fileBuffer << str << endl;
}

void GUIConfigFileSettingBuilder::addPreProcFunction(string functionName) {
  string str = "PREPROC " + functionName;
  *fileBuffer << str << endl;
}

void GUIConfigFileSettingBuilder::addMixFunction(string functionName) {
  string str = "MIX " + functionName;
  *fileBuffer << str << endl;
}

void GUIConfigFileSettingBuilder::endFile() {}

string GUIConfigFileSettingBuilder::getResult() {
    ofstream configFile;
    configFile.open ("config.cfg");
    configFile << fileBuffer->str();
    configFile.close();
    return fileBuffer->str();
  }

GUIConfigFileSettingBuilder::~GUIConfigFileSettingBuilder() {
  delete fileBuffer;
}
