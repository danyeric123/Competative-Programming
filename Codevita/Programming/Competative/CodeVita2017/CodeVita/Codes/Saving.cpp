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
#define F first
#define S second

LD M,T,R;
LD PM;

bool Ok(int x){
    LD P = (LD)x;
    for(int i=1;i<=T;i++){
        P = P + (LD)P*PM/100.00;
        P = P - M;
      // cout << x << " : " << P << " " << endl;
    }
    if(P>=-0.49999999999)
        return true;
    return false;

}

int main(){

    cin >> M >> T >> R;

    PM = (LD)R/12.000;

    int Low = 0, High = M*T;
    int Mid;
    while(Low < High){

        Mid = (Low+High)/2;
        //cout << Low << " " << High << " " << Mid << endl;
        if(Ok(Mid)){
           High = Mid;
        }
        else{
            Low = Mid+1;
        }
    }

    cout << High;

}
