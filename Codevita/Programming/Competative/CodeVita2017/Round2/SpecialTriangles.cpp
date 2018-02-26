#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
typedef int lol;
const lol INF = 1000000000000;
struct rect
{
	lol x1, y1, x2, y2;
};
int main()
{
	lol n;
	scanf("%lld", &n);
	set <lol> x;
	set <lol> y;
	vector <lol> x_vec;
	vector <lol> y_vec;
	vector <rect> LST(n);
	for(lol i = 0; i < n; i++)
	{
		lol a, b, c, d;
		scanf("%lld,%lld,%lld,%lld", &a, &b, &c, &d);
		x.insert(a);
		x.insert(c);
		y.insert(b);
		y.insert(d);
		LST[i].x1 = a;
		LST[i].y1 = b;
		LST[i].x2 = c;
		LST[i].y2 = d;
	}
	for(set<int> :: iterator it = x.begin(); it != x.end(); ++it)
	{
		x_vec.push_back(*it);
	}
	for(set<int> :: iterator it = y.begin(); it != y.end(); ++it)
	{
		y_vec.push_back(*it);
	}
	vector <vector <lol> > scanline(x_vec.size(), vector <lol>(y_vec.size(), 0));
	for(lol i = 0; i < n; i++)
	{
		lol x1 = lower_bound(x_vec.begin(), x_vec.end(), LST[i].x1) - x_vec.begin();
		lol x2 = lower_bound(x_vec.begin(), x_vec.end(), LST[i].x2) - x_vec.begin() - 1;
		lol y1 = lower_bound(y_vec.begin(), y_vec.end(), LST[i].y1) - y_vec.begin();
		lol y2 = lower_bound(y_vec.begin(), y_vec.end(), LST[i].y2) - y_vec.begin() - 1;
		if((x2 >= x1)&&(y2 >= y1))
		{
			for(lol i = y1; i <= y2; i++)
			{
				scanline[x1][i]++;
				scanline[x2 + 1][i]--;
			}
		}
	}
	lol ans = 0;
	for(lol j = 0; j < y_vec.size() - 1; j++)
	{
		lol open = 0;
		for(lol i = 0; i < x_vec.size() - 1; i++)
		{
			open += scanline[i][j];
			if(open > 0)
			{
				long long a = x_vec[i + 1] - x_vec[i];
				long long b = y_vec[j + 1] - y_vec[j];
				ans += a*b;
			}
		}
	}
	printf("%lld", ans);
    return 0;
}
