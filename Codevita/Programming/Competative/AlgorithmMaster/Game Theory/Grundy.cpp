#include<bits/stdc++.h>
using namespace::std;
const int MAXN = 1e6+25;
int Grundy[MAXN+225];
int Arr[MAXN+25];
void Pre(){
      Grundy[0] = 0;
      Grundy[1] = 1;
      bool Count[105] = {false};
      for(int i=2;i<=100;i++){
            if(Grundy[i-1]>0){
                  Grundy[i] = Grundy[i-1]-1;
            }
            else{
                  Grundy[i] = 0;
            }
      }
}
int main(){
      Pre();

      int n,T,k;
      cin >> T;
      while(T--){
            cin >> n;
            int Xor = 0;
            for(int i=1;i<=n;i++){
                  cin >> k;
                  Xor = Xor^Grundy[(k/i)];
            }

            if(Xor) cout << "ALICE\n";
            else cout << "BOB\n";
      }

      return 0;
}

