#include<bits/stdc++.h>
using namespace::std;

#define ll  long long
#define ull unsigned ll
#define LD long double

#define MP make_pair
#define BS binary_search
#define GCD __gcd
#define pb push_back
#define pp pop_back
#define ff first
#define ss second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define sz(a) (int)a.size()

string getNonDec(string s){
    bool ok=false;
    int i;
    for(i=0;i<(int)s.size()-1;i++){
        if(s[i]>s[i+1]) { ok = true; break;}
    }
    if(ok){
        while(i>=1 && s[i]==s[i-1])
        i--;
        s[i]=s[i]-1;
        for(int j=i+1;j<(int)s.size();j++)
        s[j]='9';
    }
    while((int)s.size() && s[0]=='0')
        s.erase(s.begin());
    return s;
}

int main(){
    string N;
    cin >> N;
    string res = getNonDec(N);
    cout << res << endl;
    return 0;
}

