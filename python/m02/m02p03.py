#!/usr/bin/python

import keyword

i = 0
j = 0

keylist = keyword.kwlist

for i in range(len(keylist)):
 print keylist[i]
 i+=1

for j in reversed(range(len(keylist))):
 print keylist[j]
 i-=1
