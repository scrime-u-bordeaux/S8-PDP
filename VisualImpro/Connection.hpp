/***** Connection.hpp *****/

#ifndef CONNECT_HPP
#define CONNECT_HPP

#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <netdb.h>
#include <unistd.h>

#include <sys/select.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <netinet/in.h>

#include <arpa/inet.h>
#include <strings.h>
#include <iostream>
#include <fstream>

#include <string>
#include <vector>

#include "UdpClient.h"

using namespace std;

class Connection{

private :
  int sockfd;
  //struct sockaddr_in serv_addr; //UDP
  bool _isConnected; //TCP
  int _port;
  std::string _addr;

public :
	Connection() : _port(12345), _addr("192.168.7.1") {} //default settings
	Connection(int port, std::string addr) : _port(port), _addr(addr){}
  bool isConnected(); //TCP
  int init(); //connection tcp
  int send(const std::string& msg);
  int end(); //stops tcp connection
};



#endif //CONNECT_HPP
