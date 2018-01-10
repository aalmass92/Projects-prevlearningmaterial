#!/usr/bin/python

import socket

f = open("/proc/meminfo","r")

print "Hostname:",( socket.gethostname()), (f.read())
