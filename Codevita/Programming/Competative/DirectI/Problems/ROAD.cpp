#include<bits/stdc++.h>
using namespace::std;

struct UnionFind{
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y){
		x = root(x); y = root(y);
		if(x != y){
			if(data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

vector< pair<int,pair<int,int> > > bad;
UnionFind uf;
int main(){
    int N,M;
    cin >> N >> M;
    uf.init(N+1);
    int type,x,y,weight;
    for(int i=0;i<M;i++){
        cin >> x >> y >> type;
        if(type == 0){
            uf.unionSet(x,y);
        }
        else{
            cin >> weight;
            bad.push_back(make_pair(weight,make_pair(x,y)));
        }
    }
    sort(bad.begin(),bad.end());
    int minCost = 0;
    for(int i=0;i<bad.size();i++){
        int w = bad[i].first;
        int x = bad[i].second.first;
        int y = bad[i].second.second;
        if(!uf.findSet(x,y)){
            minCost += w;
            //cout << "(" << x << "," << y << ")" << endl;
            uf.unionSet(x,y);
        }
    }
    cout << minCost << endl;
}
