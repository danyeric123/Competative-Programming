/* Recurrance Reations of the form an = b1 an-3 + b2 an-2 + b3 an-1 */
/* Given input a0,a1,a2,b1,b2,b3 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

void Copy(ll A[3][3],ll B[3][3])
{
    for(ll i=0;i<3;i++)
        for(ll j=0;j<3;j++)
            A[i][j]=B[i][j];
}

void Mul(ll A[3][3],ll B[3][3])
{
    ll i,j,k;
    ll C[3][3];

    for(i=0;i<3;i++)
    {
     for(j=0;j<3;j++)
     {
        C[i][j]=0;
        for(k=0;k<3;k++)
        {
            C[i][j]=(C[i][j]+(ll)A[i][k]* (ll) B[k][j])%MOD;
        }
     }
    }
    Copy(A,C);
}
void PowerMod(ll A[3][3],ll Exp)
{
    ll Ans[3][3]={{1,0,0},{0,1,0},{0,0,1}};

    while(Exp)
    {
        if(Exp&1) Mul(Ans,A);
        Mul(A,A);
        Exp = Exp >> 1L;
    }
    Copy(A,Ans);
}

ll Solve(ll N,ll A0,ll A1,ll A2,ll B1,ll B2,ll B3)
{
  //  an = b1 an-3 + b2 an-2 + b3 an-1;
    if(N==0)
        return A0;
    if(N==1)
        return A1;
    if(N==2)
        return A2;

    ll A[3][3]={{B3,1,0},{B2,0,1},{B1,0,0}};
    PowerMod(A,N-2);
    return ( ((ll) A2* (ll) A[0][0])%MOD + ( (ll) A1* (ll) A[1][0])%MOD + ( (ll)A0 * (ll) A[2][0])%MOD )%MOD;

}

int main()
{
    int T,Q;
    long long int A0,A1,A2,B1,B2,B3,N;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld %lld %lld %lld %lld %lld",&B1,&B2,&B3,&A0,&A1,&A2);
        scanf("%d",&Q);
        while(Q--)
        {
            scanf("%lld",&N);
            printf("%lld\n",Solve(N,A0,A1,A2,B1,B2,B3));
        }
    }

    return 0;
}
