#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    long long val;
    long long i,j;
    char c;
    int n;
    int c1[27],c2[27],dis[17];
    int n1,n2,x;
    int res;


    int t;
    cin>>t;
    while(t--)
    {

    res = INT_MAX;
    cin>>n;
    cin>>s1;
    cin>>s2;
    int n = s1.length();
    val = 1<<n;

    for(i=0;i<val;i++)
    {
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        memset(dis,0,sizeof(dis));
        n1 = n2 = 0;
        for(j=0;j<n;j++)
        {
            if(i & (1<<j))
            {
                dis[j] = 1;
            }
        }
        for(int k=0;k<n;k++)
        {
            if(dis[k]==1)
            {
                c = s1[k];
                s1[k] = s2[k];
                s2[k] = c;
            }
        }
        for(int k=0;k<n;k++)
        {
            c1[s1[k]-'a']++;
            c2[s2[k]-'a']++;
        }
        for(int k=0;k<27;k++)
        {
            if(c1[k]!=0) n1++;
            if(c2[k]!=0) n2++;
        }
        for(int k=0;k<n;k++)
        {
            if(dis[k]==1)
            {
                c = s1[k];
                s1[k] = s2[k];
                s2[k] = c;
            }
        }
        x = max(n1,n2);
    //    cout<<x<<endl;
        res = min(res,x);
    }
        cout<<res<<endl;
}
}
