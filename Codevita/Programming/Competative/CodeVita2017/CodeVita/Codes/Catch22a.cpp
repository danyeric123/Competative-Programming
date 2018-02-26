#include<stdio.h>
int main()
{
 int N,F,B,T,FD,BD,d;
 scanf("%d",&N);
 while(N>0)
 {
  scanf("%d %d %d %d %d",&F,&B,&T,&FD,&BD);
  if(F==B && F<FD && B<BD)
   printf("NO Ditch\n");
  else
  {
   d=0;
   while(FD>0 && BD>0)
   {
    d+=F;
    FD-=F;
    BD+=F;
    if(FD>0)
    {
    d+=B;
    FD+=B;
    BD-=B;
    }
   }
   if(FD<=0)
   {
    d+=FD;
    printf("%d F\n",d*T);
   }
   else if(BD<=0)
   {
    d+=BD;
    printf("%d B\n",d*T);
   }
  }
  N--;
 }
 return 0;
}
