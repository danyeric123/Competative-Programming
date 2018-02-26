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

unordered_map<int,int> numX,numY;
vector< pair<int,int> > points;

int main(){
    int T;
    int x,y,N;
    cin >> T;
    while(T--){
        cin >> N;
        numX.clear();
        numY.clear();
        points.clear();
        for(int i=1;i<=N;i++){
            cin >> x >> y;
            points.pb(mp(x,y));
            numX[x]++;
            numY[y]++;
        }
        int num = 0;
        for(int i=0;i<points.size();i++){
            int x = points[i].first;
            int y = points[i].second;
            num += (numX[x]-1)*(numY[y]-1);
        }
        cout << num << endl;
    }
    return 0;
}
