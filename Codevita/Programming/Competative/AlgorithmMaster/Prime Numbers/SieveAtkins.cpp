#include <bits/stdc++.h>
using namespace std;
const int Max = 1e8;
bool Prime[Max+25];
void SieveOfAtkin()
{
    for (int x = 1; x*x < Max; x++)
    {
        for (int y = 1; y*y < Max; y++)
        {
            int n = (4*x*x)+(y*y);
            if (n <= Max && (n % 12 == 1 || n % 12 == 5))
                Prime[n] ^= true;
            n = (3*x*x)+(y*y);
            if (n <= Max && n % 12 == 7)
                Prime[n] ^= true;
            n = (3*x*x)-(y*y);
            if (x > y && n <= Max && n % 12 == 11)
                Prime[n] ^= true;
        }
    }
    for (int r = 5; r*r < Max; r++)
    {
        if (Prime[r])
        {
            for (int i = r*r; i < Max; i += r*r)
                Prime[i] = false;
         }
    }
    return;
}

int main()
{
    SieveOfAtkin();
    for(int i=1;i<=500;i++){
        if(Prime[i])
            cout << i << endl;
    }
    return 0;
}
