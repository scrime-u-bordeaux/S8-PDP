/**
 * \file GUITCPServer.cpp
 * \author  Alexandre CASANOVA--FRANGER, Gauthier LARMARQUE, Paul SIMORRE,
*            Lucas VIVAS
*/

#include <iostream>
#include <QHostAddress>
#include <QString>
#include <QTcpSocket>
#include <string>

#include "GUITCPServer.hpp"

GUITCPServer::GUITCPServer(QObject *parent) : QTcpServer(parent) {
  QHostAddress address(IPADDRESS);
  listen(address, PORT);
  connect(this, SIGNAL(newConnection()), this, SLOT(onConnectionBela()));
}

void GUITCPServer::onConnectionBela() {
  if (hasPendingConnections()) {
    cout << "sock connected" << endl;
    clientSock = nextPendingConnection();
    connect(clientSock, SIGNAL(readyRead()), this, SLOT(readMatrix()));
  }
}

void GUITCPServer::readMatrix() {
  QString line;
  int length = 0, hexaStart = 0;

  line = clientSock->readLine();
  if (line != NULL) {
    string str = line.toStdString();
    /*if there is only a digit*/
    if (str[3] == '#') {
      /*char to int*/
      length = str[0] - '0';
      hexaStart = 3;
    }
    /*if there is a decimal number*/
    else{
    length = stoi(str.substr(0,2), nullptr, 10);
      hexaStart = 5;
    }

    string hexa;
    Matrix<RGB> colorMatrix(length,
                                    vector<RGB>(length, RGB(0, 0, 0)));

    for (int x = 0; x < length; x++) {
      for (int y = 0; y < length; y++, hexaStart += 7) {
        hexa = str.substr(hexaStart, 7);
        RGB color(hexa);
        colorMatrix.setCase(x, y, color);
      }
    }
    emit sendToGUI(colorMatrix);
  }
}

GUITCPServer::~GUITCPServer() {}
