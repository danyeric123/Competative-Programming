#include<bits/stdc++.h>
using namespace::std;

#define ll  long long
#define ull unsigned ll
#define LD long double

#define mp make_pair
#define bs binary_search
#define gcd __gcd
#define pb push_back
#define pp pop_back
#define ff first
#define ss second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

bool happy[1001];
ll digitsum(ll x){
    ll sum = 0;
    while(x > 0){
        ll r = x%10;
        sum += r*r;
        x = x/10;
    }
    return sum;
}
bool demant(ll N){
    unordered_set<ll> sset;
    while(true){
        if(N == 1) return true;
        if(sset.find(digitsum(N)) != sset.end()) return false;
        N = digitsum(N);
        sset.insert(N);
    }
    return true;
}
void pre(){
    happy[1] = true;
    for(ll i=1;i<=1000;i++){
        happy[i] = demant(i);
    }
}
int main(){
    pre();
    int T = 1000;
    while(T--){
        for(ll i=1000;i<=1099;i++){
            if(happy[digitsum(i)]){
                cout << i << endl;
            }
        }
    }
}
