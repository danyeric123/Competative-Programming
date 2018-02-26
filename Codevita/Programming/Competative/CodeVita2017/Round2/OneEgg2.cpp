#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
vector<pii> eggs;
int m, x, sigma;
vector<int> a, b;

bool cmp(const pii& p, const pii& q) {
    if(p.first == q.first) {
        return p.second < q.second;
    }
    return p.first > q.first;
}

void solve() {
    sort(eggs.begin(), eggs.end(), cmp);
    for(int i = 0; i < m; i++) {
        if(eggs[i].first <= x) {
            x -= eggs[i].first;
            b[eggs[i].second] = a[eggs[i].second];
        } else {
            b[eggs[i].second] = x;
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    sigma = 0;
    cin >> m >> x;
    for(int i = 0; i < m; i++) {
        int n;
        cin >> n;
        eggs.push_back(make_pair(n, i));
        a.push_back(n);
        b.push_back(0);
        sigma += n;
    }
    if(sigma > x) {
        cout << "Thank you, your order for " << x << " eggs are accepted" << endl;
    } else {
        x = sigma - 1;
        cout << "Sorry, we can only supply " << x << " eggs" << endl;
    }
    solve();
    for(int i = 0; i < m; i++) {
        cout << a[i] << " " << b[i] << " " << (a[i] - b[i]) << endl;
    }
    return 0;
}

