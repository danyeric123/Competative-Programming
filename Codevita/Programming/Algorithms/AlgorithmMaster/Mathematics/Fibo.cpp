#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2;
const int MOD=1e9+7;

void Copy(ll A[N][N],ll B[N][N])
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            A[i][j]=B[i][j];
}

void Mul(ll A[N][N],ll B[N][N])
{
    ll C[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            C[i][j]=0;
            for(int k=0;k<N;k++)
            {
                C[i][j]=(C[i][j]+(ll)A[i][k]*(ll)B[k][j])%MOD;
            }
        }
    }
    Copy(A,C);
}

void Power(ll A[N][N],ll Exp)
{
    ll Ans[2][2]={{1,0},{0,1}};

    while(Exp)
    {
        if(Exp&1)
        {
            Mul(Ans,A);
        }
        Mul(A,A);
        Exp = Exp >> 1LL;
    }
    Copy(A,Ans);
}

ll Solve(ll N,ll a,ll b)
{
    if(N==0)
        return a;
    if(N==1)
        return b;

    ll A[2][2]={{1,1},{1,0}};
    Power(A,N-1);

    return (  A[0][1]);
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

    for(int i=0;i<10;i++){
      cout << Solve(i,1,1) << endl;
    }
    return 0;
}
