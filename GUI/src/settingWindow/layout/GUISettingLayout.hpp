/**
 * @file GUISettingLayout.hpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#ifndef DEF_GUISETTINGLAYOUT
#define DEF_GUISETTINGLAYOUT

using namespace std;

class GUISettingLayout {
public:
  virtual const QStringList getSettings() = 0;
};
#endif // DEF_GUISETTINGLAYOUT
