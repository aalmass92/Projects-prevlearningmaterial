import sys
x = int(sys.argv[1])

y = int(sys.argv[2])

op = sys.argv[3]

sum = int(x + y)

ti = int(x * y)

min = int(x - y)

div = int(x / y)

if op == 'times':
 print ti  

elif op == 'minus':
 print (min)

elif op == 'plus':
    print (sum )
