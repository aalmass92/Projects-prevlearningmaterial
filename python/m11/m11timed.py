#!/usr/bin/python
import socket
import threading
import datetime
bind_ip   = "0.0.0.0" #	The ip address will always be different!!
bind_port = 2013
server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM) 
server.bind((bind_ip,bind_port))
#server.listen(5)
print "[*] UDP Listening on %s:%d" % (bind_ip,bind_port)
#def handle_client(client_socket):
	#request = client_socket.recv(1024)
        #print "[*] Received: %s" % request
        #client_socket.send()
        #client_socket.close()
while True:
	#client,addr = server.accept()
     	#print "[*] Accepted connection from: %s:%d" % (addr[0],addr[1])
     	#client_handler = threading.Thread(target=handle_client,args=(client,))
    	#client_handler.start()
	udp, csocket = server.recvfrom(4096)  
	sent = server.sendto('%s' % datetime.datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S'), csocket)
	#sent = server.sendto("hello",csocket) 
