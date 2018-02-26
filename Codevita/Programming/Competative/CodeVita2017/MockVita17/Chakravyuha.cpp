#include <bits/stdc++.h>
using namespace::std;
#define pb push_back
#define mp make_pair

int N;
int a[105][105];
bool isok(int x,int y){
    return x>=0 && x<=N-1 && y>=0 && y<=N-1;
}
int main(){
    cin >> N;
    int num,j=0,p=N;
    int k = 1;
    vector< pair<int,int> > vec;
    vec.pb(mp(0,0));
     for(int i=p-1; i > 0; i--, j++)
     {
          for(num=j; num < i; num++){
            if(k%11==0) vec.pb(mp(j,num));
            a[j][num] = k++;
          }
          for(num=j; num < i; num++){
            if(k%11==0) vec.pb(mp(num,i));
            a[num][i] = k++;
          }
          for(num=i; num > j; num--){
            if(k%11==0) vec.pb(mp(i,num));
            a[i][num] = k++;
          }
          for(num=i; num > j; num--){
            if(k%11==0) vec.pb(mp(num,j));
            a[num][j] = k++;
          }
     }
     int m = (p-1)/2;
     if (p % 2 == 1) {
            if(k%11 == 0) vec.pb(mp(m,m));
            a[m][m] = k++;
     }
     for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
     }
     printf("Total Power points : %d\n",(int)vec.size());

    for(int i=0;i<(int)vec.size()-1;i++){
        printf("(%d,%d)\n",vec[i].first,vec[i].second);
    }
    printf("(%d,%d)",vec.back().first,vec.back().second);
    return 0;
}

