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

int Arr[1000];
int Req[1000];
int main(){
    int N;
    cin >> N;
    ll sum = 0;
    for(int i=1;i<=N;i++){
        cin >> Arr[i];
        sum += Arr[i];
    }
    ll sum2 = 3*(N)*(N-1)/2;
    if((sum-sum2)%N != 0){
        cout << "No" << endl;
        return 0;
    }
    ll a = (sum-sum2)/N;
    for(int i=1;i<=N;i++){
        Req[i] = a;
        a += 3;
    }
    priority_queue<int> have;
    priority_queue<int> want;
    for(int i=1;i<=N;i++){
        if(Req[i]-Arr[i] < 0){
            want.push(Arr[i]-Req[i]);
        }
        if(Req[i]-Arr[i]>0){
            have.push(Req[i]-Arr[i]);
        }
    }
    int cnt = 0;
    while(!want.empty()){
        int x = want.top(); want.pop();
        int y = have.top(); have.pop();
        //cout << x << " " << y << endl;
        if(x==y) {
            cnt++;
        }
        else if(x>y){
            want.push(x-y);
            cnt++;
        }
        else{
            have.push(y-x);
        }
    }
    cout << "Yes " << cnt << endl;
	return 0;
}
