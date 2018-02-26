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
vector<ll> Original;
vector<pair<ll,int> > srt;

int main(){
    ll M,X,x;
    ll sum = 0;
    cin >> M >> X;
    for(int i=0;i<M;i++){
        cin >> x;
        Vec.pb(x);
        Original.pb(x);
        srt.pb(mp(x,-i));
        sum += x;
    }
    ll req = min(X,sum-1);
    sort(srt.rbegin(),srt.rend());
    for(ll i=0;i<(int)srt.size();i++){
        int idx = -srt[i].ss;
        ll dec = min(Vec[idx],req);
        Vec[idx] -= dec;
        req -= dec;

    }
    assert(req == 0);
    if( X < sum){
        printf("Thank you, your order for %lld eggs is accepted\n",X);
        for(int i=0;i<M;i++){
            printf("%lld %lld %lld\n",Original[i],Original[i]-Vec[i],Vec[i]);
        }
    }
    else {
        printf("Sorry, we can only supply %lld eggs\n",sum-1);
        for(int i=0;i<M;i++){
            printf("%lld %lld %lld\n",Original[i],Original[i]-Vec[i],Vec[i]);
        }
    }




	return 0;
}
