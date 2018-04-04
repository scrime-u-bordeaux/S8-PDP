/**
 * \file GUISettingLayoutFactory.cpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
 *            Lucas VIVAS
 *  @date   March 2018
*/

#include "GUISettingLayoutFactory.hpp"

GUIInputSettingLayout *GUISettingLayoutFactory::createGUIInputSettingLayout() {
  return new GUIInputSettingLayout();
}

GUIProcessSettingLayout *
GUISettingLayoutFactory::createGUIProcessSettingLayout() {
  return new GUIProcessSettingLayout();
}

GUIWavFileSettingLayout *
GUISettingLayoutFactory::createGUIWavFileSettingLayout() {
  return new GUIWavFileSettingLayout();
}
