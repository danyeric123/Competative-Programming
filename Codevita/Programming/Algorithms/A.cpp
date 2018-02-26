#include <bits/stdc++.h>
using namespace::std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define trace(x) cerr  << "(" << __FUNCTION__ << " : " << __LINE__ << ") " << #x << " : " << x << endl;
#define INF 1e7+25
const int V=1e5+25;
vector<int> Graph[V];
int Color[V];
int Dist[V];
int Pre[V];
void BFS(int s){
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
    int N,x;
    cin >> N;
    vector<int> roots;
    memset(Color,0,sizeof(Color));
    memset(Dist,INF,sizeof(Dist));
    memset(Pre,INF,sizeof(Pre));
    for(int i=0;i<N;i++){
        cin >> x;
        if(x == -1){
            roots.push_back(i);
        }
        else{
            Graph[i].push_back(x);
            Graph[x].push_back(i);
        }
    }
    for(int i=0;i<roots.size();i++){
        BFS(roots[i]);
    }
    map<int,int> mmap;
    for(int i=0;i<N;i++){
        mmap[Dist[i]]++;
    }
    int Max = 0;
    int depth = 0;
    for(auto x : mmap){
        if(x.second >= Max){
            Max = max(Max,x.second);
            depth = max(depth,x.first);
        }
    }
    cout << depth << endl;
}
