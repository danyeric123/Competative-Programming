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

int input[1005];
vector<int> LongestSeq(1005);
vector<int> ssq(1005);

void init(int N){
   for (int i = 0; i < N; i++){
      LongestSeq[i] = 1;
      ssq[i] = 1;
   }
}

int ComputeSkiSequence( int N ){
   for (int i = 1; i < N; i++){
      for (int j = 0; j < i; j++)
         if (input[i] > input[j] && LongestSeq[i] < LongestSeq[j] + 1){
            LongestSeq[i] = LongestSeq[j] + 1;
         }
   }

   for (int i = N-2; i >= 0; i--){
      for (int j = N-1; j > i; j--)
         if (input[i] > input[j] && ssq[i] < ssq[j] + 1){
            ssq[i] = ssq[j] + 1;
         }
   }

   ll res = 0;
   for (int i = 0; i < N; i++){
     if (LongestSeq[i] + ssq[i] - 1 > res && LongestSeq[i] > 1 && ssq[i] > 1){
         res = LongestSeq[i] + ssq[i] - 1;
     }
   }
   return res;
}

int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		int x, y;
		scanf("%d,%d",&x,&y);
		if(x%2 == 1 && y%2==1){
			input[i] = max(x, y);
		} else if((x%2 == 1 && y%2==0) || (x%2 == 0 && y%2==1) ){
			input[i] = y%2==0 ? y : x;
		} else {
			input[i] = min(x, y);
		}
	}
    init(N);
	ll res = ComputeSkiSequence(N);
	if(res == 0){
		cout << "Impossible" << endl;
	}
	else{
        cout << res << endl;
	}
	return 0;
}
