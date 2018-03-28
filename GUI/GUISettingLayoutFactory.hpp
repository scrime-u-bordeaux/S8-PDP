/**
 * @file GUISettingLayoutFactory.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_GUISETTINGLAYOUTFACTORY
#define DEF_GUISETTINGLAYOUTFACTORY

using namespace std;

#include "GUIInputSettingLayout.hpp"
#include "GUIProcessSettingLayout.hpp"
#include "GUIWavFileSettingLayout.hpp"

class GUISettingLayoutFactory {
public:
  static GUIInputSettingLayout* createGUIInputSettingLayout();
  static GUIProcessSettingLayout* createGUIProcessSettingLayout();
  static GUIWavFileSettingLayout* createGUIWavFileSettingLayout();
};
#endif // DEF_GUISETTINGLAYOUTFACTORY
