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

vector<string> perm;

ll toInteger(string s){
    ll ret = 0;
    for(int i=0;i<(int)s.length();i++){
        ret = ret*10 + (s[i]-'0');
    }
    return ret;
}

#define Nitro ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
    Nitro;

    string s("0123456789");
    int N,ranki;
    ll res = 0;
    int x;
    vector<int> RankArr;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> x;
        RankArr.push_back(x);
    }
    if(N==0){
        cout << "0" << endl;
        return 0;
    }

    sort(RankArr.begin(),RankArr.end());
    int i=0;

    if(RankArr[0] == 1){
        assert(RankArr[0]>=0 && RankArr[0]<=3628800);
        res += toInteger(s);
        i++;
    }
    int curr = 2;
    while(next_permutation(s.begin(),s.end())){
        if(i==N) break;
        while(RankArr[i]==curr && i<N){
            assert(RankArr[i]>=0 && RankArr[i]<=3628800);
            //cout << s << endl;
            res += toInteger(s);
            i++;
        }

        curr++;

    }
    assert(i==N);
    cout << res << endl;
	return 0;
}
