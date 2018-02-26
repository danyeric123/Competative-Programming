import random
from fractions import gcd 

def brent(N):
        if N%2==0:
                return 2
        y,c,m = random.randint(1, N-1),random.randint(1, N-1),random.randint(1, N-1)
        g,r,q = 1,1,1
        while g==1:             
                x = y
                for i in range(r):
                        y = ((y*y)%N+c)%N
                k = 0
                while (k<r and g==1):
                        ys = y
                        for i in range(min(m,r-k)):
                                y = ((y*y)%N+c)%N
                                q = q*(abs(x-y))%N
                        g = gcd(q,N)
                        k = k + m
                r = r*2
        if g==N:
                while True:
                        ys = ((ys*ys)%N+c)%N
                        g = gcd(abs(x-ys),N)
                        if g>1:
                                break
         
        return g    
def Factor(N):
        Res = 1
        while(N!=1):
                x = brent(N)
                print(x,N)
                c = 1
                while(N%x==0):
                        N = N//x
                        c = c+1
                Res = Res*c
        return Res

import random
def FermatPrimeTest(N,Iterations):
    if(N<2): return 0;
    if(N==2): return 1;
    if(N%2==0): return 0;

    for i in range(0,Iterations):
        a=int(random.randint(2,N-1));
        if(pow(a,N-1,N)!=1):
            return 0;
    return 1

if __name__ == "__main__":
        T = int(input())
        A,B = map(int,input().split())
        Count = 0
        for i in range(A,B+1):
                Count = Count + FermetPrimeTest(Factor(i),10)
        print(Count)
