/**
 * @file GUIConfigFileSettingBuilder.cpp
 * @author Lucas VIVAS
*/

#include "GUIConfigFileSettingBuilder.hpp"

GUIConfigFileSettingBuilder::GUIConfigFileSettingBuilder()
    : fileBuffer(new stringstream()) {}

void GUIConfigFileSettingBuilder::beginFile() {
  string str("# Configuration file for ./VisualImpro\n #use \'#\' at beginning of line for comments\n ");
  *fileBuffer << str;
}

void GUIConfigFileSettingBuilder::addPort(int port) {
  string str("PORT " + port);
  *fileBuffer << str;
}

void GUIConfigFileSettingBuilder::addAddress(string address) {
  string str("ADDRESS " + address);
  *fileBuffer << str;
}

void GUIConfigFileSettingBuilder::addProcessLen(int length) {
  string str("PROCESSLEN " + length);
  *fileBuffer << str;
}

void GUIConfigFileSettingBuilder::addEffect(bool effect, int bufferLen) {
  string str("EFFECTS " + effect);
  *fileBuffer << str;
  str = "EFFECT_BUFFER_LEN " + bufferLen;
  *fileBuffer << str;
}

void GUIConfigFileSettingBuilder::addAnalogInput(int nb) {
  string str("ANALOG " + nb);
  *fileBuffer << str;
}

void GUIConfigFileSettingBuilder::addAudioInput(int nb) {
  string str("AUDIO " + nb);
  *fileBuffer << str;
}

void GUIConfigFileSettingBuilder::addWavFile(string path) {
  string str("FILE " + path);
  *fileBuffer << str;
}

void GUIConfigFileSettingBuilder::addColorFunction(string functionName) {
  string str("COLOR " + functionName);
  *fileBuffer << str;
}

void GUIConfigFileSettingBuilder::addCoeffFunction(string functionName) {
  string str("COEFF " + functionName);
  *fileBuffer << str;
}

void GUIConfigFileSettingBuilder::addPreProcFunction(string functionName) {
  string str("PREPROC " + functionName);
  *fileBuffer << str;
}

void GUIConfigFileSettingBuilder::addMixFunction(string functionName) {
  string str("MIX " + functionName);
  *fileBuffer << str;
}

void GUIConfigFileSettingBuilder::endFile() {}

 string GUIConfigFileSettingBuilder::getResult() { return fileBuffer->str(); }

GUIConfigFileSettingBuilder::~GUIConfigFileSettingBuilder() {
  delete fileBuffer;
}
