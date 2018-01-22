#!/usr/bin/python

def pascal(row,col):
    if (col == 0): # for the fist colum number is 1
        return 1
    else:
        if (row == col): # for the last element row is 1
            return 1
        else:
            return pascal(row-1,col) + pascal(row-1,col-1) # forumula uses the number calculate number in inbetween first and last 

def print_pascal(num_rows):
    for i in range(0,num_rows): # for loop ranges from what ever number of rows
        for space in range(0,num_rows - i): #forloop prints space for each row 
            print " ", 
        for j in range(0,i+1): # for loop for number of col in each row 
            print pascal(i,j), # prints pascal numbers for rows and colum
            print " ", # print space inbetween the pascal numbers
        print "\n", # print new line after row complete
print_pascal (10)
