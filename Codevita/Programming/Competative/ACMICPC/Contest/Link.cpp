#include<bits/stdc++.h>
using namespace::std;

#define ll  long long
#define ull unsigned ll
#define LD long double

vector< vector<int> > Idx1(350);
vector< vector<int> > Idx2(350);
string s1,s2;

void Reset(){
      for(int i=0;i<300;i++){
            Idx1[i].clear();
            Idx2[i].clear();
      }
      return;
}

int GetMin(int x1,int x2){
      int L1 = x1;
      int L3 = s1.size() - x1 - 1;
      int L2 = x2;
      int L4 = s2.size() - x2 - 1;

     // cout << x1 << " " << x2 << endl;
      //cout << L1 << " " << L2 << " " << L3 << " " << L4 << endl;
      int res = (abs(L1-L2)+abs(L2-L3)+abs(L3-L4)+abs(L4-L1));
      //cout << "ret : " << res << endl;
      return res;
}

int Compute(int x){
      /*
      cout << char(x) << endl;

      cout << "str1" << " : " ;
      for(int i=0;i<Idx1[x].size();i++){
            cout << Idx1[x][i] << " ";
      }
      cout << "str2" << " : ";
      for(int i=0;i<Idx2[x].size();i++){
            cout << Idx2[x][i] << " ";
      }
      cout << endl;
      */
      int Min = INT_MAX;
      for(int i=0;i<Idx1[x].size();i++){
            for(int j=0;j<Idx2[x].size();j++){
                  Min = min(Min,GetMin(Idx1[x][i],Idx2[x][j]));
            }
      }
      return Min;

}
int main()
{
      int T;
      cin >> T;
      while(T--){
            Reset();
            cin >> s1 >> s2;
            for(int i=0;i<s2.size();i++){
                  Idx2[s2[i]].push_back(i);
            }
            for(int i=0;i<s1.size();i++){
                  Idx1[s1[i]].push_back(i);
            }
            int Min = INT_MAX;
            for(int i ='A';i<='Z'; i++){
                  if(Idx1[i].size() && Idx2[i].size())
                        Min = min(Min,Compute(i));
            }

            cout << Min << endl;
      }

    return 0;
}

