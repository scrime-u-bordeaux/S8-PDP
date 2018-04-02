/**
 *  @file    Connexion.cpp
 *  @author  Jérémy LIXANDRE
 *  @date    July 2017
 *
 *  @section DESCRIPTION
 *
 *  The Connexion object is used, after finishing the processing operations,
 *  to send the processed data to a web page on Firefox.
 *
 */


#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Connection.hpp"

#define SYSCALL(call, val, msg) if ((call) == (val)) {perror(msg); return -1;}
#define TIMEOUT 1

#define LEN 256

#define PORTNO 12345
#define ADDR "192.168.7.1"

bool Connection::isConnected(){  //TCP
  return this->_isConnected;
}


int Connection::init(){

//UDP

/*
sock = UdpClient(PORTNO, ADDR);
sock.setPort(PORTNO);
sock.setServer(ADDR);*/

  /*this->sockfd = socket(AF_INET, SOCK_DGRAM, 0);

  SYSCALL(this->sockfd, -1, "ERROR OPENING SOCKET");

  string addr(ADDR);
  int portno = PORTNO;
  struct in_addr inp;
  SYSCALL(inet_aton(addr.c_str(), &inp), 0, "ERROR copying address");
  //struct sockaddr_in serv_addr;
  bzero((char*) &serv_addr, sizeof(serv_addr)); //utile ?
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr = inp;
  serv_addr.sin_port = htons(portno); //recupere num port
  return 0;*/

//TCP

  this->sockfd = socket(AF_INET, SOCK_STREAM, 0);

  SYSCALL(this->sockfd, -1, "ERROR OPENING SOCKET");

  string addr(_addr);
  int portno = _port;
  struct in_addr inp;
  SYSCALL(inet_aton(addr.c_str(), &inp), 0, "ERROR copying address");
  struct sockaddr_in serv_addr;
  bzero((char*) &serv_addr, sizeof(serv_addr)); //utile ?
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr = inp;
  serv_addr.sin_port = htons(portno); //recupere num port
  if (connect(this->sockfd,
      (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == 0){
    this->_isConnected = true;
    return 0;
  }
  printf("Pas connecté\n");
  return -1;

}


int Connection::send(const string &msg){

//TCP

  string tosend = msg;
  int n = write(this->sockfd, tosend.c_str(), tosend.length());
  SYSCALL(n, -1, "ERROR WRITE SOCKET");
  return n;
//UDP

/*
	socklen_t addrlen = sizeof(serv_addr);
	sendto(this->sockfd, msg.c_str(), msg.length()*sizeof(char), 0,
         (struct sockaddr *) &(this->serv_addr), addrlen);
	//printf("sent ? %d\n", sent);

  return 0;
 */


}



int Connection::end(){

//TCP

  if (close(sockfd) == 0){
    this->_isConnected = false;
    return 0;
  }
  return -1;
return 0;
}
