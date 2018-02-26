#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<pair<int,int> >v;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			v.push_back(make_pair(a,i));
		}
		sort(v.begin(), v.end());
		std::vector<int> vis(n,0);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(vis[i] || v[i].second==i)
				continue;
			int cyc_size = 0;
			int j=i;
			while(!vis[j])
			{
				vis[j]=1;
				cyc_size++;
				j=v[j].second;
			}
			cyc_size++;
			ans=ans+cyc_size;
		}
		 cout<<ans<<endl;

	}
}
