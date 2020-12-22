/**
 *  \file    Connection.cpp
 *  \author  Jérémy LIXANDRE
 *  \date    July 2017
 *
 *  \brief Connection object to send data on a web page.
 *
 *  The Connection object is used, after finishing the processing
 *  operations, to send the processed data to a web page on Firefox.
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
/**
 * \def SYSCALL(call, val, msg)
 * Check if the the return value of the call is equals to val, returns -1 if so.
 */
#define SYSCALL(call, val, msg) if ((call) == (val)) {perror(msg); return -1;}
#define TIMEOUT 1

#define LEN 256

#define PORTNO 9090
#define ADDR "127.0.0.1"

static sig_atomic_t s_signal_received = 0;
static const char *s_http_port = "9090";
static struct mg_serve_http_opts s_http_server_opts;
bool start =false;

static void signal_handler(int sig_num)
{
    signal(sig_num, signal_handler);  // Reinstantiate signal handler
    s_signal_received = sig_num;
}


static void ev_handler(struct mg_connection *nc, int ev, void *ev_data)
{

    switch (ev)
    {
        case MG_EV_WEBSOCKET_HANDSHAKE_DONE:
        {
            cout << "Connected to Score" << endl;
            break;
        }
        
        case MG_EV_WEBSOCKET_FRAME:
        {
        	struct websocket_message *wm = (struct websocket_message *) ev_data;
        	string str = "";
        	for(int i = 0; i< wm->size; i++)
        		str +=wm->data[i];
        	
        	if(str == "true") start = true;
        	break;
        }
        
         case MG_EV_HTTP_REQUEST:
        {
            mg_serve_http(nc, (struct http_message *) ev_data, s_http_server_opts);
            break;
        }
    }
}

int Connection::init(){
	struct mg_connection *nc;
    signal(SIGTERM, signal_handler);
    signal(SIGINT, signal_handler);
    setvbuf(stdout, NULL, _IOLBF, 0);
	setvbuf(stderr, NULL, _IOLBF, 0);
	mg_mgr_init(&mgr, NULL);


	nc = mg_bind(&mgr,std::to_string(_port).c_str() ,ev_handler);
	mg_set_protocol_http_websocket(nc);
    s_http_server_opts.document_root = ".";  // Serve current directory
    s_http_server_opts.enable_directory_listing = "yes";
	 
  	printf("Started on port %s\n", s_http_port);
  	while (s_signal_received == 0) {
    	mg_mgr_poll(&mgr, 200); 
  	}


	return 0;
}

int Connection::send( string &msg){
	
	mg_send_websocket_frame(mgr.active_connections, WEBSOCKET_OP_TEXT, msg.c_str(), msg.size());
	
return 1;
}
bool Connection::startRender()
{
	return start;
}

int Connection::end(){

mg_mgr_free(&mgr);

return 0;
}

