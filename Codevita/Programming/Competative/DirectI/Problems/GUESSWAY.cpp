#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define ll unsigned long long

ll travel(ll h, ll n, ll t){
    ll tot;

    if (h == 0)
        return 0LL;
    tot = 1LL << h;
    if (t == 0){
        if (n <= tot/2)
            return travel(h - 1, n, 1) + 1;
        else
            return tot + travel(h - 1, n - tot/2, 0);
    }
    else{
        if (n <= tot/2)
            return tot + travel(h - 1, n, 1);
        else
            return travel(h - 1, n - tot/2, 0) + 1;
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        ll h;
        ll n, res;

        cin >> h >> n;
        cout << travel(h, n, 0);
    }
    return 0;
}
