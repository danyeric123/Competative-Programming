#include<bits/stdc++.h>
using namespace::std;
const int Vmax=100;
vector<int> Graph[Vmax];

/*
    u-->v edge
    Graph[u].push_back(v)
    */

set<int> Visited;
stack<int> Sorted;

void Topo(int N)
{
    for(int i=1;i<=N;i++){



    }


}

int main()
{
    int N,u,v;
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> u >> v;
        Graph[u].push_back(v);
    }
}
