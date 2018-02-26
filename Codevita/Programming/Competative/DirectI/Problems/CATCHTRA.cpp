#include<bits/stdc++.h>
using namespace std;
int main()
{
  /*  double w,s;
    s=(double)L/Ve;w=(double)L/(Ve+Vy);
    return min((double)(s-w)/T,1.0);

    double a = 1.0 * L / vE;
    double b = 1.0 * L / (vE+vY);
    double p = Math.abs((a-b)/T);
    if(p > 1)
      return 1;
    return p;
*/
    int t;
    cin>>t;
    while(t--){
        long double ve,l,vy,t,td;
        cin>>ve>>vy>>l>>t;
        long double c = ( long double)1.0/ve;
        c = c - (long double)1.0/(ve+vy);
        c = c*l;
        long double ans = c/t;
        if(ans>1.0)
            ans=1.0;
        cout << setprecision(25) << fixed << ans << endl;

    }
}
