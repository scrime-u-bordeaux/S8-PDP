/**
 * \file GUIWavFileSettingLayout.hpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
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

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \class GUIWavFileSettingLayout
 * \brief Class used to ***EXPLICATION***
 *
 * ***EXPLICATIONS***
 */
class GUIWavFileSettingLayout : public QGridLayout, public GUISettingLayout {

  /**
   * \var Q_OBJECT Contains a Qt object.
   */
  Q_OBJECT
public:
  /**
   * \fn    GUIWavFileSettingLayout(QWidget *parent = 0)
   * \brief Create a settings layout for wavefiles.
   *
   * \param parent The QWidget parent.
   */
  GUIWavFileSettingLayout(QWidget *parent = 0);

  /**
   * \fn    const QStringList getSettings()
   * \brief
   */
  const QStringList getSettings();

  /**
   * \fn    ~GUIWavFileSettingLayout()
   * \brief Destructor
   *
   * Destructor of the GUIWavFileSettingLayout class.
   */
  ~GUIWavFileSettingLayout();

private slots:
 /**
  * \fn    void loadWavFile()
  * \brief
  */
  void loadWavFile();

  /**
   * \fn    removeWavFile()
   * \brief
   */
  void removeWavFile();

  /**
   * \fn    void clearWavFile()
   * \brief
   */
  void clearWavFile();

private:

  /**
   * \var leftLayout
   * \var fileDialog
   * \var loadButton
   * \var removeButton
   * \var clearButton
   * \var wavFilesLabel
   * \var nameFile
   * \var nameFileModel
   * \var listView
   */
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
