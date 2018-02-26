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

ll ModInverse1(ll N,ll P){
      return PowerMod(N,P,P-2);
}

ll ModInverse2(ll N, ll m)
{
    if(gcd(N,m)!=1)  //they must be co-primes.
      return -1;

    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if (m == 1)
      return 0;
    while (N > 1)
    {
        q = N / m;
        t = m;
        m = N % m, N = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
       x1 += m0;
    return x1;
}


int main()
{
     printf("%lld",ModInverse2(7,4));

     return 0;
}


