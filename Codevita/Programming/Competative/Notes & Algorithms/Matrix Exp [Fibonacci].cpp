#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2;
const int M=1e9+7;
ll a,b;

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
                C[i][j]=(C[i][j]%M+((ll)A[i][k]*(ll)B[k][j])%M)%M;
            }
        }
    }
    Copy(A,C);
}

void Power(ll A[N][N],int Exp)
{
    ll Ans[2][2]={{1,0},{0,1}};

    while(Exp)
    {
        if(Exp&1)
        {
            Mul(Ans,A);
        }
        Mul(A,A);
        Exp=Exp>>1;
    }
    Copy(A,Ans);
}

ll Solve(int n)
{
    if(n==1)
        return a;
    if(n==2)
        return b;

    ll A[2][2]={{1,-1},{1,0}};
    Power(A,n-2);

    ll Res = (((ll)A[0][0]%M*(ll)b%M)%M + ((ll)A[0][1]%M*(ll)a%M)%M)%M;

    while(Res<0)
        Res = (Res+M)%M;

    return Res;

}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%lld %lld %d",&a,&b,&n);
        printf("%lld\n",Solve(n));
    }
    return 0;
}


