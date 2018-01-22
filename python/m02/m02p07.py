#!/usr/bin/python

import subprocess

def parser(test_str):
    start_idx = 0
    end_idx = 0
    user_list = []

    for i in range(0,len(test_str)):
        if(test_str[i] == '\n'):
            end_idx = i
            user_str = test_str[start_idx:end_idx]
            user_list.append(user_str)
            start_idx = i+1
    return user_list


output = subprocess.check_output(['ls', '/home'])
user_list = parser(output)
print ('+----------------------+----------------------------+')
for username in user_list :
       print('| %-20s | /home/%-20s |' % (username,username))
print ('+----------------------+----------------------------+')

