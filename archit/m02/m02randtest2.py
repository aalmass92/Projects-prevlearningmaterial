#!/usr/bin/python

import sys, random

bit = raw_input('Type "b" will generate a byte(8), "w" will generate a word(16), "d" will generate a double word(32 bits), "q" will generate a quad word (64 bits)')

if bit == 'b':
    print hex(int(random.getrandbits(8))) 

elif bit == 'w':
    print hex(int(random.getrandbits(16)))

elif bit == 'd':
    print hex(int(random.getrandbits(32)))

elif bit == 'q':
    print hex(int(random.getrandbits(64)))


#print random.getrandbits(8)
