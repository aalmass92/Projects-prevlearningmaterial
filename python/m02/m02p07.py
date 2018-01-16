import pwd

#!/usr/bin/python


#def print_user_line(username):
 #   if username == "None":
print "+-----------+--------------------------+"
       # return
for p in pwd.getpwall():
      print"| " ,p[0],"|"

print "+-----------+--------------------------+"
