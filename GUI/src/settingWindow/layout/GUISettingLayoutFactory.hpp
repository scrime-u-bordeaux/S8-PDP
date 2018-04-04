/**
 * \file GUISettingLayoutFactory.hpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#ifndef DEF_GUISETTINGLAYOUTFACTORY
#define DEF_GUISETTINGLAYOUTFACTORY

#include "GUIInputSettingLayout.hpp"
#include "GUIProcessSettingLayout.hpp"
#include "GUIWavFileSettingLayout.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \class GUISettingLayoutFactory
 * \brief Class used as a factory for the layout.
 *
 */
class GUISettingLayoutFactory {
public:

  /**
   * \fn    static GUIInputSettingLayout* createGUIInputSettingLayout()
   * \brief create a input layout.
   */
  static GUIInputSettingLayout* createGUIInputSettingLayout();

  /**
   * \fn    static GUIProcessSettingLayout* createGUIProcessSettingLayout()
   * \brief create a process layout.
   */
  static GUIProcessSettingLayout* createGUIProcessSettingLayout();

  /**
   * \fn    static GUIWavFileSettingLayout* createGUIWavFileSettingLayout()
   * \brief create a wav file layout.
   */
  static GUIWavFileSettingLayout* createGUIWavFileSettingLayout();
};
#endif // DEF_GUISETTINGLAYOUTFACTORY
