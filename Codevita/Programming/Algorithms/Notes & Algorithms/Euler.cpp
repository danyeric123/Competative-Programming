#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6+1;
int Prime[MAX],HFact[MAX];
long int Euler[MAX];
void sieve()
{
    int i,j,K;
    Prime[0]=Prime[1]=1;
    Euler[1]=1;     Euler[2]=1;
    HFact[0]=1;     HFact[1]=1;
    int sqt=sqrt(MAX);
    for(i=2;i<sqt;i++)
    {
        if(!Prime[i])
        {
            Euler[i]=i-1;
            K=i;
            for(j=i*i;j<MAX;j+=i)
            {
                Prime[j]=1;
                HFact[j]=i;
                if(K*i < MAX)
                {
                    Euler[K*i]=K*i-K;
                    K=K*i;
                }
            }
        }
    }
    for(i=sqt;i<MAX;i++)
    {
        if(!Prime[i])
        {
            Euler[i]=i-1;
        }
    }
}
int Calc(int N)
{
        int A,K;
        int Ans=1;
        while(N>1)
        {
            A=1;
            K=HFact[N];
            while(!(N%K))
            {
                N=N/K;
                A=A*K;
            }
            Ans=Ans*Euler[A];
            if(Euler[N])
            {
                break;
            }
        }
        Ans=Ans*Euler[N];
        return Ans;
}
int main()
{
    int i,T;
    sieve();
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        if(!Euler[N])
            Euler[N]=Calc(N);
        printf("%d\n",Euler[N]);
    }
    return 0;
}
