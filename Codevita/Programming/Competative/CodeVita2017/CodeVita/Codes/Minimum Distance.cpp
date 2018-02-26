#pragma warning(suppress: 4101)
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

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

long double x,y,va,vb;

bool Check(){
    if(x>0 && y>0 && va>0 && vb>0){
        return true;
    }
    return false;
}

int main()
{

    cin >> x >> y >> va >> vb;

    if(!Check()){
        cout << "Invalid Input";
    }
    else{
        long double d = sqrt(x*x+y*y);
        while(true){
            x = x-va;
            y = y-vb;
            long double temp = sqrt(x*x+y*y);
            if(temp > d)
                break;
            d = temp;
        }
        if(d==0.00)
            printf("0.0");
        else
            printf("%.11Lf",d);
    }
    return 0;
}
