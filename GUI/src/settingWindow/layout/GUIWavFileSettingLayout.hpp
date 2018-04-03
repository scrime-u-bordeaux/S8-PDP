/**
 * @file GUIWavFileSettingLayout.hpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#ifndef DEF_GUIWAVFILESETTINGLAYOUT
#define DEF_GUIWAVFILESETTINGLAYOUT

#include<QVBoxLayout>

#include <QFileDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

#include <QStringList>
#include <QStringListModel>
#include <QListView>

#include "GUISettingLayout.hpp"

using namespace std;

class GUIWavFileSettingLayout : public QGridLayout, public GUISettingLayout {
  Q_OBJECT
public:
  GUIWavFileSettingLayout(QWidget *parent = 0);
  const QStringList getSettings();
  ~GUIWavFileSettingLayout();

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
#endif // DEF_GUIWAVFILESETTINGLAYOUT
