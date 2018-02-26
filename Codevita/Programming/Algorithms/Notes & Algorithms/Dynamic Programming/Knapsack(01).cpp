#include<bits/stdc++.h>
using namespace::std;

int Dp[500][500];

int Call(){
    int &ret = Dp[20][20];

    return ret;
}

int main()
{
    cout << Call() << endl;
    Dp[20][20]=1;
    cout << Call() << endl;
}
