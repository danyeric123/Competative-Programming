#include<bits/stdc++.h>
using namespace::std;
#define ll long long
ll dp[1005][1005];
ll digits[] = {1,2,3,1};
const int mod = 1e9+7;
ll recur(int index,int sum){
    if(index == 0) return (sum == 0);
    if(index < 0 || sum < 0) return 0LL;
    if(dp[index][sum] != -1) return (dp[index][sum]%mod+mod)%mod;
    ll res = 0;
    for(int i=0;i<4;i++){
        res += recur(index-1,sum-digits[i]);
        res = (res%mod+mod)%mod;
    }
    dp[index][sum] = (res%mod+mod)%mod;
}
ll Res[10005];
int main(){
    int T,N;
    memset(dp,-1,sizeof(dp));
    T = 10000;
    for(int N = 0;N<=1000;N++){
        ll res = 0;
        for(int i=1;i<=N;i++){
            res = (res%mod+recur(i,N))%mod;
        }
        Res[N] = res;
    }
    freopen("cntKid2.txt","w",stdout);
    for(int i=0;i<=1000;i++){
        cout << Res[i] << endl;
    }
}
