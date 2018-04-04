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
 * \brief Class used to
 *
 * ***EXPLICATIONS***
 */
class GUIFileSettingBuilder {

public:
  /**
   * \fn    virtual void beginFile() = 0
   * \brief
   */
  virtual void beginFile() = 0;

  /**
   * \fn    virtual void addPort(int port) = 0
   * \brief
   *
   * \param port
   */
  virtual void addPort(int port) = 0;

  /**
   * \fn    virtual void addAddress(string address) = 0
   * \brief
   *
   * \param address
   */
  virtual void addAddress(string address) = 0;

  /**
   * \fn    virtual void addProcessLen(int length) = 0
   * \brief
   *
   * \param length
   */
  virtual void addProcessLen(int length) = 0;

  /**
   * \fn    virtual void addEffect(bool effect, int bufferLen) = 0
   * \brief
   *
   * \param effect
   * \param bufferLen
   */
  virtual void addEffect(bool effect, int bufferLen) = 0;

  /**
   * \fn    virtual void addAnalogInput(int nb) = 0
   * \brief
   *
   * \param nb
   */
  virtual void addAnalogInput(int nb) = 0;

  /**
   * \fn    virtual void addAudioInput(int nb) = 0
   * \brief
   *
   * \param nb
   */
  virtual void addAudioInput(int nb) = 0;

  /**
   * \fn    virtual void addWavFile(string path) = 0
   * \brief
   *
   * \param path
   */
  virtual void addWavFile(string path) = 0;

  /**
   * \fn    virtual void addColorFunction(string functionName) = 0
   * \brief
   *
   * \param functionName
   */
  virtual void addColorFunction(string functionName) = 0;

  /**
   * \fn    virtual void addCoeffFunction(string functionName) = 0
   * \brief
   *
   * \param functionName
   */
  virtual void addCoeffFunction(string functionName) = 0;

  /**
   * \fn    virtual void addPreProcFunction(string functionName) = 0
   * \brief
   *
   * \param functionName
   */
  virtual void addPreProcFunction(string functionName) = 0;

  /**
   * \fn    virtual void addMixFunction(string functionName) = 0
   * \brief
   *
   * \param functionName
   */
  virtual void addMixFunction(string functionName) = 0;

  /**
   * \fn    virtual void endFile() = 0
   * \brief
   */
  virtual void endFile() = 0;
};
#endif // DEF_GUIFILESETTINGBUILDER
