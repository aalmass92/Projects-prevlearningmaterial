from immlib import *

class fire (LogBpHook) :
          def __init__(self):
                   self.imm=Debugger();
                   self.logfile = "D:\\fire_log.txt"
#directory where the log file has to be saved
                   LogBpHook.__init__(self)
                  
          def run(self,regs):
                   addr=self.imm.readLong(regs['ESP']+8)
                   str=self.imm.readString(addr)
                   self.imm.log("PR_Write ( 0x%x) <- %s" % (addr,str) )
                   fd = open( self.logfile, "a" )
                   fd.write( str )
                   fd.close()
# this function run automatically when hook is hit and function code is #executed which logs it in to file and displays on log window of debugger
                  
def main(args) :
          imm=Debugger()
          wfun=imm.getAddress("nspr4.PR_Write")
#setup hook point
          fire_hook=fire()
          fire_hook.add( "%08x" % wfun, wfun)
          return "[*] READY for ACTION"
