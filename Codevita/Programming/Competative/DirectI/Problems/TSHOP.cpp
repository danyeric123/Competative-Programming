#include<bits/stdc++.h>
using namespace::std;

#define ll  long long
#define ull unsigned ll
#define LD long double

#define mp make_pair
#define bs binary_search
#define gcd __gcd
#define pb push_back
#define pp pop_back
#define ff first
#define ss second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

ll dp[50+1][50+1];
ll wt[1005];
ll val[1005];
ll N,W;
ll knapSack(){
   memset(dp,0,sizeof(dp));
   for (int i = 0; i <= N; i++){
       for (int w = 0; w <= W; w++){
           if (i==0 || w==0)
               dp[i][w] = 0;
           else if (wt[i-1] <= w)
                 dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]],  dp[i-1][w]);
           else
                 dp[i][w] = dp[i-1][w];
       }
   }
   return dp[N][W];
}


int main()
{
    int T;
    cin >> T;
    while(T--){
        cin >> N >> W;
        for(int i=0;i<N;i++){
            cin >> val[i];
        }
        for(int i=0;i<N;i++){
            cin >> wt[i];
        }
        cout << knapSack() << endl;
    }
    return 0;
}
