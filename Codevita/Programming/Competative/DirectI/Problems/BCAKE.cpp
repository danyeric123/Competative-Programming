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

class cmp{
    public:
    bool operator() (pair<int,int> p, pair<int,int> q){
        int s1 = p.first;
        int c1 = p.second;
        int s2 = q.first;
        int c2 = q.second;
        if(s1*c2 != s2*c1) return s1*c2 < s2*c1;
        return s1 < s2;
    }
};

int main(){
    //while(true){
    priority_queue< pair<int,int> , vector< pair<int,int> >,cmp> pq;
    int N,B;
    int x;
    cin >> N >> B;
    for(int i=0;i<N;i++){
        cin >> x;
        pq.push(mp(x,1));
    }
    int cnt = B-N;

    while(cnt-- > 0){
        pair<int,int> tp = pq.top();
        pq.pop();
        tp.second++;
        pq.push(tp);
    }
    int Max = 0;
    while(!pq.empty()){
        int s = pq.top().first;
        int c = pq.top().second;
        Max = max(Max,s/c + (s%c != 0));
        cout << (pq.top().first)<< " " << (pq.top().second) << endl;
        pq.pop();
    }
    cout << Max << endl;
    //}
    return 0;
}

