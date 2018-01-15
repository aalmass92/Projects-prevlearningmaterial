#!/usr/bin/python

import sys

while 1:
 inputing = raw_input("Calc:")

 if inputing == "exit":
  break

 x,y,op = inputing.split(" ")

 if op == "times":
  answer = int(x)*int(y) 
  print x,"x",y,'=' ,answer
 
 elif op == "minus":
  answer2 = int(x)-int(y)
  print x,"-",y,"=",answer2

 elif op == "plus":
  answer3 = int(x)+int(y)
  print x,"+",y,"=",answer3
