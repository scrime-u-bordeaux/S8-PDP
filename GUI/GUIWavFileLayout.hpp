/**
 * @file GUIWavFileLayout.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_GUIWAVFILELAYOUT
#define DEF_GUIWAVFILELAYOUT

#include <QGridLayout>
#include <QPushButton>
#include <QFileDialog>

using namespace std;

class GUIWavFileLayout : public QGridLayout {
  Q_OBJECT
public:
  GUIWavFileLayout(QWidget *parent = 0);
  ~GUIWavFileLayout();

public slots:
  void loadWavFile();

private:
QFileDialog *fileDialog;
  QPushButton *loadButton;

};
#endif // DEF_GUIWAVFILELAYOUT
