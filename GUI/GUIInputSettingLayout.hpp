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

#include <vector>
#include <string>

using namespace std;

class GUIInputSettingLayout : public QGridLayout {
public:
  GUIInputSettingLayout(QWidget *parent = 0);
  void addSetting(string name, int min, int max);
  ~GUIInputSettingLayout();

private:
  vector<QLabel *> *allLabel;
  vector<QSlider *> *allSlider;
  vector<QSpinBox *> *allSpinBox;

};
#endif // DEF_GUIINPUTSETTINGLAYOUT
