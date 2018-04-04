/**
 * \file GUIFileSettingBuilder.hpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#ifndef DEF_GUIFILESETTINGBUILDER
#define DEF_GUIFILESETTINGBUILDER

#include <string>

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \class GUIFileSettingBuilder
 * \brief Class used as a builder for the exit file.
 *
 *
 */
class GUIFileSettingBuilder {

public:
  /**
   * \fn    virtual void beginFile() = 0
   * \brief Add the beginning of the file.
   */
  virtual void beginFile() = 0;

  /**
   * \fn    virtual void addPort(int port) = 0
   * \brief Add the port.
   *
   * \param port The port.
   */
  virtual void addPort(int port) = 0;

  /**
   * \fn    virtual void addAddress(string address) = 0
   * \brief Add the ip adress.
   *
   * \param address The ip adress in string format.
   */
  virtual void addAddress(string address) = 0;

  /**
   * \fn    virtual void addProcessLen(int length) = 0
   * \brief Add the length of the process length.
   *
   * \param length The length of the process' buffer.
   */
  virtual void addProcessLen(int length) = 0;

  /**
   * \fn    addEffect(bool effect, int bufferLen)
   * \brief Enable effectes if the "effect" var is true and add the effect
   *        process length to the configuration file.
   *
   * \param effect A boolean to tell to enable effects or not.
   * \param bufferLen The length of the effect buffer.
   */
  virtual void addEffect(bool effect, int bufferLen) = 0;

  /**
   * \fn    addAnalogInput(int nb)
   * \brief Add the number of analog inputs to the configuration file.
   *
   * \param nb Number of analog input.
   */
  virtual void addAnalogInput(int nb) = 0;

  /**
   * \fn    addAudioInput(int nb)
   * \brief Add the number of audio inputs to the configuration file.
   *
   * \param nb Number of audio input.
   */
  virtual void addAudioInput(int nb) = 0;

  /**
   * \fn    addWavFile(string path)
   * \brief add a wav file to the config file.
   *
   * \param path The absolute path to the wav file on the computer.
   */
  virtual void addWavFile(string path) = 0;

  /**
   * \fn    addColorFunction(string functionName)
   * \brief Add the name of the color function selected to the config file.
   *
   * \param functionName The name of the function.
   */
  virtual void addColorFunction(string functionName) = 0;

  /**
   * \fn    addCoeffFunction(string functionName)
   * \brief Add the name of the correlation function selected.
   *
   * \param functionName The name of the function.
   */
  virtual void addCoeffFunction(string functionName) = 0;

  /**
   * \fn    addPreProcFunction(string functionName)
   * \brief Add the name of the preprocessing function selected.
   *
   * \param functionName The name of the function.
   */
  virtual void addPreProcFunction(string functionName) = 0;

  /**
   * \fn    addCoeffFunction(string functionName)
   * \brief Add the name of the mix function selected.
   *
   * \param functionName The name of the function.
   */
  virtual void addMixFunction(string functionName) = 0;

  /**
   * \fn    endFile()
   * \brief Add the end of file.
   */
  virtual void endFile() = 0;
};
#endif // DEF_GUIFILESETTINGBUILDER
