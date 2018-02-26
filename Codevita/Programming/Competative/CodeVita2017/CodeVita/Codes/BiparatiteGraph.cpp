#include<bits/stdc++.h>
using namespace std;
const int VMax = 2025;
vector<int> Graph[VMax];
int Color[VMax];
int Visited[VMax];
bool isBipartite(int s)
{
    Color[s] = 1;
    queue <int> q;
    q.push(s);
    Visited[s]=1;
    while (!q.empty())
    {
        int u = q.front();
        Visited[u]=1;
        q.pop();
        for (int i=0; i<Graph[u].size();i++)
        {
            int v = Graph[u][i];
            if (Color[v] == -1)
            {
                Color[v] = 1 - Color[u];
                q.push(v);
                Visited[v]=1;
            }
            else if (Color[v] == Color[u]){
                return false;
            }
        }
    }
    return true;
}
void Clear(){
    for(int i=0;i<VMax;i++){
        Graph[i].clear();
    }
    memset(Color,-1,sizeof(Color));
    memset(Color,0,sizeof(Color));
}
int main()
{
    //freopen("input.txt","r",stdin);
    int T;
    int N,Q;
    int u,v;
    cin >> T;
    for(int i=1;i<=T;i++)
    {
        bool ok = true;
        Clear();
        cin >> N >> Q;
        while(Q--){
            cin >> u >> v;
            Graph[v].push_back(u);
            Graph[u].push_back(v);
        }
        for(int i=1;i<=N;i++){
            if(!Visited[i])
                ok = ok && isBipartite(i);
        }
        puts(ok?"Yes":"NoTrue");
    }
    return 0;
}

