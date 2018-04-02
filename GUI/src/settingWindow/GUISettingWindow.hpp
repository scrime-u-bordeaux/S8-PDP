/**
 * @file GUISettingWindow.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_GUISETTINGWINDOW
#define DEF_GUISETTINGWINDOW

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include <QLabel>

#include "GUIInputSettingLayout.hpp"
#include "GUIProcessSettingLayout.hpp"
#include "GUIWavFileSettingLayout.hpp"

using namespace std;

class GUISettingWindow : public QDialog {
  Q_OBJECT
public:
  GUISettingWindow(QWidget *parent = 0);
  ~GUISettingWindow();

private slots:
  void getParam();

private:
  QVBoxLayout *mainLayout;
  GUIProcessSettingLayout *processSettingLayout;
  GUIInputSettingLayout *inputSettingLayout;
  GUIWavFileSettingLayout *wavFileLayout;
  QLabel *finishLabel;
  QPushButton *finishButton;
};
#endif // DEF_GUISETTINGWINDOW
