/**
 * @file GUISettingLayout.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_GUISETTINGLAYOUT
#define DEF_GUISETTINGLAYOUT

using namespace std;

class GUISettingLayout {
public:
  virtual GUISettingLayout(QWidget *parent = 0) = 0;
  virtual QStringList getSetting() = 0;
  virtual ~GUISettingLayout() = 0;

private:

};
#endif // DEF_GUISETTINGLAYOUT
