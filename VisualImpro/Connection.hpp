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
  int sockfd;
  //Struct sockaddr_in serv_addr; //UDP
  bool _isConnected; //TCP
  int _port;
  string _addr;

public :
  //Fefault settings
	Connection() : _port(12345), _addr("192.168.7.1") {}
	Connection(int port, string addr) : _port(port), _addr(addr){}
  bool isConnected();
  //Initialize TCP connection
  int init();
  int send(const string& msg);
  //Stops TCP connection
  int end();
};



#endif //CONNECT_HPP
