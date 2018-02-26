#include<bits/stdc++.h>
using namespace::std;

string Solve(string s1,string s2){
    int sz = min(s1.size(),s2.size());
    string ret;
    for(int i=0;i<sz;i++){
        if(s1[i]=='F')
            ret.push_back('|');
        else{
            ret.push_back(s1[i]);
        }
        if(s2[i]=='F')
            ret.push_back('|');
        else{
            ret.push_back(s2[i]);
        }
    }
    return ret;
}

int main()
{
    freopen("file1.txt","r",stdin);
    string s1,s2,res;
    while((cin >> s1)){
        cin >> s2;
        res = Solve(s1,s2);
        cout << res << endl;
    }
    return 0;
}
