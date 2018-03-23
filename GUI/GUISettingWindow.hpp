/**
 * @file GUISettingWindow.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_GUISETTINGWINDOW
#define DEF_GUISETTINGWINDOW

#include <QDialog>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

#include "GUIProcessSettingLayout.hpp"
#include "GUIInputSettingLayout.hpp"
#include "GUIWavFileLayout.hpp"

using namespace std;

class GUISettingWindow : public QDialog {
  Q_OBJECT
public:
  GUISettingWindow(QWidget *parent = 0);
  ~GUISettingWindow();

private:
  QVBoxLayout *mainLayout;
  GUIProcessSettingLayout* processSettingLayout;
  GUIInputSettingLayout* inputSettingLayout;
  GUIWavFileLayout* wavFileLayout;
  QPushButton *finishButton;


};
#endif // DEF_GUISETTINGWINDOW
