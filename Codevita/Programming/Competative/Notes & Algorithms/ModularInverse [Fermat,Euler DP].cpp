#include<bits/stdc++.h>
using namespace std;

const int MOD=1000000009;
long int ModInverse[200001];

long int PowerMod(int Base,int Exp)
{
    int Ans=1;
    Base=Base%MOD;
    while(Exp>0)
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

void DpModInv(int N)
{
    int i;
    ModInverse[1]=1;
    for(i=2;i<N;i++)
    {
        ModInverse[i]=( -(long long)(MOD/i)*(long long)ModInverse[MOD%i]) % MOD + MOD;
    }
}

int main()
{
    int i,N;
//    scanf("%d",&N);
    PreModInv(200001);

    for(i=1;i<200001;i++)
    {
        printf("%d - %d\n",i,ModInverse[i]);
    }
    return 0;
}
