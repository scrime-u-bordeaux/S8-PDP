/**
 * @file GUIProcessSettingLayout.hpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
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

using namespace std;

class GUIProcessSettingLayout : public QFormLayout, public GUISettingLayout {
    Q_OBJECT
public:
  GUIProcessSettingLayout(QWidget *parent = 0);
  void addSetting(string name);
  const QStringList getSetting();
  ~GUIProcessSettingLayout();

private:
  QVector<QComboBox *> *allBox;
  QStringList getFilename(string nameFile);

};
#endif // DEF_GUIPROCESSSETTINGLAYOUT
