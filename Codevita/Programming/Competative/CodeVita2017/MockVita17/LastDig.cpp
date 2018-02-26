#include <bits/stdc++.h>
using namespace::std;

#define TRACE(x) cerr<<"[[ "<<#x<<" = "<<x<<" ]]"<<endl;
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template <typename Arg1> void __f(const char* name, Arg1 && arg1) {
	cerr << name << " : " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

#else
#define trace(...)
#endif
#define Assert(x,y) {if(x!=y){cerr<<__LINE__ <<"->  Assertion Failed "<<": ("<<#x<<"!="<<y<<") ";TRACE(x);exit(1);}}

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
ll solve(ll N){
    ll sum = 0;
    for(ll i=0;(ll)powl(2,i)<=N;i++){
        cout << powl(2,i) << " " <<  i  << " " << N << endl;
        ll sum1  = 0;
        for(ll j=0;j<=N;j++){
            sum += powl(2,powl(2,i)+2*j);
            sum1 += powl(2,2*j);
        }
        cout << sum1 << endl;
    }
    cout << sum << endl;
}
int main(){
    ll N;
    while(1){
        cin >> N;
        solve(N);
    }
    return 0;
}

