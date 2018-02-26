from __future__ import print_function
inp = raw_input()
lis = inp.split(' ')
for st in lis:
    for i in range(len(st)):
        size = ord(st[i])-64
        if(i%2==0):
            print("0"*size,end='')
        else:
            print("!"*size,end='')
    print("")