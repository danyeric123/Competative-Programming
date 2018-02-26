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

map<int,int> lru;
unordered_map<int,int> times;
int N,S;
int t = 0;
void lruCache(int x){
    t++;
    if(lru.size() == S)
        lru.erase(lru.begin());
    if(lru.find(times[x]) != lru.end())
        lru.erase(lru.find(times[x]));
    lru[t] =  x;
    times[x] = t;
    return;
}
int main(){
    int T;
    int x;
    cin >> T;
    while(T--){
        cin >> N >> S;
        lru.clear();
        times.clear();
        for(int i=0;i<N;i++){
            cin >> x;
            lruCache(x);
        }
        vector<int> vec;
        for(auto x : lru){
            vec.pb(x.second);
        }
        while(vec.size() < S) vec.pb(0);
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
