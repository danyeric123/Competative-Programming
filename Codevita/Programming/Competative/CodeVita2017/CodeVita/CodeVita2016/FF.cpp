#include<bits/stdc++.h>
using namespace std;
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
	string teamName;
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
    string s1 =  l.teamName;
    string s2 = r.teamName;
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
	if(s1 > s2)
		return 1;
	else
		return 0;
}

vector<team> v;
vector<team>::iterator its;
map<string,team> m;
map<string,int> ct;
map<std::string,team>::iterator it,it1,it2;

int main()
{
	int n,i,mt,x,y;
	bool flag;
	scanf("%d",&n);
	string s,t;


    flag=false;
	for(i=0;i<n;i++)
	{
		std::cin >> s;
		team t;
		t.teamName = s;
		t.id=i; t.gd=0; t.gf=0; t.pts=0;
        if(ct[s]!=0)
            flag = true;
		m[s]=t;
		ct[s]=1;
	}

	scanf("%d",&mt);

	for(i=0;i<mt;i++)
	{
		std::cin >>s >> t;
		scanf("%d %d",&x,&y);
		it1=m.find(s);
		it2=m.find(t);
		if(mc[it1->s.id][it2->s.id]==2 || it1==it2)
		{
			flag=true;
			break;
		}

		mc[it1->s.id][it2->s.id]++;   mc[it2->s.id][it1->s.id]++;
		it1->s.gd += x-y;	   		  it2->s.gd += y-x;
		it1->s.gf += x;               it2->s.gf += y;

		if(x>y)
		{
			it1->s.pts += 2;
		}
		else if(x==y)
		{
			it1->s.pts += 1;
			it2->s.pts += 1;
		}
		else
		{
			it2->s.pts += 2;
		}
	}
	if(flag==true)
	{
		printf("Invalid Input");
		return 0;
	}

	for(it=m.begin(); it!=m.end(); it++)
	{
		v.pb(it->s);
	}

	sort(v.rbegin(),v.rend(),&predicate);
	its = v.begin();

	cout << its->teamName;
    its++;

	for(;its!=v.end();its++)
	{
        cout << endl << its->teamName;
	}

	return 0;
}
