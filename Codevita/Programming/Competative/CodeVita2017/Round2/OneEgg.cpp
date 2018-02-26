#include<bits/stdc++.h>
using namespace::std;

#define ll  long long
#define ull unsigned ll
#define LD long double

#define mp make_pair
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

vector<ll> Vec;
vector<ll> Res;
vector<pair<ll,int> > srt;

bool cmp(const pair<ll,ll> &lhs, const pair<ll,ll> &rhs) {
    if(lhs.ff ==  rhs.ff) {
        return lhs.ss < rhs.ss;
    }
    return lhs.ff > rhs.ff;
}

ll M,X,x;
ll sum = 0;

int main(){

    cin >> M >> X;
    for(int i=0;i<M;i++){
        cin >> x;
        Vec.pb(x);
        Res.pb(0);
        srt.pb(mp(x,i));
        sum += x;
    }
    ll req = min(X,sum-1);
    sort(srt.begin(),srt.end(),cmp);

    if( X < sum){
        printf("Thank you, your order for %lld eggs are accepted\n",X);
        for(ll i=0;i<(int)srt.size();i++){
            int idx = srt[i].ss;
            ll dec = srt[i].ff;
            if(dec <= req){
                req -= dec;
                Res[idx] = Vec[idx];
            }
            else{
                Res[idx] = X;   break;
            }
        }
    }
    else {
        X = sum-1;
        printf("Sorry, we can only supply %lld eggs\n",X);
        for(ll i=0;i<(int)srt.size();i++){
            int idx = srt[i].ss;
            ll dec = srt[i].ff;
            if(dec <= req){
                X -= req;
                Res[idx] = Vec[idx];
            }
            else{
                Res[idx] = X;   break;
            }
        }
    }

    for(int i=0;i<M;i++){
        printf("%lld %lld %lld\n",Vec[i],Res[i],Vec[i]-Res[i]);
    }

	return 0;
}
