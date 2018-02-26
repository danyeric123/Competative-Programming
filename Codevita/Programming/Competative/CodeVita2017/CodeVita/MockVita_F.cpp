#include<bits/stdc++.h>
using namespace::std;
int Dp[1005];

int Calc(int i){
    if(i<0)
        return 5000;
    if(Dp[i]!=-1)
        return Dp[i];

    return Dp[i]=min(1+Calc(i-1),min(1+Calc(i-5),min(1+Calc(i-7),1+Calc(i-10))));
}

void Pre(){
    Dp[1]=1;
    Dp[5]=1;
    Dp[7]=1;
    Dp[10]=1;
    for(int i=2;i<=1000;i++){
        Calc(i);
       // cout << Dp[i] << endl;
    }
}
int main()
{
    int T,N,Ans;
    memset(Dp,-1,sizeof(Dp));
    Pre();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        printf("%d",Dp[N]);
        if(T)
            printf("\n");
    }
	return 0;
}
