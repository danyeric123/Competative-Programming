#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e3+9;
const int MAX = 1e3+10;
typedef long long ll;
ll ModI[MAX+1];
ll FactI[MAX+1];
ll PowerMod(ll Base,ll Exp)  //Fermat Theorem
{
    ll Ans=1;
    Base=Base%MOD;
    while(Exp)
    {
        if(Exp&1)
        {
            Ans=(Ans*Base)%MOD;
        }
        Exp = Exp>>1;
        Base=(Base*Base)%MOD;
    }
    return Ans;
}



int main()
{
    int i,T,N,R;
    unsigned long long n,r;
    Fact();
    int k;
    cin >> n >> k;
    long long int Res;
    long long Ans = 0;
    for(int i=0;i<=K;i++){
            Res  = Fact[N];
            ll X = FactI[N-R];
            ll Y = FactI[R];
            Res=(PowerMod(X,MOD-2))%MOD;
            Res=Res*PowerMod(Y,MOD-2);
            Res*=FactI[N];
            Res%=MOD;

        if(i%2==0){
            Ans = Ans + Res;
        }
    }

    cout << Ans << endl;
    return 0;
}
