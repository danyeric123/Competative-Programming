#include<bits/stdc++.h>
using namespace::std;
unordered_map<int,int> par;
unordered_set<int> visited;
int cycle(int s){
    int u = s;
    u = par[u];
    while(u != -1 && visited.find(u) == visited.end()){
        visited.insert(u);
        u = par[u];
    }
    if(u == -1)
        return -1;
    vector<int> vis;
    while(find(vis.begin(),vis.end(),u) == vis.end()){
        vis.push_back(u);
        u = par[u];
        if(u == -1) return -1;
    }
    for(auto x : vis){
        //cout << x << " ";
    }
   // cout << endl;
    return vis.size();
}

int largest(){
    unordered_map<int,int> cnt;
    int Max = 0;
    int Node = -1;
    for(auto x : par){
        cnt[x.second]++;
        if(cnt[x.second] >= Max){
            Max = cnt[x.second];
            Node =  x.first;
        }
    }
    return Max;
}
int main(){
    int N,x;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x;
        par[i]=x;
    }
    int Max = -1;
    for(int i=0;i<N;i++){
        Max = max(Max,cycle(i));
    }
    cout << Max << endl;
    cout << largest() << endl;
    return 0;
}
