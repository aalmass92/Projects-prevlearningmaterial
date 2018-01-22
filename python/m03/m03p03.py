#!/usr/bin/python

import os,sys, time
from stat import *

def file_info(FileName):
    try:
        file_st = os.stat(FileName)
    except:
        print "Failed to get informaiton about file"
    else:
        print "File Name:" + FileName
        print "File Size:" + str(file_st[ST_SIZE])
        print "Inode  :" + str(file_st[ST_INO])
        print " Last Mod : " + time.asctime(time.localtime(file_st[ST_MTIME]))

if len(sys.argv) < 2:
    print "Please provide the file name"
else:
    file_info(sys.argv[1])

