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
#include <QComboBox>

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

  QLabel *colorLabel;
  QLabel *coefLabel;
  QLabel *preProcLabel;
  QLabel *mixLabel;
  QComboBox *colorBox;
  QComboBox *coefBox;
  QComboBox *preProcBox;
  QComboBox *mixBox;

};
#endif // DEF_GUISETTINGWINDOW
