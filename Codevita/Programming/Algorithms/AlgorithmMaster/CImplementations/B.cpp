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

map<int,int> Map;
vector<pair<int,int> > vec;
map<int,int> idx;
bool cmp(const  pair<int,int>  &v1,const  pair<int,int>   &v2 ){
      if(v1.ss != v2.ss){
            return v1.ss > v2.ss;
      }
      return idx[v1.ff] < idx[v2.ff];
      //return v1.ff < v2.ff;
}
int main(){
      int N;
      int x;
      cin >> N;
      for(int i=0;i<N;i++){
            cin >> x;
            Map[x]++;
            if(idx.find(x) == idx.end())
                  idx[x]=i;
      }
      for(map<int,int> ::iterator it=Map.begin();it!=Map.end();it++){
            vec.pb(mp(it->first,it->second));
      }
      sort(vec.begin(),vec.end(),cmp);
      for(int i=0;i<vec.size();i++){
            for(int j=0;j<Map[vec[i].ff];j++)
                  cout << vec[i].ff <<  " ";
      }
      return 0;
}
