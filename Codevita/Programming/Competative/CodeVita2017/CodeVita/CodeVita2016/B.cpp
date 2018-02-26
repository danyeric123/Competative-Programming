#pragma warning(suppress: 4101)
#include<bits/stdc++.h>
using namespace::std;

#define ll  long long
#define ull unsigned ll
#define LD long double

#define MP make_pair
#define BS binary_search
#define GCD __gcd
#define pb push_back
#define pp pop_back
#define F first
#define S second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

const int Max = 1e5+25;
ll Arr1[Max],Arr2[Max];
int main()
{
	ll T,N,K,i;

    ll Sum=0;
    scanf("%lld %lld",&N,&K);
    for(i=0;i<N;i++)
        scanf("%lld",&Arr1[i]);
    for(i=0;i<N;i++)
    {
        scanf("%lld",&Arr2[i]);
        Sum = Sum + 1LL*Arr1[i]*Arr2[i];
    }
    ll x,y,Temp;
    ll Max=Sum;
    for(i=0;i<N;i++)
    {
        Temp =Sum-Arr1[i]*Arr2[i];
        x = Temp + 1LL*(Arr1[i]+2*K)*Arr2[i];
        y = Temp + 1LL*(Arr1[i]-2*K)*Arr2[i];
        Max = min(Max,min(x,y));
    }
    printf("%lld",Max);

	return 0;
}
