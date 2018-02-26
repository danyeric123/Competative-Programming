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
#define ff first
#define ss second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define sz(a) (int)a.size()

string Brd;
map<string,char> Board;

void ConvertFEN()
{
    int k=0,i=1,j=1,skip;
    string sq;
    while(k<sz(Brd)){
        if(Brd[k]=='/'){
                while(j<=8) {
                    sq = char('a'+j-1) + to_string(9-i);
                    Board[sq]='-';
                    j++;
                }
                i++;  j=1;  k++;
        }else if(Brd[k]>='0' && Brd[k]<='8') {
                skip = Brd[k]-'0';
                for(int p=1;p<=skip;p++){
                    sq = char('a'+j-1) + to_string(9-i);
                    Board[sq]='-';
                    j++;
            }
            k++;
        }else{
            sq = char('a'+j-1) + to_string(9-i);
            Board[sq]=Brd[k];
            k++;
            j++;
        }
    }
    return;
}

void BoardCout()
{
    string sq;
    for(int c=8;c>=1;c--){
        for(char r='a';r<='h';r++){
            sq = r + to_string(c);
            cout << Board[sq] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string sq;
    cin >> Brd;
    ConvertFEN();
    BoardCout();
    while(1)
    {
        cin >> sq;
        cout << Board[sq] << endl;
    }
    return 0;
}

