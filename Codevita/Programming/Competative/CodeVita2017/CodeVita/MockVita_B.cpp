#include<stdio.h>
int main()
{
    int i,mon=6;
    float sum=0,val=25.0,in=4.0;
    for(i=0;i<mon;i++)
    {
        sum+=val;
        sum += (sum*in)/(100*12);
        printf("%f\n",sum);
    }
    printf("%f",sum);
}
