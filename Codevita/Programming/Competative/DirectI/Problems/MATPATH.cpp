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
ll cost[200][200];
ll A[200][200];
int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        for(int i=0;i<=N;i++)
            for(int j=0;j<=N;j++)
                cost[i][j] = 1000000000000LL;

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                cin >> A[i][j];
                if(i!=j) cost[i][j] = A[i][j];
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i==1 && j == 1) cost[i][j] = A[i][j];
                else if(i!=j || i==N && j == N){
                    cost[i][j] = min(cost[i][j-1],cost[i-1][j]) + A[i][j];
                }
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                printf("%12lld ",cost[i][j]);
            }
            cout << endl;
        }
        ll res = cost[N][N-1] + cost[N-1][N] + A[N][N];
        cout << res << endl;
    }
    return 0;
}
