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

map<char,pair<int,int> > Ch;
int main()
{
      rf("template.in");
      wf("template.out");

      int N,M;
      string s;
      cin >> N >> M;
      for(int i=0;i<M;i++){
            while(getline(cin,s) && s=="");
            for(int j=0;j<s.size();j++){
                  Ch[s[j]] = mp(i,j);
            }
      }

      string l;
      vector< pair<string,int > > Result;
      char Prev;

      while(cin >> l ){
           // cout << l << endl;
            while(getline(cin,s) && s=="");
            Prev = s[0];
            int Res = 0;
            do{
                  //cout << s << endl;
                  for(int i=0;i<s.size();i++){
                       // printf("%d %d\n",s[i],Prev);
                        Res += max(abs(Ch[s[i]].ff - Ch[Prev].ff) , abs(Ch[s[i]].ss - Ch[Prev].ss));
                        Prev = s[i];
                  }
            }while(getline(cin,s) && s!="");
            Result.pb(mp(l,Res));
      }

      pair<string,int> Ans;
      Ans = Result[0];
      for(int i=1;i<Result.size();i++){
            if(Result[i].ss < Ans.ss){
                  Ans = Result[i];
            }
      }

      cout << Ans.ff << endl << Ans.ss << endl;
	return 0;
}

