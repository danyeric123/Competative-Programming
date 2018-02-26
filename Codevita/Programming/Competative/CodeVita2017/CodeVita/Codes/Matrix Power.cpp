#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
const int NMax=4025;

ll Arr[NMax][NMax];

ll PowerMod(ll Base,int Exp,int Mod)
{
	ll Ans=1LL;
	while(Exp>0)
	{
		if(Exp&1) Ans=(Ans*Base)%Mod;
		Exp = Exp>>1;
		Base = (Base*Base)%Mod;
	}
	return Ans;
}


int main()
{
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> Arr[i][j];
        }
    }
    int Exp;
    cin >> Exp;

    ll Result = 1LL;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Result = ((Result%M)*PowerMod(Arr[i][j],Exp,M) + M)%M;
        }
    }

    cout << Result << endl;

    return 0;
}
