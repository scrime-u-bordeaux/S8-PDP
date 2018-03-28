/**
 * @file GUIInputSettingLayout.hpp
 * @author Lucas VIVAS
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

using namespace std;

class GUIInputSettingLayout : public QGridLayout {
    Q_OBJECT
public:
  GUIInputSettingLayout(QWidget *parent = 0);
  void addSetting(string name, int min, int max);
  QStringList getSetting();
  ~GUIInputSettingLayout();

private:
  QVector<QLabel *> *allLabel;
  QVector<QSlider *> *allSlider;
  QVector<QSpinBox *> *allSpinBox;

};
#endif // DEF_GUIINPUTSETTINGLAYOUT
