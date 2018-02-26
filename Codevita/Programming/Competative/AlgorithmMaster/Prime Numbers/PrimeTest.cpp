#include<bits/stdc++.h>
using namespace::std;
typedef long long ll;

bool PrimeI(ll x){
    if(x==2 || x==3) return 1;
    if(x<=1 || x%2==0 || x%3==0) return 0;
    if(x%6!=1 && x%6!=5) return 0;
    ll i=5;
    while(i*i<=x){
        if(x%i==0 || x%(i+2)==0) return 0;
        i+=6;
    }
    return 1;
}

int PrimeII(ll x)
{
    if(x<=1)return 0;
    if(x<=3)return 1;
    if(x%6==1||x%6==5){
        ll y=sqrt(x);
        for(ll i=2;i<=y;i++)
            if(x%i==0)
            return 0;
        return 1;
    }
    return 0;
}



int main()
{
    for(int i=1;i<=10000;i++){
        if(PrimeI(i))
           cout << i << endl;
    }
    return 0;
}
