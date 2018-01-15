#!/usr/bin/python

import sys

x = input("First Number:")

y = input ("Second Number:")

op = raw_input("Operation:")

sum = int(x + y)

ti = int(x * y)

min = int(x - y)

div = int(x / y)

if op == 'times':
 print x,'x',y,'=' ,ti  

elif op == 'minus':
 print x,'-',y,'=',min

elif op == 'plus':
    print x,'+',y,'=',sum

