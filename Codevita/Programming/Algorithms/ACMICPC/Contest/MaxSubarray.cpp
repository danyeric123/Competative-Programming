#include<bits/stdc++.h>
using namespace std;
int MaxSum(int a[], int Len){
      int Maxx = a[0];
      int Res = a[0];
      for (int i = 1; i < Len; i++){
            Res = max(a[i], Res+a[i]);
            if(Res > Maxx){
                  Maxx = Res;
            }
      }
      return Res;
}
int main(){
      int Arr[] = {-1,-2,-3,-4,5,-1,6};

      cout << MaxSum(Arr,7) << endl;
}
