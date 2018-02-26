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

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt(): x(0) { }
	ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
	ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		long long a = x, b = MOD, u = 1, v = 0;
		while(b) {
			long long t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		return ModInt(u);
	}

	bool operator==(ModInt that) const { return x == that.x; }
	bool operator!=(ModInt that) const { return x != that.x; }
	ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};

const int MOD = 1e9+7;
typedef ModInt<MOD> mint;

const int NN = 1005;
mint res[NN+25];

vector<int> Graph[NN+25];

void DFS(int u){
    if(Graph[u].size() == 0){
        res[u] = 1;
        return;
    }
    mint sum = 0;
    for(int i=0;i<Graph[u].size();i++){
        int v = Graph[u][i];
        DFS(v);
        sum += res[v];
    }
    if(Graph[u].size() == 1){
        res[u] = sum;
        return;
    }
    mint ans = 0;

    for(int i=0;i<Graph[u].size();i++){
        int v = Graph[u][i];
        ans += (sum-res[v])*res[v];
    }
    res[u] = ans;
}
int main(){

    int T;
    int N,x;
    cin >> T;
    while(T--){
        cin >> N;
        cin >> x;
        for(int i=2;i<=N;i++){
            cin >> x;
            Graph[x].push_back(i);
        }
        DFS(1);
        cout << res[1].get() << endl;
        for(int i=1;i<=NN;i++){
            Graph[i].clear();
        }
    }
    return 0;
}
