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

int Arr[10005];
int main(){
    int T,N;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i=1;i<=N;i++){
            cin >> Arr[i];
        }
        int Min= Arr[1];
        int res = N-1;
        for(int i=2;i<=N;i++){
            if(Arr[i] < Min){
                Min = Arr[i];
                res--;
            }
        }
        cout << res << endl;
    }
    return 0;
}
