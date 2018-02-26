#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
const int NMax=4025;

ll A[NMax][NMax];
ll Ans[NMax][NMax];
ll C[NMax][NMax];

void Copy(ll A[NMax][NMax],ll B[NMax][NMax],int N)
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            A[i][j]=B[i][j];
}

void Mul(ll A[NMax][NMax],ll B[NMax][NMax],int N)
{

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
    Copy(A,C,N);
}

void Power(ll A[NMax][NMax],int Exp,int N)
{

    //memset(Ans,0,sizeof(Ans));
    for(int i=0;i<N;i++) Ans[i][i]=1;

    while(Exp)
    {
        if(Exp&1)
        {
            Mul(Ans,A,N);
        }
        Mul(A,A,N);
        Exp=Exp>>1;
    }
    Copy(A,Ans,N);
}

int main()
{
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> A[i][j];
        }
    }
    int Exp;
    cin >> Exp;

    Power(A,Exp,N);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%lld ",A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
