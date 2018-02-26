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

std::string to_string(int i){
    std::stringstream ss;
    ss << i;
    return ss.str();
}

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

bool isWhite(char ch){
    return ch=='P'|| ch=='N' || ch=='B' || ch=='R' || ch=='Q' || ch=='K';
}

bool isBlack(char ch){
    return ch=='p'|| ch=='n' || ch=='b' || ch=='r' || ch=='q' || ch=='k';
}

bool isEmpty(char ch){
    return ch=='.';
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
void solve(string Move){
    vector<string> Moves;
    if(Move=="b"){
        for(int i=2;i<=7;i++){
            //j==1
            if(Board[i][1]=='p' && isEmpty(Board[i+1][1])){
                Moves.pb(xy[MP(i,1)]+xy[MP(i+1,1)]);
            }
            if(Board[i][1]=='p' && isWhite(Board[i+1][2])){
                Moves.pb(xy[MP(i,1)]+xy[MP(i+1,2)]);
            }
            if(i==2 && Board[i][1]=='p' && isEmpty(Board[i+1][1]) && isEmpty(Board[i+2][1])){
                Moves.pb(xy[MP(i,1)]+xy[MP(i+2,1)]);
            }



            for(int j=2;j<=7;j++){
                if(Board[i][j]=='p'){
                    if(isWhite(Board[i+1][j-1])){
                        Moves.pb(xy[MP(i,j)]+xy[MP(i+1,j-1)]);
                    }

                    if(isEmpty(Board[i+1][j])){
                         Moves.pb(xy[MP(i,j)]+xy[MP(i+1,j)]);
                    }
                    if(isWhite(Board[i+1][j+1])){
                        Moves.pb(xy[MP(i,j)]+xy[MP(i+1,j+1)]);
                    }
                    if(i==2 && Board[i][j]=='p' && isEmpty(Board[i+1][j]) && isEmpty(Board[i+2][j])){
                        Moves.pb(xy[MP(i,j)]+xy[MP(i+2,j)]);
                    }

                }
            }

            //j==8
            if(Board[i][8]=='p' && isWhite(Board[i+1][7])){
                Moves.pb(xy[MP(i,8)]+xy[MP(i+1,7)]);
            }
            if(Board[i][8]=='p' && isEmpty(Board[i+1][8])){
                Moves.pb(xy[MP(i,8)]+xy[MP(i+1,8)]);
            }
            if(i==2 && Board[i][8]=='p' && isEmpty(Board[i+1][8]) && isEmpty(Board[i+2][8])){
                Moves.pb(xy[MP(i,8)]+xy[MP(i+2,8)]);
            }


        }
    }
    else if(Move == "w"){
        for(int i=2;i<=7;i++){
            //j==1

            if(i==7 && Board[i][1]=='P' && isEmpty(Board[i-1][1]) && isEmpty(Board[i-2][1])){
                Moves.pb(xy[MP(i,1)]+xy[MP(i-2,1)]);
            }
            if(Board[i][1]=='P' && isEmpty(Board[i-1][1])){
                Moves.pb(xy[MP(i,1)]+xy[MP(i-1,1)]);
            }


            if(Board[i][1]=='P' && isBlack(Board[i-1][2])){
                Moves.pb(xy[MP(i,1)]+xy[MP(i-1,2)]);
            }

            for(int j=2;j<=7;j++){
                if(Board[i][j]=='P'){
                    if(i==7 && Board[i][j]=='P' && isEmpty(Board[i-1][j]) && isEmpty(Board[i-2][j])){
                        Moves.pb(xy[MP(i,j)]+xy[MP(i-2,j)]);
                    }
                    if(isBlack(Board[i-1][j-1])){
                        Moves.pb(xy[MP(i,j)]+xy[MP(i-1,j-1)]);
                    }
                    if(isEmpty(Board[i-1][j])){
                         Moves.pb(xy[MP(i,j)]+xy[MP(i-1,j)]);
                    }


                    if(isBlack(Board[i-1][j+1])){
                        Moves.pb(xy[MP(i,j)]+xy[MP(i-1,j+1)]);
                    }
                }
            }

            //j==8
            if(i==7 && Board[i][8]=='P' && isEmpty(Board[i-1][8]) && isEmpty(Board[i-2][8])){
                Moves.pb(xy[MP(i,8)]+xy[MP(i-2,8)]);
            }
            if(Board[i][8]=='P' && isBlack(Board[i-1][7])){
                Moves.pb(xy[MP(i,8)]+xy[MP(i-1,7)]);
            }
            if(Board[i][8]=='P' && isEmpty(Board[i-1][8])){
                Moves.pb(xy[MP(i,8)]+xy[MP(i-1,8)]);
            }


        }
    }
    else{
        assert(false==true);
    }
    cout << "[";
    for(int i=0;i<(int)Moves.size();i++){
        cout << Moves[i];
        if(i!=(int)Moves.size()-1) cout << ", ";
    }
    cout << "]";

}
int main()
{
    Notation();
    //while(1){
    cin >> Brd >> Move;
    ConvertFEN();
    //8/1k6/8/P7/K7/8/8/8 w
       // cout << "---------" << endl;
    //PrintBoard();

        //cout << "---------" << endl;
    solve(Move);

    return 0;
}

