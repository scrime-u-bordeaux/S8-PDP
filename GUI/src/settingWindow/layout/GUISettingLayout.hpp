/**
 * \file GUISettingLayout.hpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#ifndef DEF_GUISETTINGLAYOUT
#define DEF_GUISETTINGLAYOUT

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
class GUISettingLayout {
public:
  /**
   * \fn    virtual const QStringList getSettings() = 0
   * \brief
   */
  virtual const QStringList getSettings() = 0;
};
#endif // DEF_GUISETTINGLAYOUT
