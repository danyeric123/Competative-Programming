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

int cost[1050][1050][3];
int C[1050][1050];
int P[1050][1050];

int min(int a,int b,int c) { return min(a,min(b,c)); }
int min(int a,int b,int c ,int d) { return min(a,min(b,c,d)); }

int main(){
    int T;
    cin >> T;
    while(T--){
        memset(C,0,sizeof(C));
        memset(P,0,sizeof(P));
        memset(cost,0,sizeof(cost));
        int N,M;
        cin >> N >> M;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                cin >> C[i][j];
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                cin >> P[i][j];
            }
        }
        //1 - cost from right side
        //2 - cost from top
        for(int i=1;i<=M;i++) {
                cost[1][i][1] = cost[1][i-1][1] + C[1][i];
                cost[1][i][0] = cost[1][i][1];
                cost[1][i][2] = 1e9;
        }
        for(int i=1;i<=N;i++) {
                cost[i][1][2] = cost[i-1][1][2] + C[i][1];
                cost[i][1][0] = cost[i][1][2];
                cost[i][1][1] = 1e9;
        }

        for(int i=2;i<=N;i++){
            for(int j=2;j<=M;j++){
                cost[i][j][0] = min(cost[i][j-1][1],cost[i][j-1][2]+P[i][j-1],
                                    cost[i-1][j][2],cost[i-1][j][1]+P[i-1][j]
                                    ) + C[i][j];

                cost[i][j][1] = min(cost[i][j-1][1],cost[i][j-1][2]+P[i][j-1],
                                    cost[i-1][j][2]+P[i][j],cost[i-1][j][1]+P[i-1][j]+P[i][j]
                                    )+C[i][j];

                cost[i][j][2] = min(cost[i-1][j][2],cost[i-1][j][1]+P[i-1][j],
                                     cost[i][j-1][1]+P[i][j],cost[i][j-1][2]+P[i][j-1]+P[i][j]
                                    )+C[i][j];

            }
        }

        cout << cost[N][M][0] << endl;
    }
    return 0;
}
