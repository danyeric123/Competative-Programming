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

const int Maxx = 1e6+25;
const int Mod = 1e9+7;
vector<ll> Arr(Maxx);
vector<ll> Res(Maxx);
ll Max,Sum;

void Reset(int N){
      for(int i=0;i<=N;i++){
            Res[i] = 0;
            Arr[i] = 0;
      }
      Max = -1;
      Sum = 0;
      return;
}
int main()
{
      int T,x,N;
      cin >> T;
      while(T--){
            cin >> N;
            Reset(Maxx);

            for(int i=1;i<=N;i++){
                  cin >> Arr[i];
            }

            Max = -1;
            for(int i=1;i<=N;i++){
                  Max = max(Max,Arr[i]);
                  Res[Arr[i]] = 1;
            }

            for(int i=Max;i>=1;i--){
                  if(Res[i]!=0){
                        for(int j=2*i;j<=Max;j+=i){
                              Res[i] = (Res[i] + Res[j] + Mod)%Mod;
                        }
                  }
            }

            Sum = 0;

            for(int i=1;i<=Max;i++){
                  Sum = (Sum + Res[i]+Mod)%Mod;
            }

            cout << Sum << endl;
      }
	return 0;
}
