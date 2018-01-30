#!/usr/bin/python 
import m04p02

obj = m04p02.LinuxProcList()

procList = obj.procList()
psTree = obj.getPSTree()
cmdLine = {}
for pid in procList:
	cmdLine[pid] = obj.cmdline(pid)

def printChildren(pid, psTree):
	cmd = cmdLine[pid].strip()
	if cmd != "":
		print pid, " ", cmd
	if pid in psTree:
		for child_pid in psTree[pid]:
			if child_pid != pid:
				print "\t",
				printChildren(child_pid, psTree)

for pid in psTree:
	printChildren(pid, psTree)	
		
	 
