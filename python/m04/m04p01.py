#!/usr/bin/python 
import sys
class LinuxProcess:
    def __init__(self, pid):
        self.file_name ="/proc/"+str(pid)+"/stat"
        self.info_list = []
        
    def readfile(self):
        f = open(self.file_name,'r')
        filedata = f.read()
        self.info_list = filedata.split()

    def printStats(self):
        self.readfile()
        print "%20s" % "name: ", "%20s" % self.info_list[1] 
        print "%20s" % "rss_lim: ","%20s" % hex(int(self.info_list[24])) 
        print "%20s" % "start_code: ","%20s" % hex(int(self.info_list[25])) 
        print "%20s" % "end_code: ", "%20s" % hex(int(self.info_list[26])) 
        print "%20s" % "start_stack: ","%20s" % hex(int(self.info_list[27]))
        print "%20s" % "esp: ","%20s" % hex(int(self.info_list[28])) 
        print "%20s" % "eip: ","%20s" % hex(int(self.info_list[29])) 
        print "%20s" % "start_data: ","%20s" % hex(int(self.info_list[44])) 
        print "%20s" % "end_data: ","%20s" % hex(int(self.info_list[45])) 
        print "%20s" % "start_brk: ","%20s" % hex(int(self.info_list[46])) 
        print "%20s" % "arg_start: ","%20s" % hex(int(self.info_list[47])) 
        print "%20s" % "arg_end: ","%20s" % hex(int(self.info_list[48])) 
        print "%20s" % "env_start: ","%20s" % hex(int(self.info_list[49])) 
        print "%20s" % "env_end: ","%20s" % hex(int(self.info_list[50]))

if (len(sys.argv) < 2):
    print "Error: Please provide a pid"
else:
    obj = LinuxProcess(int(sys.argv[1]))
    obj.printStats()
