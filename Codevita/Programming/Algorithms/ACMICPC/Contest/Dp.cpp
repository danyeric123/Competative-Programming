#include<bits/stdc++.h>
using namespace::std;
 int Dp[1000];
int main(){
      int N;
      cin >> N;

      Dp[0]=0;
      Dp[1]=1;
      Dp[2]=2;
      Dp[3]=3;
      for(int i=4;i<=N;i++){
            Dp[i] =   max(3*Dp[i-4],max(1+Dp[i-1],2*Dp[i-3]));

      }

      for(int i=1;i<=20;i++){
            cout << i << " " << Dp[i] << endl;
      }
}
