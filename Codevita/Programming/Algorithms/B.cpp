#include <bits/stdc++.h>
using namespace::std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define trace(x) cerr  << "(" << __FUNCTION__ << " : " << __LINE__ << ") " << #x << " : " << x << endl;
#define INF 1234567
const int V=100;
vector<int> Graph[V];
int Color[V]; // {0,-1,1} = {White,Grey,Black}  = {Unvisited,Discovered,Explored}
int Dist[V];
int Pre[V];
vector<int> Nodes[V];
void BFS(int s){
    queue <int> q;
    q.push(s);
    Color[s] = -1;
    Dist[s]=0;
    Pre[s]=0;
    Nodes[0].push_back(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<Graph[u].size();i++){
           int v = Graph[u][i];
           if(Color[v]==0){
                Color[v] = -1;
                Dist[v] = Dist[u]+1;
                //trace(Dist[v]);
                //trace(v);
                Nodes[Dist[v]].push_back(v);
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
    int Maxdepth = 0;
    for(int i=0;i<N;i++){
        Maxdepth = max(Maxdepth,Dist[i]);
    }
    for(int i=0;i<=Maxdepth;i++){
        //trace(i);
        sort(Nodes[i].begin(),Nodes[i].end());
        for(int j=0;j<Nodes[i].size();j++){
            cout << Nodes[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
