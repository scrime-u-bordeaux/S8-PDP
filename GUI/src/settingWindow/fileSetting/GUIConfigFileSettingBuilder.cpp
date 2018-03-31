/**
 * @file GUIConfigFileSettingBuilder.cpp
 * @author Lucas VIVAS
*/

#include "GUIConfigFileSettingBuilder.hpp"

GUIConfigFileSettingBuilder::GUIConfigFileSettingBuilder()
    : fileBuffer(new string()) {}

void GUIConfigFileSettingBuilder::beginFile() {
  fileBuffer << "# Configuration file for ./VisualImpro\n
#use '#' at beginning of line for comments\n "
}

void GUIConfigFileSettingBuilder::addPort(int port) { fillBuffer << "PORT "; }

void GUIConfigFileSettingBuilder::addAddress(string address) {
  fillBuffer << "ADDRESS ";
}

void GUIConfigFileSettingBuilder::addProcessLen(int length) {
  fillBuffer << "PROCESSLEN ";
}

void GUIConfigFileSettingBuilder::addEffect(bool effect, int bufferLen) {
  fillBuffer << "EFFECTS ";
  fillBuffer << "EFFECT_BUFFER_LEN ";
}

void GUIConfigFileSettingBuilder::addAnalogInput(int nb) {
  fillBuffer << "ANALOG ";
}

void GUIConfigFileSettingBuilder::addAudioInput(int nb) {
  fillBuffer << "AUDIO ";
}

void GUIConfigFileSettingBuilder::addWavFile(string path) {
  fillBuffer << "FILE ";
}

void GUIConfigFileSettingBuilder::addColorFunction(string functionName) {
  fillBuffer << "COLOR ";
}

void GUIConfigFileSettingBuilder::addCoeffFunction(string functionName) {
  fillBuffer << "COEFF ";
}

void GUIConfigFileSettingBuilder::addPreProcFunction(string functionName) {
  fillBuffer << "PREPROC ";
}

void GUIConfigFileSettingBuilder::addMixFunction(string functionName) {
  fillBuffer << "MIX ";
}

void GUIConfigFileSettingBuilder::endFile() {}

string GUIConfigFileSettingBuilder::getResult() { return fillBuffer; }

GUIConfigFileSettingBuilder::~GUIConfigFileSettingBuilder() {
  delete fileBuffer;
}
