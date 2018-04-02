/**
 * @file GUISettingWindow.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_GUISETTINGWINDOW
#define DEF_GUISETTINGWINDOW

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

#include "GUIInputSettingLayout.hpp"
#include "GUIProcessSettingLayout.hpp"
#include "GUIWavFileSettingLayout.hpp"

#define MIN_ENTRIES 2

#define MIN_AUDIO_INPUT 0
#define MAX_AUDIO_INPUT 2
#define MIN_ANALOG_INPUT 0
#define MAX_ANALOG_INPUT 8

#define PORT 12345
#define IPADDRESS "192.168.7.1"
#define PROCESSLEN 32768
#define EFFECTBUFFERLEN 32

using namespace std;

class GUISettingWindow : public QDialog {
  Q_OBJECT
public:
  GUISettingWindow(QWidget *parent = 0);
  ~GUISettingWindow();

private slots:
  void checkInput();

private:
  void buildConfigFile();
  int getNumInput();
  QVBoxLayout *mainLayout;
  GUIProcessSettingLayout *processSettingLayout;
  GUIInputSettingLayout *inputSettingLayout;
  GUIWavFileSettingLayout *wavFileLayout;
  QLabel *finishLabel;
  QPushButton *finishButton;
};
#endif // DEF_GUISETTINGWINDOW
