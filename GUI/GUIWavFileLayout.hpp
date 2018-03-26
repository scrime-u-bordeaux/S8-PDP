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

#include <QStringList>
#include <QStringListModel>
#include <QListView>

using namespace std;

class GUIWavFileLayout : public QGridLayout {
  Q_OBJECT
public:
  GUIWavFileLayout(QWidget *parent = 0);
  ~GUIWavFileLayout();

private slots:
  void loadWavFile();
  void removeWavFile();

private:
  QFileDialog *fileDialog;
  QPushButton *loadButton;
  QPushButton *removeButton;

  QLabel *wavFilesLabel;

  QStringList* nameFile;
  QStringListModel* nameFileModel;
  QListView * listView;
};
#endif // DEF_GUIWAVFILELAYOUT
