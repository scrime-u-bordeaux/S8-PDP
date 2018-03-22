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
#include <QSlider>
#include <QSpinBox>
#include <QLabel>

using namespace std;

class GUISettingWindow : public QDialog {
public:
  GUISettingWindow(QWidget *parent = 0);
  ~GUISettingWindow();

private:
  QWidget *principalWidget;
  QGridLayout *mainLayout;
  QPushButton *finishButton;

  QLabel *nbAudioLabel;
  QLabel *nbAnalogLabel;
  QSlider *nbAudioSlider;
  QSlider *nbAnalogSlider;
  QSpinBox *nbAudioBox;
  QSpinBox *nbAnalogBox;




};
#endif // DEF_GUISETTINGWINDOW
