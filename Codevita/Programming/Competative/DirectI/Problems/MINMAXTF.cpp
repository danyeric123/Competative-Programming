#include<bits/stdc++.h>
using namespace::std;

#define ll  long long
#define ull unsigned ll
#define LD long double

#define mp make_pair
#define bs binary_search
#define gcd __gcd
#define pb push_back
#define pp pop_back
#define ff first
#define ss second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
int a[100005];
int main(){
    int T;
    int n,m;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i=0;i<n;i++) cin >> a[i];

        int lo=0;
        int hi=1e9;
        int ans = -1;
        while(lo<=hi)
        {
            int mid=(lo+hi)/2;
            bool possible=true;
            int s=0,cnt=1;
            for(int i=0;i<n;i++){
                if(a[i]>mid){
                    possible=false;
                    break;
                }
                else if(s+a[i]<=mid) s+=a[i];
                else{
                    s=a[i];
                    cnt++;
                }
            }
            if(cnt<=m and possible==true){
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;
        }

        cout << ans << endl;
    }
    return 0;
}
