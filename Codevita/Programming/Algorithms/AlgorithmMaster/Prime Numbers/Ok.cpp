vector<int> Graph[V];
int Color[V]; // {0,-1,1} = {White,Grey,Black}  = {Unvisited,Discovered,Explored}
int Dist[V];
int Pre[V];
int DTime[V];
int FTime[V];
int Time=0;
void DFS();
void DFS_VISIT(int u);
list<int> TopoSort;
void DFS(int N){
    memset(Color,0,sizeof(Color));
    memset(Dist,INF,sizeof(Dist));
    memset(Pre,0,sizeof(Pre));
    memset(DTime,0,sizeof(Pre));
    memset(FTime,0,sizeof(Pre));
    for(int u=1;u<=N;u++){
        if(Color[u]==0){ 
          DFS_VISIT(u);
        }
    }
}
void DFS_VISIT(int u){
    Time++;
    DTime[u] = Time;    Color[u] = -1;
    for(int i=0;i<Graph[u].size();i++){
        int v = Graph[u][i];
        if(Color[v]==0){
            Pre[v]=u; DFS_VISIT(v);
        } }
    Color[u]=1; Time++;
    FTime[u]=Time;
    TopoSort.push_front(u);
}