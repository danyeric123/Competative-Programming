import math
import operator
from functools import reduce

def ExtendedEuclid(a, b):
    if a == 0: return 0, 1, b
    if b == 0: return 1, 0, a
    px, ppx = 0, 1
    py, ppy = 1, 0
    while b:
        q = a // b
        a, b = b, a % b
        x = ppx - q * px
        y = ppy - q * py
        ppx, px = px, x
        ppy, py = py, y
    return ppx, ppy, a
 
def modInverse(a,M):
    if(M==1):
        return 0
    x, y, g = ExtendedEuclid(a, M)
    if(x<0):
        x += M
    return x

def getRes(N,p):
    if(N==0):
        return 0
    p1 = p
    x1 = ((pow(4,N+1,p1)-1)%p1 * modInverse(3,p1))%p1
    y1 = 0
    rx = int(math.log(N,2))
    for i in range(0,rx+1):    
        y1 = y1+pow(2,pow(2,i),p1)
        y1 = y1%p1
    res = (x1*y1)%p1
    return res%p1

N = int(input())
print (getRes(N,10))
        
