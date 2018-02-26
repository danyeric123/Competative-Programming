"""
    Name    : PVSM Praveen Kumar.
    College : Gayatri Vidya Parishad College of Engineering.
    Problem : SANDWICH.
	Reference :
		1. http://www.dms.umontreal.ca/~andrew/PDF/BinCoeff.pdf
		2. https://github.com/hellman/libnum/blob/master/libnum/modular.py
"""

import math
import operator
from functools import reduce

MAX = int(1e6+25)
Fact = [0]*(MAX+50)
Prime = [True]*(MAX+50)
LPF = [0]*(MAX+50)

def sieve():
    for i in range(2,MAX,2):
        Prime[i] = False
        LPF[i] = 2
    sqt = int(math.sqrt(MAX))
    for i in range(3,sqt,2):
        if(Prime[i]):
            LPF[i] = i
            for j in range(i*i,MAX,i):
                Prime[j] = False
                if(LPF[j] == 0):
                    LPF[j] = i
    Prime[0],Prime[1],Prime[2] = False,False,True
    LPF[0],LPF[1]  = 1,1
    for i in range(2,MAX):
        if(Prime[i]):
            LPF[i]=i


sieve()

def factorize(M):
    factors = []
    while M>1:
        prime = LPF[M]
        power = 0
        while M%prime==0:
            M = M//prime
            power += 1
        factors.append((prime,power))
    return factors


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


def ChineseRemainder(mods,rems,MOD):
    if len(mods)==0 or len(mods) != len(rems):
       return 0
    x = 0
    for i, mod in enumerate(mods):
        if mod == 1:
            continue
        Ni = MOD//mod
        b = modInverse(Ni,mod)
        x += (rems[i]%MOD * Ni%MOD * b%MOD)%MOD
    return x % MOD

def GeneralizedLucas(N,R,Mod):
    factors = factorize(Mod)

    def factPower(x,prime):
        ans = 0
        ppow = prime
        while(ppow<=x):
            ans += x//ppow
            ppow = ppow*prime
        return ans

    def BinomialModPrimePower(N,K,prime,power):
        powr,R = prime**power,N-K
        Fact[0]=1
        for i in range(1,powr):
            if i % prime == 0:
                Fact[i] =  Fact[i-1]
            else:
                Fact[i] = Fact[i-1]*i
            if(Fact[i]>=powr):
                Fact[i] = Fact[i]%powr
        last = Fact[powr-1]
        num,den = 1,1
        neg,dig = 0,0
        while N>0:
            if last != 1 and dig >=power:
                    neg = neg^(N&1)^(R&1)^(K&1)
            num = (num * Fact[N % powr]) % powr
            den = (den * Fact[R % powr]) % powr
            den = (den * Fact[K % powr]) % powr
            N,R,K = N//prime,R//prime,K//prime
            dig += 1
        res = (num * modInverse(den,powr)) % powr
        if prime != 2 or power < 3:
            if neg == 1:
                res = powr - res
        return res

    mods = []
    rems = []
    for (prime,power) in factors:
        primeNCR = factPower(N,prime)-factPower(R,prime) - factPower(N-R,prime)
        poww = power - primeNCR
        if(primeNCR >= power):
            continue
        primepoww = prime**poww
        Res = BinomialModPrimePower(N,R,prime,poww)%primepoww
        x = ((prime**primeNCR)*Res)%(prime**power)
        m = prime**power
        if x != 0:
            rems.append(x)
            mods.append(m)
    return ChineseRemainder(mods,rems,Mod)%Mod

if __name__ == "__main__":
    N,R,m = tuple(map(int,input().split()))
    print (GeneralizedLucas(N,R,m))