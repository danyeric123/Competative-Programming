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
#define F first
#define S second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

#define rf freopen("input.txt","r",stdin)
#define wf freopen("output.txt","w",stdout)

#define Nitro ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define clk clock_t tStart = clock()
#define xtime printf("Execution Time : %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC)
ll Res = 0;
ll N,K;
const int Mod = 1e9+7;

ll MulMod(ll A,ll B)
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

ll PowerMod(ll Base,ll Exp)
{
    ll Ans=1;
    Base = Base%Mod;
    while(Exp>0)
    {
        if(Exp&1) Ans=MulMod(Ans,Base);
        Base=MulMod(Base,Base);
        Exp = Exp>>1LL;
    }
    return Ans;
}

int main()
{
    cin >> N >> K;
    ll Num = 1;
    ll Den = 1;
    Res = 1;
    ll Mul,NcR;
    for(ll i=0;i<K;i++){
    	
    	Mul = (N-i)%Mod;
    	Num = MulMod(Num,Mul);
    	
    	Mul = (i+1)%Mod;
    	Den = MulMod(Den,Mul);
    	//cout << Num << " " << Den << endl;
    	NcR = MulMod(Num,PowerMod(Den,Mod-2));

    	NcR = (NcR +Mod)%Mod;
    	if(i&1){
    		//cout << NcR  << endl;
    		Res += NcR;
    	}
    }

    cout << Res << endl;
	return 0;
}
