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

const int MAX = 1e6+144;
bool Prime[MAX+144];
int dp[MAX+144],dp2[MAX+144];
void sieve(){
    int i,j;
    memset(Prime,1,sizeof(Prime));
    Prime[0]=Prime[1]=0;
    for(i=2;i<=MAX;i+=2) {Prime[i]=0;}
    for(i=3;i<=sqrt(MAX);i+=2) {
        if(Prime[i]){
            for(j=i*i;j<=MAX;j+=i){
                Prime[j]=0;
            }
        }
    }
    Prime[2] = 1;
    Prime[0] = Prime[1] = 0;
    for(int i=2;i<=MAX;i++){
        dp[i] += dp[i-1] + Prime[i];
        dp2[i] += dp2[i-1] + Prime[dp[i]];
    }
}

int main(){
    sieve();
    int T;
    cin >> T;
    while(T--){
        int L,R;
        cin >> L >> R;
        cout << dp2[R] - dp2[L-1] << endl;
    }


}

