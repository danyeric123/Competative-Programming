#include<bits/stdc++.h>
using namespace::std;
int findKey(int Arr[],int Len,int Key){
      int Low = 0;
      int High = Len-1;
      while(Low<=High){
            int Mid=(Low+High)/2;
            cout << Mid << endl;

            if(Arr[Mid]==Key) return Mid;
            if(Key>Arr[Mid] && Key<Arr[High]){
                  High = Mid-1;
            }
            else{
                  Low = Mid+1;
            }
      }
      return -1;

}
int findKeyRecur(int Arr[],int Low,int High,int Key){
      if(Low>High)
            return -1;
      int Mid = (Low+High)/2;
      if(Arr[Mid]==Key)
            return Mid;
      if(Key>Arr[Mid] && Key<Arr[High])
            return findKeyRecur(Arr,Low,Mid-1,Key);
      else
            return findKeyRecur(Arr,Mid+1,High,Key);
      return -1;
}

struct test{
      int Arr[50];
      int key;
      int idx;
};


int main(){
      int Arr[] ={8,7,1,2,3,4,5};
      int key = 1;
      int len = 7;
      int idx = findKey(Arr,len,key);
      int idx2 = findKeyRecur(Arr,0,len-1,key);
      cout << idx << " " << endl;
      cout << idx2 << endl;
}
