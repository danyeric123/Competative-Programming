#pragma warning(suppress: 4101)
#include<bits/stdc++.h>
using namespace::std;

#define ll  long long
#define ull unsigned ll
#define LD long double

#define MP make_pair
#define BS binary_search
#define GCD __gcd
#define pb push_back
#define pp pop_back
#define F first
#define S second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

ll Ans=0;
ll BF= 0;
void Forward(ll P,ll F,ll B,ll FD){
    BF = 1;

    while(P+F < FD){
        Ans = Ans+F;
        Ans = Ans+B;
        P = P+(F-B);
    }
    Ans = Ans + abs(FD-P);
}

void Backword(ll P,ll F,ll B,ll BD){
    BF = -1;
    while(P-B > BD){
        Ans = Ans+B;
        Ans = Ans+F;
        P = P-abs(B-F);
    }
    Ans = Ans + abs(P-BD);
}

int main()
{
    ll N;
    scanf("%lld",&N);

    ll F,B,T,FD,BD;
    while(N--){
        Ans = 0;
        BF = 0;
        scanf("%lld %lld %lld %lld %lld",&F,&B,&T,&FD,&BD);

        if(FD<=F){
            Ans = FD;
            BF = 1;
        }
        else if((F-B)==0){
            Ans = -1;
        }
        else if((F-B)>0){
            Ans = 0;
            Forward(0,F,B,FD);
        }
        else{
            Ans = F;
            Backword(F,F,B,-BD);
        }

        if(Ans == -1){
            printf("No Ditch");
        }
        else{
            ll Res = Ans*T;
            printf("%lld ",Res);
            if(BF==1)
                printf("F");
            else
                printf("B");

        }
        if(N)
            printf("\n");
    }
    return 0;
}
