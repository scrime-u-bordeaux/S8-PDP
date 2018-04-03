/**
 * @file GUITCPServer.hpp
 * @author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
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

class GUITCPServer : public QTcpServer {
  Q_OBJECT
public:
  GUITCPServer(QObject * parent = 0);
  ~GUITCPServer();

signals :
  void sendToGUI(const vector<vector<RGB> >& matrixRGB);

private slots:
  void onConnectionBela();
  void readMatrix();

private:
  QTcpSocket* clientSock;

};

#endif // DEF_GUITCPSERVER
