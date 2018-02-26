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

bool Valid = true;
bool isLeap(int year)
{
	if ( year%400 == 0)
   		return 1;
 	else if ( year%100 == 0)
   		return 0;
  	else if ( year%4 == 0 )
    	return 1;
  	else
    	return 0;
}

bool isDateValid(int month, int day, int year)
{
    return (month >= 1 && month <= 12 &&
           day >= 1 &&
           day <= (month == 2 ? (isLeap(year) ? 29 : 28) :
                   month == 9 || month == 4 || month == 6 || month == 11 ? 30 : 31));
                   
}

bool isDayValid(string M){
	string v[] ={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	for(int i=0;i<=6;i++){
		if(M==v[i])
			return true;
	}
	return false;
}
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

int convert(string s)
{	
	int ret = 0;
	for(int i=0;i<sz(s);i++){
		if(s[i]>='0' && s[i] <='9'){
			ret = ret*10 + s[i]-'0';
		}
		else{
			Valid = false;
		}
	}
	return ret;
}
int main()
{
    string date,day;
    cin >> day;

    if(!isDayValid(day)){
    	cout << "Invalid Day";
    	return 0;
    }

    cin >> date;
    int dd,mm,yy;
    vector<string> sep = split(date, '/');
    if(sz(sep) != 3)
    	Valid = false;
    else{
    	dd = convert(sep[0]);
    	mm = convert(sep[1]);
    	yy = convert(sep[2]);
    }

    /*
    for(auto it = sep.begin();it!=sep.end();it++){
    	cout << *it << endl;
    }
    */
    
    if(!isDateValid(mm,dd,yy)){
    	cout << "Invalid Date";
    	return 0;
    }

    int Ans = 0;
 
    map<int,int> days;
    days[1] = 31;
    days[2] = 28;
    days[3] = 31;
    days[4] = 30;
    days[5] = 31;
    days[6] = 30;
    days[7] = 31;
    days[8] = 31;
    days[9] = 30;
    days[10] = 31;
    days[11] = 30;
    days[12] = 31;

    int d = 0;
    for(int i=1;i<mm;i++){
    	d += days[i];
    }	

    Ans = d + dd;
    if(Ans>50)
    	Ans = 50;


    if(isLeap(yy)){
    	Ans = 0;
    }
    cout << Ans << endl;

	return 0;
}
