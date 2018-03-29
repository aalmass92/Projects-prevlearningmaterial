import socket
import threading
import datetime

bind_ip   = "0.0.0.0"
bind_port = 2013

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server.bind((bind_ip,bind_port))

#server.listen(5)

print "[*] Listening on %s:%d" % (bind_ip,bind_port)

# this is our client handling thread
#def handle_client(client_socket):

    # just print out what the client sends
   # request = client_socket.recv(1024)
    
    print "[*] Received: %s" % request    

    # send back a packet
    #client_socket.send("ACK!")
   # print client_socket.getpeername()
   # client_socket.close()


while True:

    #client,addr = server.accept()
    
   # print "[*] Accepted connection from: %s:%d" % (addr[0],addr[1])

    # spin up our client thread to handle incoming data
    #client_handler = threading.Thread(target=handle_client,args=(client,))
   # client_handler.start()
    udp, csocket = sever.recvfrom(4096)
    sent = server.sendto('%s' % datetime.datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S'), csocket)

