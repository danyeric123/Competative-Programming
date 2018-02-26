#include<bits/stdc++.h>
using namespace::std;
int PowerMod(int Exp){
      int Base = 1378;
      int Ans = 1;
      while(Exp>0){
            if(Exp&1)
                  Ans = (Ans*Base)%10;
            Base = (Base*Base)%10;
            Exp = Exp>>1;
      }
      return Ans;
}
int main(){
      int N;
      cin >> N;
      cout << PowerMod(N);
}
