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

vector<int> Series;
vector<string> Result;
void Pre()
{
    int Ele=0;
    for(int i=2;i<=300;i+=2){
        Ele = i*(2*i-1);
        Series.push_back(Ele);

        string res = to_string(Ele);
        if(res.size()==1)
            Result.push_back("0000"+res);
        else if(res.size()==2)
            Result.push_back("000"+res);
        else if(res.size()==3)
            Result.push_back("00"+res);
        else if(res.size()==4)
            Result.push_back("0"+res);
        else
            Result.push_back(res);
    }
}

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
