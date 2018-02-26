#pragma warning(suppress: 4101)
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

const int MAX = 2e6;
vector<bool> Prime(MAX+25,1);
vector<ll> Primes;
void Sieve()
{

    int i,j;
    Prime[0]=Prime[1]=0;
    for(i=2;i<sqrt(MAX);i++)
    {
        if(Prime[i])
        {
            for(j=i*i;j<=MAX;j+=i)
            Prime[j]=0;
        }
    }

    for(int i=2;i<=MAX;i++){
        if(Prime[i])
            Primes.push_back(i);
    }

}

int PrimeTest(ll x)
{
    if(x<MAX)
        return Prime[x];
    if(x%6!=1 && x%6!=5)
        return 0;
    ll sqt = sqrt(x);
    for(int i=2;i<=sqt;i++)
        if(x%i==0)
            return 0;
    return 1;
}

vector<ll> Result;
ll MAXSUM = 12000000000LL;

void Process()
{
    ll Sum = 2;
    for(int i=1;i<(int)Primes.size();i++){
        Sum += Primes[i];
        if(Sum <= MAXSUM){
            if(PrimeTest(Sum)){
                Result.pb(Sum);
            }
        }
        else{
            break;
        }
    }
    //cout << Result.size();
    //cout << Sum << endl;
}

void Solve(ll N)
{
    int res = upper_bound(Result.begin(),Result.end(),N)- Result.begin();
    cout << res ;
    return ;
}

int main()
{
    Sieve();
    Process();
    ll N;

    /*
    for(int i=0;i<20;i++){
        cout << Primes[i] << endl;
    }
    */

    cin >> N;

    Solve(N);

    return 0;
}

