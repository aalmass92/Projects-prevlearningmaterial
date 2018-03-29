import socket

target_host = "10.185.192.163";
target_port = 2013;

#create the socket
socket = socket.socket(AF_INET, SOCK_DGRAM, SOL_UDP);

#connect the client
socket.socket(socket, target_host, target_port);

#send some data
socket.sendto(socket, "AAABBBCCC" , 100 , 0 , target_host , target_port);

#receive some data
response = socket_recvfrom(socket, buf, 4096, 0, client_host, client_port);
