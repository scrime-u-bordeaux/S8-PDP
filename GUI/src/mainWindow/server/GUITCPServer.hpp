/**
 * \file GUITCPServer.hpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#ifndef DEF_GUITCPSERVER
#define DEF_GUITCPSERVER

#include <QObject>
#include <QTcpServer>
#include <vector>
#include "RGB.hpp"

#define PORT 12345
#define IPADDRESS "192.168.7.1"

/**
 * \class GUITCPServer
 * \brief Class used to send data
 *
 * The GUITCPServer class used to send data in TPC with the GUI.
 */
class GUITCPServer : public QTcpServer {

  /**
   * \var Q_OBJECT Contains a Qt object.
   */
  Q_OBJECT

public:

  /**
   * \fn    GUITCPServer(QObject * parent = 0)
   * \brief Create the GUI TCP server
   *
   * \param parent The QObject parent.
   */
  GUITCPServer(QObject * parent = 0);

  /**
   * \fn    ~GUITCPServer()
   * \brief Destructor
   *
   * Destructor of the GUITCPServer class.
   */
  ~GUITCPServer();

signals :
  /**
   * \fn    void sendToGUI(const vector<vector<RGB> >& matrixRGB)
   * \brief send a signal corresponding to an RGB matrix to the GUI
   *
   * \param matrixRGB The RGB matrix to send.
   */
  void sendToGUI(const vector<vector<RGB> >& matrixRGB);

private slots:

 /**
  * \fn    void onConnectionBela()
  * \brief The slot corresponding to a new connection.
  */
  void onConnectionBela();

  /**
   * \fn    void readMatrix()
   * \brief The slot corresponding to the matrix to read.
   */
  void readMatrix();

private:

  /**
   * \var clientSock Socket used to get and read the matrix.
   */
  QTcpSocket* clientSock;

};

#endif // DEF_GUITCPSERVER
