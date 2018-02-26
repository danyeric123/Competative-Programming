#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
		unordered_map<string,int> vis;
		string s,f;
		int n;
		cin>>s>>f;
		n=s.length();
		int pos = 0;
		for(int i = 0 ; i<s.length(); i++){
			if(s[i]=='_'){
				pos = i;
				break;
			}
		}
		queue<pair<string,int> > q;
		q.push({s,pos});
		vis[s]=0;
		while(!q.empty()){
			string ss = q.front().first;
			int pp = q.front().second;
			int dist = vis[ss];
			q.pop();
			if(pp>0){
				swap(ss[pp],ss[pp-1]);
				if(!vis.count(ss)){
					if(ss==f){
						cout<<dist+1<<"\n";
						break;
					}
					vis[ss]=dist+1;
					q.push({ss,pp-1});
				}
				swap(ss[pp],ss[pp-1]);
			}
			if(pp<n-1){
				swap(ss[pp],ss[pp+1]);
				if(!vis.count(ss)){
					if(ss==f){
						cout<<dist+1<<"\n";
						break;
					}
					vis[ss]=dist+1;
					q.push({ss,pp+1});
				}
				swap(ss[pp],ss[pp+1]);
			}
			if(pp>1 && ss[pp-1]!=ss[pp-2]){
				swap(ss[pp],ss[pp-2]);
				if(!vis.count(ss)){
					if(ss==f){
						cout<<dist+1<<"\n";
						break;
					}
					vis[ss]=dist+1;
					q.push({ss,pp-2});
				}
				swap(ss[pp],ss[pp-2]);
			}
			if(pp<n-2 && ss[pp+1]!=ss[pp+2]){
				swap(ss[pp],ss[pp+2]);
				if(!vis.count(ss)){
					if(ss==f){
						cout<<dist+1<<"\n";
						break;
					}
					vis[ss]=dist+1;
					q.push({ss,pp+2});
				}
				swap(ss[pp],ss[pp+2]);
			}
		}
	}
	return 0;
}
