#include<bits/stdc++.h>
using namespace::std;

const int VMax = 1e4+5;
vector<int> Graph[VMax];
vector<int> Inp;
int Dist[VMax];
int NDist[VMax];
int Visited[VMax];

void LineInput(int i)
{
        string line;
        if(!i) getline(std::cin, line);
        int k;
        Inp.clear();
        getline(std::cin, line);
        //cout << line << endl;
        istringstream iss(line);
        while(iss >> k){
           Inp.push_back(k);
        }
}

void ClearEverything(int N)
{
    for(int i=1;i<=N;i++){
        Dist[i]=Visited[i]=0;
        Graph[i].clear();
    }
}

void Dfs(int v)
{
   // if(Visited[v])
   //     return ;

    Visited[v]=1;
    for(int i=0;i<(int)Graph[v].size();i++){
        int u = Graph[v][i];
        if(!Visited[u]){
        Dist[u] = max(Dist[u],NDist[u]+Dist[v]);
        Dfs(u);
        }
    }
    return ;
}

void Copy(int Dist[],int NDist[],int N){
    for(int i=1;i<=N;i++){
        Dist[i]=NDist[i];
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    int T,N;
    string line;
    cin >> T;
    while(T--)
    {
        cin >> N;
        ClearEverything(N);
        for(int i=0;i<N;i++)
        {
            LineInput(i);
            Dist[Inp[0]] = Inp[1];
            for(int j=2;j<(int)Inp.size();j++){
                Graph[Inp[j]].push_back(Inp[0]);
            }
        }

        int Max = -1;
        Copy(NDist,Dist,N);
        for(int i=1;i<=N;i++) {
            if(!Visited[i])
                    Dfs(i);
        }

        for(int i=1;i<=N;i++){
            Max = max(Max,Dist[i]);
        }

        printf("%d",Max);
        if(T)
            printf("\n");
    }

    return 0;
}

