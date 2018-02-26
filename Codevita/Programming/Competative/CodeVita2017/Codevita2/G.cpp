#include<bits/stdc++.h>
using namespace::std;

#define ll  long long
#define ull unsigned ll
#define LD long double

#define mp make_pair
#define bs binary_search
#define gcd __gcd
#define pb push_back
#define pp pop_back
#define F first
#define S second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

#define rf freopen("input.txt","r",stdin)
#define wf freopen("output.txt","w",stdout)

#define Nitro ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define clk clock_t tStart = clock()
#define xtime printf("Execution Time : %.5fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC)
#define sz(a) (int)a.size()

vector<string> split(string str, char delimiter)
{
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;

  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }

  return internal;
}

int Arr[55];
void Process(string s)
{
	if(sz(s)<2)
		return;
	for(int i=0;i<sz(s)-1;i++){
		Arr[s[i]-'0'] = s[sz(s)-1]-'0';
	}
	return;
}
int main()
{
   string input,key;
   string val;

  // getline(cin,input);
  // getline(cin,key);

   cin >> input;
   cin >> key;
   string Res = key;

   set<char> Dist;
   for(int i=0;i<sz(key);i++){
   		Dist.insert(key[i]);
   }



   memset(Arr,-1,sizeof(Arr));

//   cout << input << endl;
//   cout << key << endl;

   vector<string> sep = split(input, '|');
   bool ok = true;
   bool Fine = true;

   for(auto it = sep.begin();it!=sep.end();it++){
   //	cout << *it << endl;
   		string st = *it;
   		if(!(st[0]>='0' && st[0]<='9'))
   			ok = false;
   		if(ok)
   			Process(st);
    	if(!ok)
    		val = st;
    }

    bool neg = false;
    for(int i=0;i<10;i++){

    	if(Arr[i]==-1){
    		neg = true;
    		continue;
    	}
    	if(neg && Arr[i]!=-1){
    		Fine = false;
    	}
    }


	if(sz(Dist) != 10)
	   	Fine = false;

	    for(int i=0;i<sz(val)-1;i++){
	    	Arr[val[i]-'0'] += 10;
	    }

   // cout << endl;
    int Idx = 0;
    for(int i=0;i<10;i++){

    	if(Arr[i]==-1){
    		Idx = i-1;
    		break;
    	}
    	//cout << i << " " << Arr[i] << endl;
    }

    int Brr[55];
    memset(Brr,0,sizeof(Brr));

    Brr[0]  = Arr[0] - (val[sz(val)-1]-'0');
    int k = 0;

    for(int i=Idx;i>=1;i--){
    	//cout << Arr[i] << "---"<< Idx << endl;
    	Brr[i] = Arr[i] - Brr[k];
    	k = i;
    }
    for(int i=0;i<=Idx;i++){
    	if(Brr[i] >= sz(key))
    		Fine = false;
    }
    //cout << "OK " << endl;
    if(Fine){
	    for(int i=0 ;i<=Idx;i++){
	    	cout << Res[Brr[i]];
	    }
	}
	else{
		cout << "-1";
	}
   // cout << val << " " << Idx << endl;
    return 0;
}
