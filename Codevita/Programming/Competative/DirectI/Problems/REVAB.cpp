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


void driver(string str){
    int i = 0;
    while(i < str.length()){
        if(str[i] == 'b'){
            break;
        }
        i++;
    }
    if(i == str.length())  {
        cout << "[0,0]";
        return;
    }
    int pre_count = 0;
    int pre_end = 0;
    int start = i;
    int end = i;
    int count = 0;
    for(; i < str.length(); i ++){
        if(str[i] == 'a'){
            end = i;
            count ++;
        }else{
            if(count > pre_count){
                pre_count = count;
                pre_end = end;
            }
            count = 0;
        }
    }
    if(count > pre_count){
        pre_end = end;
    }
    cout <<"["<<start <<"," << pre_end << "]" << endl;
}

int main(){
    int T;
    string str;
    cin >> T;
    while(T--){
        cin >> str;
        driver(str);
    }
    return 0;
}
