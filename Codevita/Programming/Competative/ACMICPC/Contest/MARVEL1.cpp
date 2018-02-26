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

#define rf freopen("input.txt","r",stdin)
#define wf freopen("output.txt","w",stdout)

#define Nitro \
ios_base::sync_with_stdio(0); \
cin.tie(0); \
cout.tie(0)

#define sz(a) (int)a.size()


int main()
{
      int E;
      cin >> E;
      while(E--){
            int a,d;
            cin >> a >> d;
            int c=0;
            for(int i=1;i<=a;i++){
                  for(int j=1;j<=a;j++){
                        if((i+j)%d==0 && i<j)
                              c++;
                  }
            }
            cout << c << endl;
      }
	return 0;
}

