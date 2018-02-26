#include <bits/stdc++.h>
using namespace::std;

#define TRACE(x) cerr<<"[[ "<<#x<<" = "<<x<<" ]]"<<endl;
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1 && arg1) {
	cerr << name << " : " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

#else
#define trace(...)
#endif
#define Assert(x,y) {if(x!=y){cerr<<__LINE__ <<"->  Assertion Failed "<<": ("<<#x<<"!="<<y<<") ";TRACE(x);exit(1);}}

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

#define endl '\n'
#define Nitro ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MAX = 1e6;
bool isprime[MAX+25];
int HPF[MAX+25];
vector<ll> prime;
void sieve()
{
    int i,j;
    memset(isprime,1,sizeof(isprime));
    isprime[0]=isprime[1]=0;
    for(i=4;i<=MAX;i+=2) {isprime[i]=0; HPF[i] =2;}
    for(i=3;i<=sqrt(MAX);i+=2) {
        if(isprime[i]){
            HPF[i]=i;
            for(j=i*i;j<=MAX;j+=i){
                isprime[j]=0;
                if(!HPF[j])
                    HPF[j]=i;
            }
        }
    }
    for(int i=2;i<=MAX;i++) {
        if(isprime[i]){
            prime.push_back(i);
            HPF[i]=i;
        }
    }
}

ll mul(unsigned ll a, unsigned ll b, unsigned ll mod) {
    ll ret = 0;
    for (a %= mod, b %= mod; b != 0; b >>= 1, a <<= 1, a = a >= mod ? a - mod : a) {
        if (b&1) {
            ret += a;
            if (ret >= mod)	ret -= mod;
        }
    }
    return ret;
}

void exgcd(ll x, ll y, ll &g, ll &a, ll &b) {
    if (y == 0)
        g = x, a = 1, b = 0;
    else
        exgcd(y, x%y, g, b, a), b -= (x/y) * a;
}

ll llgcd(ll x, ll y) {
    if (x < 0)    x = -x;
    if (y < 0)    y = -y;
    if (!x || !y)    return x + y;
    ll t;
    while (x%y)
        t = x, x = y, y = t%y;
    return y;
}

ll inverse(ll x, ll p) {
    ll g, b, r;
    exgcd(x, p, g, r, b);
    if (g < 0)	r = -r;
    return (r%p + p)%p;
}

ll mpow(ll x, ll y, ll mod) {
    ll ret = 1;
    while (y) {
        if (y&1)
            ret = (ret * x)%mod;
        y >>= 1, x = (x * x)%mod;
    }
    return ret % mod;
}

ll mpow2(ll x, ll y, ll mod) {
    ll ret = 1;
    while (y) {
        if (y&1)
            ret = mul(ret, x, mod);
        y >>= 1, x = mul(x, x, mod);
    }
    return ret % mod;
}

int isPrime(ll p) {
    if (p < 2 || !(p&1))	return 0;
    if (p == 2)				return 1;
    ll q = p-1, a, t;
    int k = 0, b = 0;
    while (!(q&1))	q >>= 1, k++;
    for (int it = 0; it < 2; it++) {
        a = rand()%(p-4) + 2;
        t = mpow2(a, q, p);
        b = (t == 1) || (t == p-1);
        for (int i = 1; i < k && !b; i++) {
            t = mul(t, t, p);
            if (t == p-1)
                b = 1;
        }
        if (b == 0)
            return 0;
    }
    return 1;
}

ll pollard_rho(ll n, ll c) {
    ll x = 2, y = 2, i = 1, k = 2, d;
    while (true) {
        x = (mul(x, x, n) + c);
        if (x >= n)	x -= n;
        d = llgcd(x - y, n);
        if (d > 1) return d;
        if (++i == k) y = x, k <<= 1;
    }
    return n;
}

void factorize(ll n, vector<ll> &f) {
    for (ll i = 0; i < prime.size() && 1LL*prime[i]*prime[i] <= n; i++) {
    	if (n%prime[i] == 0) {
    		while (n%prime[i] == 0){
    			f.push_back(prime[i]);
    			n /= prime[i];
    		}
    	}
    }
    if (n != 1)	f.push_back(n);
}

void llfactorize(ll n, vector<ll> &f) {
    if (n == 1)
        return ;
    if (n < 1e+9) {
        factorize(n, f);
        return ;
    }
    if (isPrime(n)) {
        f.push_back(n);
        return ;
    }
    ll d = n;
    for (int i = 2; d == n; i++)
        d = pollard_rho(n, i);
    llfactorize(d, f);
    llfactorize(n/d, f);
}

void Solve(ll n){
    vector<ll> f;
    llfactorize(n,f);
    map<ll,ll> r;
    for (auto &x : f)
        r[x]++;
    if(r.size() == 1){
        cout << "NO" << endl;
        return;
    }
    for(auto x : r){
        ll p = 1LL*x.second;
        ll p2 = 1LL*p*p;
        if(n%p == 0 && n%p2 != 0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

}

int main(){
    sieve();
    ll n ;
    while(cin >> n ){
        if(!n) break;
        Solve(n);
    }
}
