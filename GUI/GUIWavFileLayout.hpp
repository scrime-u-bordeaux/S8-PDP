/**
 * @file GUIWavFileLayout.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_GUIWAVFILELAYOUT
#define DEF_GUIWAVFILELAYOUT

#include <QFileDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>

#include <vector>

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
  QPushButton *removeButton;

  QLabel *wavFilesLabel;
  QTextEdit *wavFilesText;

  vector<QString *> *filesName;
};
#endif // DEF_GUIWAVFILELAYOUT
