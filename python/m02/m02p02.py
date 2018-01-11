#!/usr/bin/python

import socket

f = open("/proc/meminfo","r")

mem = f.readline(27).split()

total = float(float(mem[1])/1024)

print "Hostname: "+( socket.gethostname())+",", "Memory:",total, "MB"

