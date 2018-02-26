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
#define ff first
#define ss second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define sz(a) (int)a.size()

vector<ll> vec(6);
ll arr[20],i,j,N;

int main() {
// your code goes here

    scanf("%lld",&N);
    for(i=0;i<N-1;i++) {
       scanf("%lld,",&arr[i]);
    }
    scanf("%lld",&arr[i]);
    sort(arr,arr+N,greater<ll>());
    vec[0]=arr[4];
    vec[1]=arr[2];
    vec[2]=arr[1];
    vec[3]=arr[0];
    vec[4]=arr[3];
    vec[5]=arr[5];
    for(i=4;i>0;i--){
        for(j=0;j<=i;j++){
            vec[j]+=vec[j+1];
        }
    }
    ll res = 1LL*vec[0]*1LL*vec[1];
    printf("%lld",res);
    return 0;
}

