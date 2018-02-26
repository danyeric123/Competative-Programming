struct Node{
  int node, cost;
  // i.e Node o is higher up in priority in the queue
  bool operator<(Node const &o) const {
    return cost > o.cost;
  }
};

vector<Node> AdjList[MAXN];
int dist[MAXN];

void ShortestPath(int src){
      Node start,curr,next;
      start.node = src;
      start.cost = 0;
      memset(dist, -1, sizeof(dist));  // Initialize distance
      priority_queue<Node> q;          // Initialize queue
      q.push(start);
      while(!q.empty()){
            curr = q.top();
            q.pop();
           // cout << curr.node << " " << curr.cost << ", dist : " << dist[curr.node] << endl;
            if(dist[curr.node] == -1){
                  dist[curr.node] = curr.cost;
                  for(int i = 0; i < AdjList[curr.node].size(); i++){
                        if(dist[AdjList[curr.node][i].node] != -1) continue;
                  next.node = AdjList[curr.node][i].node;
                  next.cost = curr.cost + AdjList[curr.node][i].cost;
                  q.push(next);
      	}
      }
    }
}

scanf("%d %d %d",&x,&y,&c);
AdjList[x].push_back({y,c});
AdjList[y].push_back({x,c});

ShortestPath(src);