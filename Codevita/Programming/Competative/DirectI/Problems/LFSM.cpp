#include<bits/stdc++.h>
using namespace::std;
int maxDiameterSum(int nodes, int tree[511]){
    int tp = nodes+1;
    int leafs = tp/2;
    int Max = 0;
    for(int i=nodes-leafs;i<nodes;i++){
        for(int j=nodes-leafs;j<nodes;j++){
            int sum = 0;
            int u = i,v=j;
            while( u != v){
                sum += tree[u];
                sum += tree[v];
                u = (u-1)/2;
                v = (v-1)/2;
            }
            sum += tree[v];
            Max = max(Max,sum);
        }
    }
    return Max;
}
int main(){
    int T;
    int Tree[512];
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        for(int i=0;i<N;i++){
            cin >> Tree[i];
        }
        cout << maxDiameterSum(N,Tree) << endl;
    }
}
