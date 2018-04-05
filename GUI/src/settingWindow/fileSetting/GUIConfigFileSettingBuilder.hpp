/**
 * \file GUIConfigFileSettingBuilder.hpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#ifndef DEF_GUICONFIGFILESETTINGBUILDER
#define DEF_GUICONFIGFILESETTINGBUILDER

#include <string>
#include <sstream>

#include "GUIFileSettingBuilder.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \class GUIConfigFileSettingBuilder
 * \brief Class used to ***EXPLICATION***
 *
 * ***EXPLICATIONS***
 */
class GUIConfigFileSettingBuilder : public GUIFileSettingBuilder {

public:

  /**
   * \fn    GUIConfigFileSettingBuilder()
   * \brief Constructor of the GUIConfigFileSettingBuilder object
   *
   * ***EXPLICATIONS***
   */
  GUIConfigFileSettingBuilder();

  /**
   * \fn    void beginFile()
   * \brief Add the beginning of the Configuration file.
   */
  void beginFile();

  /**
   * \fn    void addPort(int port)
   * \brief Add the port in the configuration file.
   *
   * \param port The number of the port.
   */
  void addPort(int port);

  /**
   * \fn    addAddress(string address)
   * \brief Add the ip address to the configuration file.
   *
   * \param address IP address as a string for the server.
   */
  void addAddress(string address);

  /**
   * \fn    addProcessLen(int length)
   * \brief Add the process buffer length to the configuration file.
   *
   * \param length Buffer process length.
   */
  void addProcessLen(int length);

  /**
   * \fn    addEffect(bool effect, int bufferLen)
   * \brief Enable effectes if the "effect" var is true and add the effect
   *        process length to the configuration file.
   *
   * \param effect A boolean to tell to enable effects or not.
   * \param bufferLen The length of the effect buffer.
   */
  void addEffect(bool effect, int bufferLen);

  /**
   * \fn    addAnalogInput(int nb)
   * \brief Add the number of analog inputs to the configuration file.
   *
   * \param nb Number of analog input.
   */
  void addAnalogInput(int nb);

  /**
   * \fn    addAudioInput(int nb)
   * \brief Add the number of audio inputs to the configuration file.
   *
   * \param nb Number of audio input.
   */
  void addAudioInput(int nb);

  /**
   * \fn    addWavFile(string path)
   * \brief add a wav file to the config file.
   *
   * \param path The absolute path to the wav file on the computer.
   */
  void addWavFile(string path);

  /**
   * \fn    addColorFunction(string functionName)
   * \brief Add the name of the color function selected to the config file.
   *
   * \param functionName The name of the function.
   */
  void addColorFunction(string functionName);

  /**
   * \fn    addCoeffFunction(string functionName)
   * \brief Add the name of the correlation function selected.
   *
   * \param functionName The name of the function.
   */
  void addCoeffFunction(string functionName);

  /**
   * \fn    addPreProcFunction(string functionName)
   * \brief Add the name of the preprocessing function selected.
   *
   * \param functionName The name of the function.
   */
  void addPreProcFunction(string functionName);

  /**
   * \fn    addCoeffFunction(string functionName)
   * \brief Add the name of the mix function selected.
   *
   * \param functionName The name of the function.
   */
  void addMixFunction(string functionName);

  /**
   * \fn    endFile()
   * \brief Add the end of file.
   */
  void endFile();

  /**
   * \fn    getResult()
   * \brief Print all the setting in a .cfg file format.
   */
  string getResult();

  /**
   * \fn    ~GUIConfigFileSettingBuilder()
   * \brief Destructor
   *
   * Destructor of the GUIConfigFileSettingBuilder class.
   */
  ~GUIConfigFileSettingBuilder();

private:
  /**
   * \var fileBuffer ***EXPLICATION***
   */
  stringstream* fileBuffer;
};
#endif // DEF_GUICONFIGFILESETTINGBUILDER
