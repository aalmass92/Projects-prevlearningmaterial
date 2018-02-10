from ctypes import *
import os
import sys

pid = os.getpid()
file_name ="/proc/"+str(pid)+"/stat"
        
f = open(file_name,'r')
filedata = f.read()
info_list = filedata.split()

test = cdll.LoadLibrary("libprintproc.so")

test.printproc(info_list[2][0],int(info_list[3]), int(info_list[7]), int(info_list[25]), int(info_list[26]), int(info_list[27]), int(info_list[28]), int(info_list[29])) 
