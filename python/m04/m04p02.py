#!/usr/bin/python 
import os
import os.path

class LinuxProcList:
	def __init__(self):
		self.pidlist = []
		self.pstree = None
	
	def procList(self):
		location = "/proc/"
		for d in os.listdir(location):
			if (d.isdigit()):
				self.pidlist.append(d)
		return self.pidlist

	def cmdline(self, pid):
		cmdfile = "/proc/" + str(pid) + "/cmdline"
	 	if (os.path.exists(cmdfile)):
			f = open(cmdfile, 'r')
			cmd = f.read()
			f.close()
			return cmd
		else:
			return "None"
 	
	def getPPID(self, pid):
		statfile = "/proc/" + str(pid) + "/stat"
		if (os.path.exists(statfile)):
			f = open(statfile, 'r')
			contents = f.read()
			statlist = contents.split()
			f.close()
			return str(statlist[3])
		else:
			return ""
		
	def createPSTree(self):
		self.pstree= {}		
		for pid in self.pidlist:
			ppid = self.getPPID(pid)
			if (ppid != ""):
				if ppid == '0':
					ppid = str(pid)
				if ppid in self.pstree:
					self.pstree[ppid].append(pid)
				else:
					self.pstree[ppid] = [pid]
			else:
				self.pstree[pid] = [pid]
	
	def findChildren(self, pid):
		if self.pstree == None:
			self.createPSTree()
		if pid in self.pstree:
			return self.pstree[pid]
		else:
			return None
	
	def getPSTree(self):
		if self.pstree == None:
			self.createPSTree()
		return self.pstree

obj = LinuxProcList()
print "The process list is : ",obj.procList()
        
process_id = raw_input("Enter the process id: ")
print "Command line for the pid", process_id,": ", obj.cmdline(process_id)        

print " The Children for the pid", process_id," ", obj.findChildren(process_id)

