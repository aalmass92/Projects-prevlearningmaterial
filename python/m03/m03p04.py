#!/usr/bin/python

import subprocess, sys

def process_output(output, fileName):
    lines = output.split('\n')
    endian = ""
    machine = ""
    magicnumber = []
    dataformat = ""
    for line in lines:
        if ("Magic" in line):
            magics = line.split()
            magics = magics[1:]
            magicnumber = magics[0:4]
            if (int(magics[4]) == 1):
                dataformat = "32-bit"
            else:
                dataformat = "64-bit"
            if (int(magics[5]) == 1):
                endian = "little"
            else:
                endian = "big"
        if ("Machine" in line):
            answers = line.split()
            answers = answers[1:]
            machine = " ".join(answers)
    if (endian == "little"):
        magicnumber = magicnumber[::-1]
    magic = "0x"
    for num in magicnumber:
        magic = magic + num
    print "File    : " + fileName
    print "Magic   : " + magic
    print "Format  : " + dataformat
    print "Endian  : " + endian
    print "Machine : " + machine
                

def dumpElf(fileName):
    output = subprocess.check_output(['readelf','--file-header',fileName])
    process_output(output, fileName)

if len(sys.argv) < 2:
    print "ERROR File not found"
else:
    dumpElf(sys.argv[1])
