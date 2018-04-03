/**
 * @file GUISettingLayoutFactory.cpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date   March 2018
*/

#include "GUISettingLayoutFactory.hpp"

/**
 * @fn
 * @brief
 *
 * @param var description
 */
GUIInputSettingLayout *GUISettingLayoutFactory::createGUIInputSettingLayout() {
  return new GUIInputSettingLayout();
}

/**
 * @fn
 * @brief
 *
 * @param var description
 */
GUIProcessSettingLayout *
GUISettingLayoutFactory::createGUIProcessSettingLayout() {
  return new GUIProcessSettingLayout();
}

/**
 * @fn
 * @brief
 *
 * @param var description
 */
GUIWavFileSettingLayout *
GUISettingLayoutFactory::createGUIWavFileSettingLayout() {
  return new GUIWavFileSettingLayout();
}
