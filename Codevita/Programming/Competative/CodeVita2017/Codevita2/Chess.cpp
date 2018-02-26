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

char Board[20][20];
string Brd,Move;
map<string,pair<int,int> >ah;
map<pair<int,int>,string> xy;
void Notation()
{
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            string s = char('a'+j-1) + to_string(9-i);
            xy[MP(i,j)] = s;
            ah[s] = MP(i,j);
        }
    }
}

void ConvertFEN()
{
    int k=0,i=1,j=1,skip;
    while(k<sz(Brd)){
        if(Brd[k]=='/'){
                while(j<=8) {
                    Board[i][j]='.'; j++;
                }
                i++;  j=1;  k++;
        }else if(Brd[k]>='0' && Brd[k]<='8') {
                skip = Brd[k]-'0';
                for(int p=1;p<=skip;p++){
                    Board[i][j]='.'; j++;
            }
            k++;
        }else{
            Board[i][j]=Brd[k];
            k++; j++;
        }
    }
    return;
}

void PrintBoard()
{
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            printf("%c ",Board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Notation();
    cout << ah["a8"].ff << " " << ah["a8"].ss << endl;
    cout << ah["d4"].ff << " " << ah["d4"].ss << endl;
    while(1)
    {
        cin >> Brd;

        ConvertFEN();
        cout << Board[ah["g8"].ff][ah["g8"].ss]<< endl;
        PrintBoard();
    }
    return 0;
}

