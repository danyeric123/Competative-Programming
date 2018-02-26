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

#define rf(file) freopen(file,"r",stdin)
#define wf(file) freopen(file,"w",stdout)

#define Nitro \
ios_base::sync_with_stdio(0); \
cin.tie(0); \
cout.tie(0)

#define sz(a) (int)a.size()

int main(){
      int N;
      cin >> N;
      int cnt = 0;
      for(int i=0;i<=N;i++){
            for(int j=0;j<=i;j++){
                  cnt += (i+j);
            }
      }
      cout << cnt << endl;
      return 0;
}

