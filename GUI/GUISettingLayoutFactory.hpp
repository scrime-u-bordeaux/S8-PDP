/**
 * @file GUISettingLayoutFactory.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_GUISETTINGLAYOUTFACTORY
#define DEF_GUISETTINGLAYOUTFACTORY

using namespace std;

#include "GUISettingLayout.hpp"

class GUISettingLayoutFactory {
public:
  GUISettingLayoutFactory(QWidget *parent = 0);
  GUISettingLayout createGUIInputSettingLayout();
  GUISettingLayout createGUIProcessSettingLayout();
  GUISettingLayout createGUIWavFileLayout();
  ~GUISettingLayoutFactory();

private:

};
#endif // DEF_GUISETTINGLAYOUTFACTORY
