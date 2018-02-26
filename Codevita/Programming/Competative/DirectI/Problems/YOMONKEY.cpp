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

int danceTime(int N,int P[100]){
    bool ok[100];
    memset(ok,false,sizeof(ok));
    for(int i=0;i<N;i++) P[i]--;
    int time = 0;
    for(int i=0;i<N;i++){
        vector<int> idx;
        int id = i;
        if(!ok[id]){
            idx.pb(P[id]);
            int t = id;
            id = P[id];
            while(id != t){
                id = P[id];
                idx.pb(id);
            }
            time = max(time,(int)idx.size());

            cout << idx.size() << endl;
            for(auto x : idx){
                ok[x] = true;
                cout << x+1 << " ";
            }
            cout << endl;


        }
    }
    return time;
}
int main(){
    int P[100] = {4, 11, 9 ,6 ,7 ,1, 2 ,5 ,3 ,8 ,10};
    int Q[100] = {2,3,1};
    cout << "::" << danceTime(3,Q) << endl;
    cout << "::" << danceTime(11,P) << endl;
    return 0;
}
