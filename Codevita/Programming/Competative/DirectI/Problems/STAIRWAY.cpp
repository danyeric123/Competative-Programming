#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v, w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 2;

int main() {
	int T; cin >> T;
	while (T--) {
		int N, K, P;
		cin >> N >> K >> P;
		vector<int> A(N), B(N);
		for (int i = 0; i < N; i++)
			cin >> A[i];
		for (int i = 0; i < N; i++)
			cin >> B[i];
		vector<int> a(N, INT_MAX / 2), b(N, INT_MAX / 2);
		a[0] = A[0]; b[0] = B[0];
		for (int i = 1; i < N; i++) {
			for (int k = 1; k <= K; k++) {
				if (i - k < 0) continue;
				a[i] = min(a[i], min(a[i - k], b[i - k] + P));
				b[i] = min(b[i], min(b[i - k], a[i - k] + P));
			}
			a[i] += A[i]; b[i] += B[i];
		}
		cout << min(a[N - 1], b[N - 1]) << endl;
	}
}

/**

Template belongs to : Himanshu Jaju [himanshujaju]


#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

#define inp_s     ios_base::sync_with_stdio(false)
#define DRT()     int test_case;cin>>test_case;while(test_case--)

#define VI        vector<int>
#define VS        vector<string>
#define VLL       vector<LL>
#define PII       pair<int,int>
#define all(c)    c.begin(),c.end()
#define sz(c)     c.size()
#define clr(c)    c.clear()
#define msi       map<string,int>
#define msit      map<string,int>::iterator
#define pb        push_back
#define mp        make_pair

#define GI(x)     scanf("%d",&x)
#define PI(x)     printf("%d\n",x)

#define FOR(i,a,b)      for(int i=a;i<b;i++)
#define RFOR(i,a,b)     for(int i=b-1;i>=a;i--)

#define gcd(a,b)  __gcd(a,b)
#define MOD       1000000007

#define PI  acos(-1)

#define CASE(x)   cout<<"Case "<<x<<": ";

int p,k;
VI A,B;

int visited[10000][2] = {0};
LL dp[10000][2] = {0};

LL ans(int pos,int x)
{
      if(pos < 0) return MOD;

      if(pos == 0)
      {
            if(!x) return A[0];
            else return B[0];
      }

      if(visited[pos][x]) return dp[pos][x];
      visited[pos][x] = 1;

      LL a1 = MOD;
      FOR(i,1,k+1)
      {
            a1 = min(a1,ans(pos-i,x));
            a1 = min(a1,p + ans(pos-i,1-x));
      }

      LL add = 0;
      if(!x) add = A[pos];
      else add = B[pos];

      dp[pos][x] = a1 + add;
      return a1 + add;
}

int main()
{
      inp_s;
      DRT()
      {
            clr(A);
            clr(B);
            FOR(i,0,10000) FOR(j,0,2) visited[i][j] = 0;
            int n;
            cin>>n>>k>>p;
            A.resize(n);
            B.resize(n);
            FOR(i,0,n) cin>>A[i];
            FOR(i,0,n) cin>>B[i];
            cout<<min(ans(n-1,0),ans(n-1,1))<<endl;
      }
      return 0;
}

*/
