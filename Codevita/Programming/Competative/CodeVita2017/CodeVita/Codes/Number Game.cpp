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
#define F first
#define S second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

const int MAX = 100025;
bool Prime[MAX+25];

void Sieve()
{
		memset(Prime,1,sizeof(Prime));
		int i,j;
		Prime[0]=Prime[1]=0;
		for(i=2;i<sqrt(MAX);i++)
            if(Prime[i])
		          for(j=i*i;j<=MAX;j+=i)
                    Prime[j]=0;
}


int main()
{
    Sieve();
    bool np = false;
    int N,Ai;
    int p=0;
    cin >> N;
    for(int i=0 ;i<N;i++){
        cin >> Ai;
        if(!Prime[Ai])
            np = true;
        else
            p++;
    }

    if(!np){
        if(N&1)
            printf("JASBIR");
        else
            printf("AMAN");
    }
    else{
            printf("AMAN");
    }

    return 0;
}
