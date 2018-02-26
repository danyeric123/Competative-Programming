#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll MulMod(ll A,ll B,ll Mod)
{
    ll x=0,y=A%Mod;
    while(B>0)
    {
        if(B&1)
            x=(x+y)%Mod;
        y=(y*2)%Mod;
        B=B/2;
    }
    return x%Mod;
}

ll PowerMod(ll Base,ll Exp,ll Mod)
{
    ll Ans=1;
    Base = Base%Mod;
    while(Exp>0)
    {
        if(Exp&1) Ans=MulMod(Ans,Base,Mod);
        Base=MulMod(Base,Base,Mod);
        Exp = Exp>>1LL;
    }
    return Ans;
}

bool FermatPrimeTest(ll N,ll Iterations)
{
    if(N==1)
        return 0;
    srand(time(NULL));
    for(ll i=0;i<Iterations;i++)
    {
        ll a=rand()%(N-1)+1;
        if(PowerMod(a,N-1,N)!=1)
             return 0;
    }
    return 1;
}

int main()
{
    int T;
    ll N,i;
    scanf("%d",&T);
   /*
    for(i=2;i<5000;i++)
    {
        if(FermatPrimeTest(i,150)) printf("%d ",i);
    }
    */

    while(T--)
    {
        scanf("%lld",&N);
        if(FermatPrimeTest(N,5)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
