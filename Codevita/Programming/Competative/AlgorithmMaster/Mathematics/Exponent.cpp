#include<bits/stdc++.h>
using namespace::std;

#define ll  long long
#define ull unsigned ll
#define LD long double

#define mp make_pair
#define bs binary_search
#define gcd __gcd
#define pb push_back
#define pp pop_back
#define ff first
#define ss second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

#define rf freopen("input.txt","r",stdin)
#define wf freopen("output.txt","w",stdout)

#define Nitro ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define clk clock_t tStart = clock()
#define xtime printf("Execution Time : %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC)

#define sz(a) (int)a.size()


ll Power(ll Base,ll Exp)
{
   ll Ans=1LL;
   while(Exp>0)
   {
      if(Exp&1LL)
         Ans = (Ans*Base);
      Exp = Exp >> 1LL;
      Base = (Base*Base);
   }
   return Ans;
}

ll PowerMod(ll Base,ll Exp){
    if(Base>MOD)
        Base = Base%MOD;
    ll Ans = 1;
    while(Exp>0){
        if(Exp&1)
            Ans = (Ans*Base)%MOD;
        Base = (Base*Base)%MOD;
        Exp = Exp >> 1LL;
    }
    Ans = (Ans%MOD+MOD)%MOD;
    return Ans;
}

ll PowerMod(ll Base,ll Exp,ll Mod){
    ll Ans = 1LL;
    Base = Base%Mod;
    while(Exp>0){
        if(Exp&1LL)
            Ans = (Ans*Base)%Mod;
        Exp = Exp >> 1LL;
        Base = (Base*Base)%Mod;
    }
    return Ans;
}


int main()
{
     printf("%lld",Power(3,3));

     return 0;
}


