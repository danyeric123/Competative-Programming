#include<cstdio>

#define MOD 124

ll Power(ll Base,ll Exp)
{
   ll Ans=1LL;
   while(exp>0)
   {
      if(Exp&1LL)
         Ans = (Ans*Base);
      Exp = Exp >> 1LL;
      Base = (Base*Base);
   }
   return Ans;
}

ll PowerMod(ll Base,ll Exp,ll Mod){
    ll Ans = 1LL;
    Base = Base%Mod;
    while(Exp>0){
        if(Exp&1LL)
            Ans = (Ans*Base)%Mod;
        Exp = Exp >> 1LL;
        Base = (Base*Base)%Mod;
    }
    return Ans;
}


int main()
{

     printf("%d",POWER(10,50));

     return 0;
}


