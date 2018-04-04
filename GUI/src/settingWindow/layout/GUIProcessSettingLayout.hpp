/**
 * \file GUIProcessSettingLayout.hpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#ifndef DEF_GUIPROCESSSETTINGLAYOUT
#define DEF_GUIPROCESSSETTINGLAYOUT

#include <QFormLayout>
#include <QComboBox>
#include <string>
#include <QVector>
#include <QStringList>

#include "GUISettingLayout.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

class GUIProcessSettingLayout : public QFormLayout, public GUISettingLayout {

  /**
   * \var Q_OBJECT Contains a Qt object.
   */
  Q_OBJECT
public:
  /**
   * \fn    GUIProcessSettingLayout(QWidget *parent = 0)
   * \brief Create a settings layout for processing functions.
   *
   * \param parent The QWidget parent.
   */
  GUIProcessSettingLayout(QWidget *parent = 0);

  /**
   * \fn    void addSetting(string name)
   * \brief
   *
   * \param name
   */
  void addSetting(string name);

  /**
   * \fn    const QStringList getSettings()
   * \brief
   */
  const QStringList getSettings();

  /**
   * \fn    ~GUIProcessSettingLayout()
   * \brief Destructor
   *
   * Destructor of the GUIProcessSettingLayout class.
   */
  ~GUIProcessSettingLayout();

private:
  /**
   * \var allBox
   */
  QVector<QComboBox *> *allBox;

  /**
   * \fn    QStringList getFilename(string nameFile)
   * \brief
   *
   * \param nameFile
   */
  QStringList getFilename(string nameFile);

};
#endif // DEF_GUIPROCESSSETTINGLAYOUT
