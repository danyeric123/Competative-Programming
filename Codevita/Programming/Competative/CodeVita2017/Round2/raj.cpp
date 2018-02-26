#include<bits/stdc++.h>
using namespace::std;
int a[1000005];
int main() {

        int tmax;
        cin >> tmax;
        for(int tc=1;tc<=tmax;tc++)
        {
            int n,q;
            cin >> n >> q;

         for(int i=0;i<n;i++)
            cin >> a[i];

          for(int i=n-1;i>0;i--)
            {
             if(a[i]-1>a[i-1])
                 a[i-1]=a[i]-1;
            }

            for(int i=0;i<n-1;i++)
            {
            if(a[i]-1>a[i+1])
                a[i+1]=a[i]-1;

            }
          cout << (a[q-1]) << endl;

        }
    return 0;
}
