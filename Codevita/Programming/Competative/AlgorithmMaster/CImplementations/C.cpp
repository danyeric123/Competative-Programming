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

int Arr[10000];
map<int,int> Time;
int ok(int N){

      for(int i=1;i<=N;i++)
            if(Arr[i]!=0) return false;
      return true;
}
int main(){
      int N;
      cin >> N;
      for(int i=1;i<=N;i++){
            cin >> Arr[i];
      }
      int time = 0;
      int i = 1;
      while(!ok(N)){
            //cout << i << " " << Arr[i] << endl;
            if(Arr[i]==0){
                  i++;
                  if(i>N) i=1;
                  continue;
            }
            Arr[i]--;
            time++;
            if(Arr[i]==0){
                  Time[i]=time;
            }
            i++;
            if(i>N) i=1;
      }
      for(i=1;i<=N;i++){
            cout << Time[i] << " ";
      }
      return 0;
}

