/**
 * @file GUIWavFileLayout.hpp
 * @author Lucas VIVAS
*/

#ifndef DEF_GUIWAVFILELAYOUT
#define DEF_GUIWAVFILELAYOUT

#include<QVBoxLayout>

#include <QFileDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

#include <QStringList>
#include <QStringListModel>
#include <QListView>

using namespace std;

class GUIWavFileLayout : public QGridLayout {
  Q_OBJECT
public:
  GUIWavFileLayout(QWidget *parent = 0);
  const QStringList getSetting();
  ~GUIWavFileLayout();

private slots:
  void loadWavFile();
  void removeWavFile();
  void clearWavFile();

private:
  QVBoxLayout *leftLayout;

  QFileDialog *fileDialog;
  QPushButton *loadButton;
  QPushButton *removeButton;
  QPushButton *clearButton;

  QLabel *wavFilesLabel;

  QStringList* nameFile;
  QStringListModel* nameFileModel;
  QListView * listView;
};
#endif // DEF_GUIWAVFILELAYOUT
