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

vector<ll> MyVec;

bool CanSum(ll N,ll sum)
{
   if (sum == 0)
     return true;
   if (N == 0 && sum != 0)
     return false;

   if (MyVec[N-1] > sum)
     return CanSum(N-1,sum);

   return CanSum(N-1, sum) || CanSum(N-1,sum-MyVec[N-1]);
}


int main()
{
    ll N,Ai;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> Ai;
        MyVec.pb(Ai);
    }
    sort(MyVec.begin(),MyVec.end());
    ll Sum;
    cin >> Sum;
    bool ok = CanSum(N,Sum);

    if(ok && Sum!=0)
        printf("True");
    else
        printf("False");
}



