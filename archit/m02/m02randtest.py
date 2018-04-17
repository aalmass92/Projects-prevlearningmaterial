#!/usr/bin/python

import sys, random

typeofbit = sys.argv[1]

if typeofbit == 'b':
    print hex(int(random.getrandbits(8))) 

elif typeofbit == 'w':
    print hex(int(random.getrandbits(16)))

elif typeofbit == 'd':
    print hex(int(random.getrandbits(32)))

elif typeofbit == 'q':
    print hex(int(random.getrandbits(64)))


#print random.getrandbits(8)
