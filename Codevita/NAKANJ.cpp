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

bool OnBoard(int x){
    if(x>=11 && x<=88 && x%10>=1 && x%10<=8)
        return true;
    return false;
}

void CreateVertex(int u){
    int LeftUp = u+10-2;
    int LeftDw = u-10-2;
    int RightUp = u+10+2;
    int RightDw = u-10+2;
    int UpLeft =  u+20-1;
    int UpRight = u+20+1;
    int DownLeft = u-20-1;
    int DownRight = u-20+1;

    if(OnBoard(LeftUp))
        Graph[u].pb(LeftUp);
    if(OnBoard(LeftDw))
        Graph[u].pb(LeftDw);
    if(OnBoard(RightUp))
        Graph[u].pb(RightUp);
    if(OnBoard(RightDw))
        Graph[u].pb(RightDw);
    if(OnBoard(UpLeft))
        Graph[u].pb(UpLeft);
    if(OnBoard(UpRight))
        Graph[u].pb(UpRight);
    if(OnBoard(DownLeft))
        Graph[u].pb(DownLeft);
    if(OnBoard(DownRight))
        Graph[u].pb(DownRight);
}

void CreateChessBoard()
{
    for(int i=11;i<=88;i++){
        CreateVertex(i);
    }
}


void PrintBoard()
{
    for(int i=11;i<=88;i++)
    {
        if(i%10 >=1 && i%10 <=8){
        cout << "Squrare " << i << " : " ;
        for(int j=0;j<Graph[i].size();j++){
            cout << Graph[i][j] << " ";
        }
        cout << endl;
        }
   }

}
int main()
{
    CreateChessBoard();
    int T;
    string A,B;
    cin >> T;
    while(T--)
    {
        cin >> A >> B;
        int s = (A[0]-'a'+1)+(A[1]-'0')*10;
        int d = (B[0]-'a'+1)+(B[1]-'0')*10;
        BFS(s);
        cout << Dist[d] << endl;
    }
    return 0;
}

