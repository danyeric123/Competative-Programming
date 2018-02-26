#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <iomanip> //setprecision
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;

#define ll long long int
#define ld long double
#define form(i,m) for(i=m.begin();i!=m.end();i++)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define X it->first
#define Y it->second
#define cls(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>

const int INF = (int)1e9;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

ll fact[15];
void pre()
{
	fact[0]=1;
	fact[1]=1;
	for(int i=2;i<15;i++)
		fact[i]=i*fact[i-1];

}
int main() {
	ios_base::sync_with_stdio(false);
	pre();
	int t=1;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		map<char,vector<int> >m;
		map<char,bool>m2;
		map<char,vector<int> >::iterator it,it1;
		string a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];

			int l=a[i].length();
			//cout<<a[i]<<" "<<l<<endl;

			for(int j=0;j<l;j++)
			{
				if(find(m[a[i][j]].begin(), m[a[i][j]].end(), i)==m[a[i][j]].end())
					m[a[i][j]].pb(i);
				m2[a[i][j]]=true;
			}
		}
		ll ans=1;

		for(it=m.begin();it!=m.end();it++)
		{
			int c=1;
			m2[it->first]=false;

			for(it1=it;it1!=m.end();it1++)
			{
				if(m2[it1->first]==false)
					continue;

				if(it->second==it1->second)
				{
					c++;
					m2[it1->first]=false;
				}
			}

			ans=ans*fact[c];
		}

		cout<<ans<<endl;
	}
	return 0;
}
