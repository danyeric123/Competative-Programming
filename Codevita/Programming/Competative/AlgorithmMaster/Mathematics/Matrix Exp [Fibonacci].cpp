#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2;
const int MOD=1e9+7;
const int cons = MOD;
unordered_map<ll ,ll >fibo;
ll fib(ll b)
{
	if(b<=0)
		return 0;
	if(b==1||b==2)
		return 1;
	if(fibo[b])
		return fibo[b];
	return fibo[b]=(fib(b/2+1)*fib(b-b/2)+fib(b/2)*fib(b-b/2-1))%MOD;
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
      int T;
      cin >> T;
      while(T--){
            ll N;
            cin >> N;
            ll Re = fib(N+2);
            ll Res = (PowerMod(2,N,MOD)- Re+MOD)%MOD;
            cout << Res << endl;
      }

    return 0;
}
