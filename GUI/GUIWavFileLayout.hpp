/**
 * @file GUIWavFileLayout.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_GUIWAVFILELAYOUT
#define DEF_GUIWAVFILELAYOUT

#include <QFileDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>

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

  QLabel *wavFilesLabel;
  QTextEdit *wavFilesText;
};
#endif // DEF_GUIWAVFILELAYOUT
