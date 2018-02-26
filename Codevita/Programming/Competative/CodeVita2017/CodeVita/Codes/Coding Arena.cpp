#include<bits/stdc++.h>
using namespace::std;
string S;
int Count[300];
int Rep=0,Add=0,Del=0;

int Solve(){
    int A=0,B=0,C=0;
    for(int i=1;i<=26;i++){
        if(Count[i]){
            if(Count[i]>i) A+=abs(Count[i]-i);
            if(Count[i]<i) B+=abs(Count[i]-i);
        }
    }
    Rep = min(A,B); A -= Rep;  B -= Rep;
    if(A) Del=A;    if(B) Add=B;
   // cout << Rep << " " << Add << " " << Del << endl;
}
int main()
{
    int T=1;
    cin >> T;
    while(T--)
    {
        Rep=Add=Del=0;
        memset(Count,0,sizeof(Count));
        cin >> S;
        int sz = (int)S.size();
        for(int i=0;i<sz;i++){
            Count[S[i]-'a'+1]++;
        }
        Solve();
        int Res = Add*2 + Rep + Del*3;
        printf("%d",Res);
        if(T)
            printf("\n");
    }
	return 0;
}


