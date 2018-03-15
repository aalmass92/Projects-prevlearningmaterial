import sys
# Read in the DLL

Filename = raw_input("Name of the File: ")

dll = raw_input("Enter dll: ")

fd = open(Filename, "rb" )
dll_contents = fd.read()
fd.close()

print "[*] Filesize: %d" % len( dll_contents )

# Now write it out to the ADS
fd = open( "%s:%s" % ( dll, Filename ), "wb" )
fd.write( dll_contents )
fd.close()
