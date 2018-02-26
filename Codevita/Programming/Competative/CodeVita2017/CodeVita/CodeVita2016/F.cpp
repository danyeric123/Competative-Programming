#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace::std;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define N 100005
#define MOD 1000000007
#define lli long long int
int mc[10000][10000];
struct team
{
	int id;
	char teamName[20];
	int gd;
	int gf;
	int pts;
};

int maxm(int x,int y)
{
	if(x<y)
		return 1;
	if(y<x)
		return 0;
}

bool predicate(const team &l, const team &r)
{
	if(l.pts-r.pts)
		return maxm(l.pts,r.pts);
	if(l.gd-r.gd)
		return maxm(l.gd,r.gd);
	if(l.gf-r.gf)
		return maxm(l.gf,r.gf);
	if(l.teamName > r.teamName)
		return 1;
	else
		return 0;
}

int main()
{
	int tc,n,i,mt,x,y;
	char a[100],b[100];
	bool flag;
	scanf("%d",&n);
	std::string s,t;
	std::vector<team> v;
	std::vector<team>::iterator its;
	std::map<std::string,team> m;
	std::map<std::string,team>::iterator it,it1,it2;
	for(i=0;i<n;i++)
	{
		std::cin>>s;
		team t;
		strcpy(t.teamName,s.c_str());
		t.id=i; t.gd=0; t.gf=0; t.pts=0;
		m[s]=t;
	}
	scanf("%d",&mt);
	flag=false;
	for(i=0;i<mt;i++)
	{
		std::cin>>s>>t;
		scanf("%d%d",&x,&y);
		it1=m.find(s);
		it2=m.find(t);
		if(mc[it1->s.id][it2->s.id]==2 || it1==it2)
		{
			flag=true;
			break;
		}
		mc[it1->s.id][it2->s.id]++;   mc[it2->s.id][it1->s.id]++; //updating match count
		it1->s.gf += x;               it2->s.gf += y;   //updating goals for
        if(x>y)
		{
			it1->s.pts += 2;
			it1->s.gd += x-y;
			it2->s.gd += y-x;
		}
		else if(x==y)
		{
			it1->s.pts += 1;
			it2->s.pts += 1;
		}
		else
		{
			it2->s.pts += 2;
			it1->s.gd += x-y;
			it2->s.gd += y-x;
		}
	}
	for(it=m.begin(); it!=m.end(); it++)
	{
		v.pb(it->s);
	}

	sort(v.rbegin(),v.rend(),&predicate);
	//sort and print
	for(auto it=v.begin();it!=v.end();it++){
        cout << it->id << " " << it->teamName << " " << it->gd << " " << it-> gf  << " " << it->pts << endl;
	}



}
