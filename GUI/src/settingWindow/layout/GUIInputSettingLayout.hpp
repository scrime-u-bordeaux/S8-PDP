/**
 * \file GUIInputSettingLayout.hpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#ifndef DEF_GUIINPUTSETTINGLAYOUT
#define DEF_GUIINPUTSETTINGLAYOUT

#include <QGridLayout>
#include <QLabel>
#include <QSlider>
#include <QSpinBox>

#include <QVector>
#include <string>
#include <QStringList>

#include "GUISettingLayout.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

class GUIInputSettingLayout : public QGridLayout, public GUISettingLayout {

  /**
   * \var Q_OBJECT Contains a Qt object.
   */
  Q_OBJECT
public:

  /**
   * \fn    GUIInputSettingLayout(QWidget *parent = 0)
   * \brief Create a settings layout for the inputs.
   *
   * \param parent The QWidget parent.
   */
  GUIInputSettingLayout(QWidget *parent = 0);

  /**
   * \fn    void addSetting(string name, int min, int max)
   * \brief
   *
   * \param name
   * \param min
   * \param max
   */
  void addSetting(string name, int min, int max);

  /**
   * \fn    const QStringList getSettings()
   * \brief
   */
  const QStringList getSettings();

  /**
   * \fn    ~GUIInputSettingLayout()
   * \brief Destructor
   *
   * Destructor of the GUIInputSettingLayout class.
   */
  ~GUIInputSettingLayout();

private:
  /**
   * \var allLabel
   * \var allSlider
   * \var allSpinBox
   */
  QVector<QLabel *> *allLabel;
  QVector<QSlider *> *allSlider;
  QVector<QSpinBox *> *allSpinBox;

};
#endif // DEF_GUIINPUTSETTINGLAYOUT
