#include<bits/stdc++.h>
using namespace std;
const int V = 405+25; //dict size
vector<int> Graph[V+25];
int dp[50][50]; //string size
int editDist(string str1, string str2){
     memset(dp,0,sizeof(dp));
     int m = str1.length();
     int n = str2.length();
     for (int i=0; i<=m; i++){
        for (int j=0; j<=n; j++){
            if (i==0) dp[i][j] = j;
            else if (j==0) dp[i][j] = i;
            else if (str1[i-1] == str2[j-1])dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    return dp[m][n];
}

#define INF 0x3f3f3f3f
int Color[V];
int Dist[V];
void BFS(int s){
    memset(Color,0,sizeof(Color));
    memset(Dist,INF,sizeof(Dist));
    queue <int> q;
    q.push(s);
    Color[s] = -1;
    Dist[s]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<Graph[u].size();i++){
           int v = Graph[u][i];
           if(Color[v]==0){
                Color[v] = -1;
                Dist[v] = Dist[u]+1;
                q.push(v);
           }
        }
        Color[u] = 1;
    }
    return;
}

vector<string> vec;
int findPos(string s){
    for(int i=0;i<vec.size();i++){
        if(vec[i] == s) return i;
    }
    vec.push_back(s);
    return vec.size()-1;
}
int main(){
	string s;

	while(cin >> s){
		if(s=="END") break;
        vec.push_back(s);
	}
	string source,destination;
	cin >> source >> destination;

    int src = findPos(source);
    int dest = findPos(destination);

    for(int i=0;i<vec.size();i++){
        for(int j=i+1;j<vec.size();j++){
            if(editDist(vec[i],vec[j]) == 1){
                Graph[i].push_back(j);
                Graph[j].push_back(i);
            }
        }
    }
    BFS(src);
    if(Dist[dest] == INF){
        cout << "-1" << endl;
    }
    else{
        cout << Dist[dest] << endl;
    }


	return 0;
}
