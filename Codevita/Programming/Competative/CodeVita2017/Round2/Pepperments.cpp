#include<bits/stdc++.h>
using namespace::std;

#define ll  long long
#define ull unsigned ll
#define LD long double

#define MP make_pair
#define BS binary_search
#define GCD __gcd
#define pb push_back
#define pp pop_back
#define ff first
#define ss second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define sz(a) (int)a.size()

int main() {
    scanf("%ld",&tc);
    while(tc--)
    {
    scanf("%ld%ld",&n,&m);
        if(n<0) n=0;
        if(m<0) m=0;
        days=n;
        m+=n;
        while(m>=7)
        {
        days+=m/7;
        m=m/7+m%7;
        }
    printf("%ld\n",days);
    }
	return 0;
}
