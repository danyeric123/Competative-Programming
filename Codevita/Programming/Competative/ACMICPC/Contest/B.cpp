#include<bits/stdc++.h>
using namespace::std;
typedef long long ll;
ll Arr[100025];
unordered_map<ll,ll> Freq;
int main(){
      ll N,x;
      cin >> N >> x;
      for(int i=0;i<N;i++){
            cin >> Arr[i];
            Freq[Arr[i]]++;
      }
      ll Res = 0;
      for(int i=0;i<N;i++){
            ll f = x^Arr[i];
            if(f==Arr[i]){
                  Res += Freq[Arr[i]]*(Freq[Arr[i]]-1)/2;
                  Freq[Arr[i]]=0;
            }
            else if(Freq[f]>0){
                  Res += Freq[f]*Freq[Arr[i]];
                  Freq[f]=0;
                  Freq[Arr[i]]=0;
            }
      }
      cout << Res << endl;
}
