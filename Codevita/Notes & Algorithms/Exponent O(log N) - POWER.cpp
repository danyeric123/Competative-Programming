#include<cstdio>

ll POWER(ll base,ll exp)
{
   ll Ans=1;
   while(exp>0)
   {
      if(exp%2==1)
      {
         Ans = (Ans*base);
      }
      exp = exp >> 1;
      base = (base*base);
   }

   return Ans;
}


int main()
{

     printf("%d",POWER(5,3));

     return 0;
}


