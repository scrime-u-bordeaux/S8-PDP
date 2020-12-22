#ifndef CONNECT_HPP
#define CONNECT_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <errno.h>
#include <netdb.h>
#include <signal.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>

#include "mongoose.h"
//#include "UdpClient.h"

/**
 * \namespace std
 * Standard C++ library
 */
using namespace std;

/**
 * \class Connection
 * \brief Class representing the connection object.
 *
 * This class is used to send data on a web page.
 */
class Connection{

private :
  //int sockfd;
  //Struct sockaddr_in serv_addr; //UDP
  bool _isConnected; //TCP
  int _port;
  string _addr;
  struct mg_mgr mgr;
 
  bool stop;
  
public :
  //Fefault settings
	Connection() : _port(9090), _addr("127.0.0.1") {}
	Connection(int port, string addr) : _port(port), _addr(addr){}

  //Initialize TCP connection
  int init();
  int send( string& msg);
  //Stops TCP connection
  int end();
  bool getIsConnected(){return _isConnected;};
  bool startRender();
  void setIsConnected(bool b){_isConnected = b;};
  void setStop(bool b){cout << "Bravo" << endl; stop = b;};
  
};

#endif //CONNECT_HPP
