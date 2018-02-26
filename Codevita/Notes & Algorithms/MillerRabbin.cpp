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

ll ModExp(ll Base,ll Exp,ll Mod)
{
    ll Ans=1;
   // Base = Base%Mod;
    while(Exp>0)
    {
        if(Exp&1) Ans=MulMod(Ans,Base,Mod);
        Base = MulMod(Base,Base,Mod);
        Exp = Exp>>1LL;
    }
    return Ans;
}

bool MillerRabinTest(ll N,ll Iterations)
{
    if(N<2) return 0;
    if(N==2) return 1;
    if(N%2==0) return 0;

    ll M = N-1;
    while(M%2==0)
        M=M/2;

    for(int i=0;i<Iterations;i++)
    {
        ll a=rand()%(N-1)+1 , K=M;
        ll Mod = ModExp(a,K,N);
        while(K!=N-1 && Mod!=1 && Mod!=N-1)
        {
            Mod = MulMod(Mod,Mod,N);
            K=K*2;
        }
        if(Mod!=N-1 && K%2==0)
            return 0;
    }
    return 1;
}

int main()
{
    ll T,N,i;
    //for(i=2;i<5000;i++)
      //  if(MillerRabinTest(i,150)) printf("%lld ",i);


    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&N);
        if(MillerRabinTest(N,150)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
