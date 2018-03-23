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

using namespace std;

class GUISettingWindow : public QDialog {
public:
  GUISettingWindow(QWidget *parent = 0);
  ~GUISettingWindow();

private:
  QVBoxLayout *mainLayout;
  GUIProcessSettingLayout* processSettingLayout;
  GUIInputSettingLayout* inputSettingLayout;
  QPushButton *finishButton;


};
#endif // DEF_GUISETTINGWINDOW
