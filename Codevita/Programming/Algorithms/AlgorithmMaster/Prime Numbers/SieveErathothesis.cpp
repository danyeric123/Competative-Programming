#include<bits/stdc++.h>
using namespace::std;
const int MAX = 1e8;
bool Prime[MAX+25];

void sieve()
{
    int i,j;
    memset(Prime,1,sizeof(Prime));
    Prime[0]=Prime[1]=0;
    for(i=2;i<=sqrt(MAX);i+=2)Prime[i]=0;
    for(i=3;i<=sqrt(MAX);i+=2) {
        if(Prime[i])
            for(j=i*i;j<=MAX;j+=i)
                Prime[j]=0;
    }
}


int main()
{
    sieve();
    return 0;
}
