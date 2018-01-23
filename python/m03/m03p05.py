#!/usr/bin/python 

import sys 

def hexdump( chars, sep, width ):
	i = 0
	total = len(chars)
	while chars: 
		print "[%0.8x]: " % (i * width),
		i = i + 1
		line = chars[:width] 
		chars = chars[width:] 
		line = line.ljust( width, '\000' ) 
		print "%s%s%s" % ( sep.join( "%02x" % ord(c) for c in line),sep,quotechars( line )) 
	print "Total Length %d (%0.2xh)" % (total, total)

def quotechars( chars ):
	return ''.join( ['.', c][c.isalnum() ] for c in chars ) 

def file_section( name): 
	contents = open( name, "rb" ).read() 
	return contents 

if __name__ == '__main__': 
	hexdump( file_section( sys.argv[1]),' ', 16) 
	
