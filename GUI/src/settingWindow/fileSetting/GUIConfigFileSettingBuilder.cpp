/**
 * @file GUIConfigFileSettingBuilder.cpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#include "GUIConfigFileSettingBuilder.hpp"

#include <fstream>
#include <string>

/**
 * @fn GUIConfigFileSettingBuilder()
 * @brief Constructor for GUIConfigFileSettingBuilder class.
 *
 * @param
 */
GUIConfigFileSettingBuilder::GUIConfigFileSettingBuilder()
    : fileBuffer(new stringstream()) {}

/**
 * @fn beginFile()
 * @brief add the begin of the config file.
 *
 * @param
 */
void GUIConfigFileSettingBuilder::beginFile() {
  string str = "# Configuration file for ./VisualImpro";
  *fileBuffer << str << endl;
}

/**
 * @fn addPort(int port)
 * @brief add the port in the config file.
 *
 * @param port
 */
void GUIConfigFileSettingBuilder::addPort(int port) {
  string str = "PORT " + std::to_string(port);
  *fileBuffer << str << endl;
}

/**
 * @fn addAddress(string address)
 * @brief add the ip address to the config file.
 *
 * @param address ip address for the server.
 */
void GUIConfigFileSettingBuilder::addAddress(string address) {
  string str = "ADDRESS " + address;
  *fileBuffer << str << endl;
}

/**
 * @fn addProcessLen(int length)
 * @brief add the process buffer length to the onfig file.
 *
 * @param length Buffer process length.
 */
void GUIConfigFileSettingBuilder::addProcessLen(int length) {
  string str = "PROCESSLEN " + std::to_string(length);
  *fileBuffer << str << endl;
}

/**
 * @fn addEffect(bool effect, int bufferLen)
 * @brief select add effect if "effect" var is true and add the length of the
 * effect
 * buffer to the config file.
 *
 * @param effect set effect to true or false
 * @param bufferLen the length of the effect buffer.
 */
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

/**
 * @fn addAnalogInput(int nb)
 * @brief add the number of analog input to the config file.
 *
 * @param nb Number of analog input.
 */
void GUIConfigFileSettingBuilder::addAnalogInput(int nb) {
  string str = "ANALOG " + std::to_string(nb);
  *fileBuffer << str << endl;
}

/**
 * @fn addAudioInput(int nb)
 * @brief add the number of audio input to the config file.
 *
 * @param nb Number of audio input.
 */
void GUIConfigFileSettingBuilder::addAudioInput(int nb) {
  string str = "AUDIO " + std::to_string(nb);
  *fileBuffer << str << endl;
}

/**
 * @fn addWavFile(string path)
 * @brief add a wav file to the config file.
 *
 * @param path The absolute path to the wav file on the computer.
 */
void GUIConfigFileSettingBuilder::addWavFile(string path) {
  string str = "FILE " + path;
  *fileBuffer << str << endl;
}

/**
 * @fn addColorFunction(string functionName)
 * @brief add the name of the color function selected.
 *
 * @param functionName The name of the function.
 */
void GUIConfigFileSettingBuilder::addColorFunction(string functionName) {
  string str = "COLOR " + functionName;
  *fileBuffer << str << endl;
}

/**
 * @fn addCoeffFunction(string functionName)
 * @brief add the name of the correlation coeff function selected.
 *
 * @param functionName The name of the function.
 */
void GUIConfigFileSettingBuilder::addCoeffFunction(string functionName) {
  string str = "COEFF " + functionName;
  *fileBuffer << str << endl;
}

/**
 * @fn addPreProcFunction(string functionName)
 * @brief add the name of the preprocess function selected.
 *
 * @param functionName The name of the function.
 */
void GUIConfigFileSettingBuilder::addPreProcFunction(string functionName) {
  string str = "PREPROC " + functionName;
  *fileBuffer << str << endl;
}

/**
 * @fn addCoeffFunction(string functionName)
 * @brief add the name of the mix function selected.
 *
 * @param functionName The name of the function.
 */
void GUIConfigFileSettingBuilder::addMixFunction(string functionName) {
  string str = "MIX " + functionName;
  *fileBuffer << str << endl;
}

/**
 * @fn endFile()
 * @brief add the end of file.
 *
 * @param
 */
void GUIConfigFileSettingBuilder::endFile() {}

/**
 * @fn getResult()
 * @brief print all the setting in a .cfg file.
 * format.
 *
 * @param
 */
void GUIConfigFileSettingBuilder::getResult() {
  ofstream configFile;
  configFile.open("./config_qt.cfg");
  configFile << fileBuffer->str();
  configFile.close();
}

/**
 * @fn ~GUIConfigFileSettingBuilder()
 * @brief Destructor of the GUIConfigFileSettingBuilder's class.
 *
 * @param
 */
GUIConfigFileSettingBuilder::~GUIConfigFileSettingBuilder() {
  delete fileBuffer;
}
