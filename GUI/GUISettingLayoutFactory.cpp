/**
 * @file GUISettingLayoutFactory.cpp
 * @author Lucas VIVAS
*/

#include "GUISettingLayoutFactory.hpp"

GUIInputSettingLayout* GUISettingLayoutFactory::createGUIInputSettingLayout(){
    return new GUIInputSettingLayout();
}

GUIProcessSettingLayout* GUISettingLayoutFactory::createGUIProcessSettingLayout(){
    return new GUIProcessSettingLayout();
}

GUIWavFileSettingLayout* GUISettingLayoutFactory::createGUIWavFileSettingLayout(){
    return new GUIWavFileSettingLayout();
}
