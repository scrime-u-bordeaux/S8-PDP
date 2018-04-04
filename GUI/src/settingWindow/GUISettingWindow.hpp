/**
 * \file GUISettingWindow.hpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
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

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \class GUISettingWindow
 * \brief Class used to
 *
 * The container that will contain the settings layouts.
 */
class GUISettingWindow : public QDialog {

  /**
   * \var Q_OBJECT Contains a Qt object.
   */
  Q_OBJECT
public:

  /**
   * \fn    GUISettingWindow(QWidget *parent = 0)
   * \brief Create the settings window composed by the settings layouts.
   *
   * \param parent The QWidget parent.
   */
  GUISettingWindow(QWidget *parent = 0);

  /**
   * \fn    ~GUISettingWindow()
   * \brief Destructor
   *
   * Destructor of the GUISettingWindow class.
   */
  ~GUISettingWindow();

private slots:

 /**
  * \fn    void checkInput()
  * \brief
  */
  void checkInput();

private:

  /**
   * \fn    void checkInput()
   * \brief
   */
  void buildConfigFile();

  /**
   * \fn    void checkInput()
   * \brief
   *
   * \return
   */
  int getNumInput();

  /**
   * \var mainLayout
   * \var processSettingLayout
   * \var inputSettingLayout
   * \var wavFileLayout
   * \var finishLabel
   * \var finishButton
   */
  QVBoxLayout *mainLayout;
  GUIProcessSettingLayout *processSettingLayout;
  GUIInputSettingLayout *inputSettingLayout;
  GUIWavFileSettingLayout *wavFileLayout;
  QLabel *finishLabel;
  QPushButton *finishButton;
};
#endif // DEF_GUISETTINGWINDOW
