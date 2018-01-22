var net = require('net');
var dgram = require('dgram');
var http = require('http');
var fs = require('fs');

var HOST = '192.168.7.1';
var PORT = 12345;

// Create a server instance, and chain the listen function to it
// The function passed to net.createServer() becomes the event handler for the 'connection' event
// The sock object the callback function receives UNIQUE for each connection

function ab2str(buf) {
  return String.fromCharCode.apply(null, new Uint16Array(buf));
}

var httpserver = http.createServer(function(req, res) {
	    fs.readFile('./index.html', 'utf-8', function(error, content) {
    	    res.writeHead(200, {"Content-Type": "text/html"});
        	res.end(content);
		});
});

var io = require('socket.io').listen(httpserver);

var wsclients = [];

io.sockets.on('connection', function (socket) {
    //console.log('Client web connecté');
    wsclients.push(socket);
});

//TCP SERVER

var tcpserver = net.createServer(function(sock) {
    
    console.log('CONNECTED: ' + sock.remoteAddress +':'+ sock.remotePort);
    
    // Add a 'data' event handler to this instance of socket
    sock.on('data', function(data) {
		//console.log('Data RECEIVED');
        //console.log('DATA ' + sock.remoteAddress + ': ' + data);
        // Write the data back to the socket, the client will receive it as data from the server
	//alert(data);
	//console.log("clients : " + wsclients);
	for (var cl = 0; cl < wsclients.length ; cl++)
	    wsclients[cl].emit('message', ab2str(data));
    });
    sock.on('close', function(data) {
        console.log('CLOSED: ' + sock.remoteAddress +' '+ sock.remotePort);
    });
}).listen(PORT, HOST);

//UDP SERVER

/*
var dServer = dgram.createSocket('udp4');
dServer.on('message', function(msg, rinfo){    
    //console.log('CONNECTED: ' + sock.remoteAddress +':'+ sock.remotePort);
    
     console.log('DATA ' + ': ' + msg);
    // Add a 'data' event handler to this instance of socket
        // Write the data back to the socket, the client will receive it as data from the server
	//alert(data);
	//console.log("clients : " + wsclients);
	for (var cl = 0; cl < wsclients.length ; cl++)
	    wsclients[cl].emit('message', ab2str(msg));
    });

dServer.on('listening', () => {
  const address = dServer.address();
    console.log(`server listening ${address.address}:${address.port}`);
	});



dServer.bind(PORT, HOST);
*/

console.log('VISUALIMPRO SERVER: ');
httpserver.listen(8080);

console.log('Server listening on ' + HOST +':'+ PORT);


