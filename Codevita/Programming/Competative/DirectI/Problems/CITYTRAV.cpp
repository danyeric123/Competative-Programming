#include<bits/stdc++.h>
using namespace::std;
int commonCitiesVisited(string s1, string s2){
    int dp[s1.length()+1][s2.length()+1];
    for(int i=0;i<=s1.length();i++){
        for(int j=0;j<=s2.length();j++){
            dp[i][j] = 0;
        }
    }
    for(int i=1;i<=s1.length();i++){
        for(int j=1;j<=s2.length();j++){
            if (s1[i-1] == s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[s1.length()][s2.length()];
}

int main(){
    int T;
    string s1,s2;
    cin >> T;
    while(T--){
        cin >> s1 >> s2;
        cout << commonCitiesVisited(s1,s2) << endl;
    }
}
