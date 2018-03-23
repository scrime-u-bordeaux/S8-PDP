/**
 * @file GUISettingWindow.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_GUIPROCESSSETTINGLAYOUT
#define DEF_GUIPROCESSSETTINGLAYOUT

#include <QFormLayout>
#include <QComboBox>
#include <string>
#include <vector>

using namespace std;

class GUIProcessSettingLayout : public QFormLayout {
public:
  GUIProcessSettingLayout(QWidget *parent = 0);
  void addSetting(string name);
  ~GUIProcessSettingLayout();

private:
  vector<string> getFilename(string nameFile);
  vector<QComboBox *> *allBox;

};
#endif // DEF_GUIPROCESSSETTINGLAYOUT
