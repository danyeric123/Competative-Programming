#include<bits/stdc++.h>
using namespace::std;


struct UnionFind
{
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y)
	{
		x = root(x); y = root(y);
		if(x != y)
		{
			if(data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

UnionFind Uf;

int main()
{
    int i,j,N;
    string Type;

    cin >> N;
    Uf.init(N+25);
    cin >> Type;

    while(Type[0]!='-'){
    	cin >> i >> j;

    	if(Type[0]=='C'){
    		Uf.unionSet(i,j);
    	}else{
    		puts(Uf.findSet(i,j)?"Yes":"No");
    	}

    	cin >> Type;
    }

	return 0;
}

