#include <iostream>
#include <vector>

using namespace std;

#define M 1 //masculino
#define F (-1) //femenino
#define U 0 //no marcado
#define PB push_back


vector<int> adj[105];
short int g[105]; //gender


bool DFS(int r){
    bool res = true;
    for(int i = 0; i < (int)adj[r].size(); i++){
        int v = adj[r][i];
        if(g[v] == g[r]) return false;
        if(g[v] == U){
            g[v] = -g[r];
            res = res and DFS(v);
        }
    }
    return res;
}



int main()
{

        int n, m;
        scanf("%d %d",&n,&m);
        for(int i = 1; i <= n; i++){
            g[i] = U;
            adj[i].clear();
        }

        int x, y;
        for( int i = 1; i <= m; i++){
            scanf("%d %d",&x,&y);
            adj[x].PB(y);
            adj[y].PB(x);
        }

        bool result = true;
        for(int i = 1; i <=n; i++){
            if(g[i] == U){
                g[i] = M;
                result = result and DFS(i);
            }
        }

        if(result)
            printf("Yes");
        else
            printf("No");

    return 0;
}
