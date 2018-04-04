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

/**
 * \class GUISettingLayoutFactory
 * \brief Class used as an layout to choose the process functions.
 *
 */
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
   * \brief Add a part for the "name" process function.
   *
   * \param name The name of the process function.
   */
  void addSetting(string name);

  /**
   * \fn    const QStringList getSettings()
   * \brief Return all the process function as a QStringList.
   *
   * \return Return the name of the process function.
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
   * \brief Get all the function in the directory with the name : nameFile.
   *
   * \param nameFile
   */
  QStringList getFilename(string nameFile);

};
#endif // DEF_GUIPROCESSSETTINGLAYOUT
