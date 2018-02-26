#include<stdio.h>
int main()
{
    double M,T,R;
    double A,I,RM;
    scanf("%lf",&M);
    scanf("%lf",&T);
    scanf("%lf",&R);
    RM=M;
    T--;
    while(T>0)
    {
        A=double(RM)/(1+(double)R/(double)1200);
        I=RM-A;
        RM+=M-I;
        T--;
    }
    printf("%d",int(RM+0.5));
    return 0;
}
