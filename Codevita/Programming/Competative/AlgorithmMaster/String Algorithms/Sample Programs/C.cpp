#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> Array;

ll MinimumCost() 
{
    priority_queue< ll, vector<ll>, greater<ll> > pque;
    ll i, cost;
    cost = 0;
    for (i = 0; i < (int)Array.size(); i++) {
        pque.push(Array[i]);
    }

    while (pque.size() > 1) {
        i = pque.top();
        pque.pop();
        i += pque.top();
        pque.pop();
        pque.push(i);
        cost += i;
    }
    return cost;
}

int main () {

	ll T,N;
	ll x;
	ll Cost = 0;
	cin >> T;
	while(T--)
	{
		cin >> N;
		for(ll i=0;i<N;i++){
			cin >> x;
			Array.push_back(x);

		}
		if(N!=1){
			cout << MinimumCost();
		}
		else{
			cout << Array[0];
		}
		if(T)
			cout << endl;


		Array.clear();
	}



    return 0;
}