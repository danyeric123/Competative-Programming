#include<bits/stdc++.h>
using namespace::std;

int main()
{
    int T=1,N;
    cin >> N;

    while(T--)
    {
        cin >> N;
        if(N==1 || N%4==0){
            puts("No");
        }
        else{
            puts("Yes");
        }
    }

	return 0;
}

