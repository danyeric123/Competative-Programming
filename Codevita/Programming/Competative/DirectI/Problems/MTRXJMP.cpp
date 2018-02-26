#include<bits/stdc++.h>
using namespace::std;

int minHops(int matrix[64][64], int m, int n){
    int dp[m+1][n+1];
    memset(dp,2222,sizeof(dp));
    for(int i=0;i<m;i++){
        for(int j =0;j<n;j++){
           dp[i][j] = 2222;
        }
    }
    dp[0][0] = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(j+matrix[i][j] < n){
                dp[i][j+matrix[i][j]] = min(dp[i][j+matrix[i][j]],dp[i][j]+1);
            }
            if(i+matrix[i][j] < m){
                dp[i+matrix[i][j]][j] = min(dp[i+matrix[i][j]][j],dp[i][j]+1);
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j =0;j<n;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return ((dp[m-1][n-1] != 2222)?dp[m-1][n-1]:0);
}
int main(){
    int mat[64][64] = {
        {5, 3, 8, 2},
        {6, 4, 2, 1}
    };
    cout << minHops(mat,2,4) << endl;
    return 0;
}
