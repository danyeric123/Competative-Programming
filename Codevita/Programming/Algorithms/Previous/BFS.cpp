#include<bits/stdc++.h>
using namespace::std;

#define INF 0x3f3f3f3f
#define pb push_back
const int V=100;
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
