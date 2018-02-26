#include<bits/stdc++.h>
using namespace::std;
const int SMax = 1e8+5; // All prime numbers up to this
const int SMby2 = SMax/2;
const int Ssqt = sqrt(SMax);
char a[SMax/16+2];
#define isprime(n) (a[(n)>>4]&(1<<(((n)>>1)&7)))

void sieve()
{
	int i,j;
	memset(a,0xFF,sizeof(a));
	a[0]=(char)0xFE;
	for(i=1;i<Ssqt;i++)
		if (a[i>>3]&(1<<(i&7)))
			for(j=i+i+i+1;j<SMby2;j+=i+i+1)
				a[j>>3]&=~(1<<(j&7));
}

int main()
{
    sieve();
	return 0;
}
