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

const int N = 30025;
vector<int> Graph[N];
int values[N];
bool univalued[N];
bool visited[N];

void dfs(int u,int par){
    if(visited[u]) return;
    visited[u] = true;
    if(Graph[u].size() == 1){
        univalued[u] = true;
        return;
    }
    bool ok1 = true;  //from values
    bool ok2 = true;  //from dfs
    for(int i=0;i<Graph[u].size();i++){
        int v = Graph[u][i];
        if(v != par){
            dfs(v,u);
            ok2 = ok2 & univalued[v];
            ok1 = ok1 & (values[v] == values[u]);
        }
    }
    if(ok1 && ok2){
        univalued[u] = true;
        return;
    }
}
int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> values[i];
    }
    int x,y;
    for(int i=1;i<=N-1;i++){
        cin >> x >> y;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }

    dfs(0,-1);
    int res = 0;
    for(int i=0;i<N;i++){
        res += (univalued[i]);
    }
    cout << res << endl;
    return 0;
}
