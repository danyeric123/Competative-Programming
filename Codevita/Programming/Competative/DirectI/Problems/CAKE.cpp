#include<bits/stdc++.h>
using namespace::std;

#define INF 0x3f3f3f3f
#define pb push_back
const int V=1e4+25;
vector<int> Graph[V];
int Color[V]; // {0,-1,1} = {White,Grey,Black}  = {Unvisited,Discovered,Explored}
int Dist[V];
int Pre[V];

void BFS(int s){

    memset(Color,0,sizeof(Color));
    memset(Dist,INF,sizeof(Dist));
    memset(Pre,INF,sizeof(Pre));

    queue <int> q;
    q.push(s);
    Color[s] = -1;
    Dist[s]=0;
    Pre[s]=0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<Graph[u].size();i++){
           int v = Graph[u][i];
           if(Color[v]==0){
                Color[v] = -1;
                Dist[v] = Dist[u]+1;
                Pre[v] = u;
                q.push(v);
           }
        }
        Color[u] = 1;
    }
    return;
}


int main(){
    int T;
    cin >> T;
    while(T--){
        int N,M,s,d;
        int x,y;
        cin >> N >> M >> s >> d;
        for(int i=0;i<M;i++){
            cin >> x >> y;
            Graph[x].pb(y);
            Graph[y].pb(x);
        }
        BFS(s);
        cout << Dist[d] << endl;
        for(int i=0;i<=N;i++){
            Graph[i].clear();
        }
    }
}
