#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long long>
#define vd vector<double>
#define vp vector<pair<int,int> >
#define ll long long
#define pi pair<int,int>
#define point pair<double,double>
#define pl pair<ll,ll>
#define popcnt(x) __builtin_popcount(x)
#define LSOne(x) ((x) & (-(x)))
#define xx first
#define yy second
#define PQ priority_queue
#define print(A,t) cerr << #A << ": "; copy(all(A),ostream_iterator<t>(cerr," " )); cerr << endl
#define prp(p) cerr << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cerr << #A << ": "; copy(A,A + n,ostream_iterator<t>(cerr," " )); cerr << endl
#define PRESTDIO() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
using namespace std;
const int MAX = 2e5 + 1e2;
const int MAXLG = 20;
vi G[MAX];
int siz[MAX],dfs_in[MAX],dfs_out[MAX],depth[MAX],dfs_time;
int P[MAX][MAXLG],n;
/*
int dfs(int u,int p,int d){
	siz[u] = 1; depth[u] = d;
	dfs_in[u] = dfs_time++;
	P[u][0] = p;
	loop(i,MAXLG-1) P[u][i + 1] = P[P[u][i]][i];
	for(int v : G[u]) if(v != p){
		siz[v] += dfs(v,u,d+1);
	}
	dfs_out[u] = dfs_time - 1;
}
bool inSubTree(int a,int b){
	return dfs_in[b] <= dfs_in[a] && dfs_in[a] <= dfs_out[b];
}
int lca(int a,int b){
	if(depth[a] > depth[b]) swap(a,b);
	if(inSubTree(b,a)) return a;
	int k = MAXLG - 1;
	while(a != b){
		if(depth[a] > depth[b]) swap(a,b);
		while(k && inSubTree(a,P[b][k])) k--;
		b = P[b][k];
	}
	return a;
}
int dist(int a,int b){
	return depth[a] + depth[b] - 2*depth[lca(a,b)];
}
int LCA(int a,int b){
      int ans = 1;
      if(depth[a] > depth[b]) swap(a,b);
		if(inSubTree(b,1) && inSubTree(a,1)) {
			ans = lca(a,b);
		}
		else if(inSubTree(b,1) || inSubTree(a,1)) {
			ans = 1;
		}
		else if(inSubTree(1,b)) {
			if(inSubTree(a,b)) ans = lca(a,1);
			else ans = b;
		}
		else if(inSubTree(1,a)) {
			if(inSubTree(b,a)) ans = lca(b,1);
			else ans = a;
		}
		else if(inSubTree(b,a)) ans = a;
		else {
			ans = lca(a,1);
			if(dist(ans,1) > dist(1,lca(b,1))) ans = lca(b,1);
			if(inSubTree(a,ans) && inSubTree(b,ans)) ans = lca(a,b);
		}
      return ans;
}
*/
const int MAXN = 1e5+25;
const int MAXLOG = 25;
int Justice[MAX];
int Dp[MAX];
int par[MAXN][MAXLOG]; // initially all -1
int h[MAXLOG];
void dfs(int v,int p = -1){
      if(p==-1){
           Dp[v] = 1;
      }
      else{
            if(Justice[v] < Justice[Dp[p]])
                  Dp[v] = p;
            else
                  Dp[v] = v;
      }
	par[v][0] = p;
	if(p + 1)
		h[v] = h[p] + 1;
	for(int i = 1;i < MAXLOG;i ++)
		if(par[v][i-1] + 1)
			par[v][i] = par[par[v][i-1]][i-1];
	for(auto u : G[v])
            if(p - u)
		dfs(u,v);
}
int LCA(int v,int u){
	if(h[v] < h[u])
		swap(v,u);
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(par[v][i] + 1 and h[par[v][i]] >= h[u])
			v = par[v][i];
	// now h[v] = h[u]
	if(v == u)
		return v;
	for(int i = MAXLOG - 1;i >= 0;i --)
		if(par[v][i] - par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

int main(){
      memset(par,-1,sizeof(par));
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++){
            cin >> Justice[i];
      }
      for(int i=2;i<=n;i++){
            cin >> x;
            G[i].pb(x);
            G[x].pb(i);
      }
      dfs(1);
	//dfs(1,0,0);
	//dfs_out[0] = n-1;
	int m;

	cout << endl;
	scanf("%d",&m);
	while(m--){
	      int a,b;
            cin >> a >> b;
		int ans = LCA(a,b);

            cout << Dp[ans] << endl;
		//printf("%d\n",ans);
	}
	return 0;
}
