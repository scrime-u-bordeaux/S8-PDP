/**
 * \file GUIWindow.hpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#ifndef DEF_GUIWINDOW
#define DEF_GUIWINDOW

#include <QtGui>
#include <QWidget>
#include <vector>

#include "GUIImageMatrix.hpp"
#include "GUITCPServer.hpp"
#include "RGB.hpp"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \class GUIWindow
 * \brief Class used to manage the GUI window
 *
 * The container that will contain a GUIImageMatrix.
 */
class GUIWindow : public QMainWindow {

  /**
   * \var Q_OBJECT Contains a Qt object.
   */
  Q_OBJECT
public:
  /**
   * \fn    GUIWindow(int sizeMatrix, QWidget *parent = 0)
   * \brief Create the main window composed by the RGB matrix itself.
   *
   * \param sizeMatrix Size of the matrix.
   * \param parent     The QWidget parent.
   */
  GUIWindow(int sizeMatrix, QWidget *parent = 0);

  /**
   * \fn    ~GUIWindow()
   * \brief Destructor
   *
   * Destructor of the GUIWindow class.
   */
  ~GUIWindow();

public slots:

  /**
   * \fn    void updateColor(const vector<vector<RGB> >& matrixRGB)
   * \brief Update the colors of the matrix
   *
   * \param matrixRGB The RGB matrix with the fresh colors to update.
   */
  void updateColor(const vector<vector<RGB> >& matrixRGB);
private:

  /**
   * \var view   The layout printing the matrix.
   * \var server The server getting the data from Bela.
   */
  GUIImageMatrix *view;
  GUITCPServer *server;

};
#endif // DEF_GUIWINDOW
