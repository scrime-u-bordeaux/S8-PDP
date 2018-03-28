/**
 * @file GUIProcessSettingLayout.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_GUIPROCESSSETTINGLAYOUT
#define DEF_GUIPROCESSSETTINGLAYOUT

#include <QFormLayout>
#include <QComboBox>
#include <string>
#include <QVector>
#include <QStringList>

using namespace std;

class GUIProcessSettingLayout : public QFormLayout {
    Q_OBJECT
public:
  GUIProcessSettingLayout(QWidget *parent = 0);
  void addSetting(string name);
  QStringList getSetting();
  ~GUIProcessSettingLayout();

private:
  QVector<QComboBox *> *allBox;
  QStringList getFilename(string nameFile);

};
#endif // DEF_GUIPROCESSSETTINGLAYOUT
