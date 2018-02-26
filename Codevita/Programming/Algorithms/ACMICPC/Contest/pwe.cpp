#include<bits/stdc++.h>
using namespace::std;
int mul(int a,int b){
      int res = 0;
      for(int i=1;i<=b;i++){
            res += a;
      }
      return res;
}
int poww(int m,int n){
      int res = 1;
      for(int i=1;i<=n;i++){
            int k=0;
            for(int i=1;i<=m;i++){
                  k += res;
            }
            res = k;
      }
      return res;
}
int main(){
      cout << poww(5,3) << endl;
}
