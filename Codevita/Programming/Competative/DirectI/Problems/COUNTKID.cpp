#include<bits/stdc++.h>
using namespace::std;

#define ll  long long
#define ull unsigned ll
#define LD long double

#define mp make_pair
#define bs binary_search
#define gcd __gcd
#define pb push_back
#define pp pop_back
#define ff first
#define ss second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL


ll A[10005];
int mod = 1e9+7;
void pre(){
    A[0] = 1;
    A[1] = 2;
    A[2] = 5;
    for(int i=3;i<=1000;i++){
        A[i] = (2*A[i-1]+A[i-2]+A[i-3])%mod;
    }
    A[0] = 0;
    for(int i=0;i<=1000;i++){
        cout << A[i] << endl;
    }
}
int main(){
    freopen("cntKid.txt","w",stdout);
    pre();

}
