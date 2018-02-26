#include <bits/stdc++.h>
using namespace::std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define trace(x) cerr  << "(" << __FUNCTION__ << " : " << __LINE__ << ") " << #x << " : " << x << endl;
#define INF 1234567
map<int,int> Parent;
int main(){
    int N,x;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x;
        assert(Parent.find(i) == Parent.end());
        Parent[i] = x;
    }
    int a,b;
    cin >> a >> b;
    int u = a,v = b;
    vector<int> List1,List2;
    while(u != -1){
        List1.push_back(u); u = Parent[u];
    }
    while(v != -1){
        List2.push_back(v); v = Parent[v];
    }
    reverse(List1.begin(),List1.end());
    reverse(List2.begin(),List2.end());
    int ans = -1;
    int i=0,j=0;
    while(i< List1.size() && j<List2.size()){
        if(List1[i] == List2[j]){
            ans = List1[i];
            i++; j++;
        }
        else
            break;
    }
    if(ans == a) ans = Parent[a];
    if(ans == b) ans = Parent[b];
    cout << ans << endl;

    return 0;
}
