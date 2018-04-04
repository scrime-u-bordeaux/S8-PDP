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
 * \brief Class used to ***EXPLICATION***
 *
 * ***EXPLICATIONS***
 */
class GUISettingLayoutFactory {
public:

  /**
   * \fn    static GUIInputSettingLayout* createGUIInputSettingLayout()
   * \brief
   */
  static GUIInputSettingLayout* createGUIInputSettingLayout();

  /**
   * \fn    static GUIProcessSettingLayout* createGUIProcessSettingLayout()
   * \brief
   */
  static GUIProcessSettingLayout* createGUIProcessSettingLayout();

  /**
   * \fn    static GUIWavFileSettingLayout* createGUIWavFileSettingLayout()
   * \brief
   */
  static GUIWavFileSettingLayout* createGUIWavFileSettingLayout();
};
#endif // DEF_GUISETTINGLAYOUTFACTORY
