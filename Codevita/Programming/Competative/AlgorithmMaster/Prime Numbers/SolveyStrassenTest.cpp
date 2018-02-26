#include<bits/stdc++.h>
using namespace::std;
typedef long long ll;

ll MulMod(ll A,ll B,ll Mod)
{
    ll x=0,y=A%Mod;
    while(B>0)
    {
        if(B&1)
            x=(x+y)%Mod;
        y=(y*2)%Mod;
        B=B/2;
    }
    return x%Mod;
}

ll ModExp(ll Base,ll Exp,ll Mod)
{
    ll Ans=1;
    while(Exp>0)
    {
        if(Exp&1) Ans=MulMod(Ans,Base,Mod);
        Base = MulMod(Base,Base,Mod);
        Exp = Exp>>1LL;
    }
    return Ans;
}

ll calculateJacobian(ll a,ll n)
{
    if (!a)
        return 0;
    ll ans = 1;
    if (a < 0)
    {
        a = -a;
        if (n % 4 == 3)
            ans=-ans;
    }
    if (a == 1)
        return ans;
    while (a)
    {
        if (a < 0)
        {
            a = -a;
            if (n % 4 == 3)
                ans = -ans;
        }
        while (a % 2 == 0)
        {
            a = a / 2;
            if (n % 8 == 3 || n % 8 == 5)
                ans = -ans;
        }
        swap(a, n);
        if (a % 4 == 3 && n % 4 == 3)
            ans = -ans;
        a = a % n;
        if (a > n / 2)
            a = a - n;
    }
    if (n == 1)
        return ans;
    return 0;
}

bool Solovoy(ll p, int iteration)
{
    if (p < 2)
        return false;
    if (p != 2 && p % 2 == 0)
        return false;
    for (int i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1;
        ll jacobian = (p + calculateJacobian(a, p)) % p;
        ll mod = ModExp(a, (p - 1) / 2, p);
        if (!jacobian || mod != jacobian)
        {
            return false;
        }
    }
    return true;
}

int main()
{
   ll T,N;
   cin >> T;
   while(T--)
   {
        cin >> N;
        if(Solovoy(N,5))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
   }
}
