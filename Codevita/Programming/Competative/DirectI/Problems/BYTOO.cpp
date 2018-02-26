#include<bits/stdc++.h>
using namespace::std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int N,M,x;
        vector<int> vec;
        cin >> N >> M;
        for(int i=0;i<M;i++){
            cin >> x;
            vec.push_back(x);
        }
        sort(vec.begin(),vec.end());
        bool ok = true;
        if(vec[0] == 1)
            ok = false;
        for(int i=0;i<vec.size()-2;i++){
            if(vec[i]+1 == vec[i+1] && vec[i+1]+1 == vec[i+2]){
                ok = false;
            }
        }
        puts(ok?"YES":"NO");
    }
    return 0;
}
