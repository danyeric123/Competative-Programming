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

char Board[20][20];
string Brd,Move;

void ProcessBoard()
{
    int k=0;
    int i=8,j=1;
    while(k<(int)Brd.size())
    {
            if(Brd[k]=='/')
            {
                while(j<=8)
                {
                    Board[i][j]='.';
                    j++;
                }
                i--;
                j=1;
                k++;
            }
            else if(Brd[k]>='0' && Brd[k]<='8')
            {
                int skip = Brd[k]-'0';
                for(int p=1;p<=skip;p++)
                {
                    Board[i][j]='.';
                    j++;
                }
                k++;
            }
            else
            {
                Board[i][j]=Brd[k];
                k++;
                j++;
            }
    }
}

vector<string> b1,b2;

void Process(int x,int y,char mv,int cnt)
{
    int i,j;
    string sou = char(y+'a'-1)+to_string(x);
    i=x+1; j=y-1;

    while(i<=8 && j>=1)
    {
        if(mv=='w' && Board[i][j]>='a' && Board[i][j]<='z'){
            Board[i][j]=char(cnt+'0');
            break;
        }
        if(mv=='b' && Board[i][j]>='A' && Board[i][j]<='Z'){
            Board[i][j]=char(cnt+'0');
            break;
        }
        if(mv=='w' && Board[i][j]>='A' && Board[i][j]<='Z')
            break;
        if(mv=='b' && Board[i][j]>='a' && Board[i][j]<='z')
            break;
        if(Board[i][j]!='.')
            break;
        Board[i][j]=char(cnt+'0');
        i++;
        j--;

    }

    i=x+1; j=y+1;
    while(i<=8 && j<=8)
    {
         if(mv=='w' && Board[i][j]>='a' && Board[i][j]<='z'){
            Board[i][j]=char(cnt+'0');
            break;
        }
        if(mv=='b' && Board[i][j]>='A' && Board[i][j]<='Z'){
            Board[i][j]=char(cnt+'0');
            break;
        }
        if(mv=='w' && Board[i][j]>='A' && Board[i][j]<='Z')
            break;
        if(mv=='b' && Board[i][j]>='a' && Board[i][j]<='z')
            break;
        if(Board[i][j]!='.')
            break;
        Board[i][j]=char(cnt+'0');
        i++;
        j++;
    }

    i=x-1; j=y-1;
    while(i>=1 && j>=1)
    {
         if(mv=='w' && Board[i][j]>='a' && Board[i][j]<='z'){
            Board[i][j]=char(cnt+'0');
            break;
        }
        if(mv=='b' && Board[i][j]>='A' && Board[i][j]<='Z'){
            Board[i][j]=char(cnt+'0');
            break;
        }
        if(mv=='w' && Board[i][j]>='A' && Board[i][j]<='Z')
            break;
        if(mv=='b' && Board[i][j]>='a' && Board[i][j]<='z')
            break;
        if(Board[i][j]!='.')
            break;
        Board[i][j]=char(cnt+'0');
        i--;
        j--;

    }

    i=x-1; j=y+1;
    while(i>=1 && j<=8)
    {
         if(mv=='w' && Board[i][j]>='a' && Board[i][j]<='z'){
            Board[i][j]=char(cnt+'0');
            break;
        }
        if(mv=='b' && Board[i][j]>='A' && Board[i][j]<='Z'){
            Board[i][j]=char(cnt+'0');
            break;
        }
        if(mv=='w' && Board[i][j]>='A' && Board[i][j]<='Z')
            break;
        if(mv=='b' && Board[i][j]>='a' && Board[i][j]<='z')
            break;
        if(Board[i][j]!='.')
            break;
        Board[i][j]=char(cnt+'0');
        i--;
        j++;
    }

}

void Proceed(int x,int y,int cnt)
{
    string sou = char(y+'a'-1)+to_string(x);
    for(int i=8;i>=1;i--)
    {
        for(int j=1;j<=8;j++)
        {
            {
                if(Board[i][j]==char(cnt+'0') && (x-i)!=0 && abs(y-j)/abs(x-i)==1){
                    string res = sou + char(j+'a'-1)+to_string(i);
                    if(cnt==0){
                        b1.push_back(res);
                    }
                    else{
                        b2.push_back(res);
                    }
                }
            }
        }
    }

}
int main()
{

    cin >> Brd >> Move;
    char mv = Move[0];

    ProcessBoard();

    cout << endl << endl;
    for(int i=8;i>=1;i--)
    {
       for(int j=1;j<=8;j++)
       {
          printf("%c",Board[i][j]);
       }
       printf("\n");
    }


    int Cnt=0;
    for(int i=8;i>=1;i--)
    {
       for(int j=1;j<=8;j++)
       {
           if(mv=='w' && Board[i][j]=='B'){
                Process(i,j,mv,Cnt);
                Cnt++;
           }
           if(mv=='b' && Board[i][j]=='b'){
                Process(i,j,mv,Cnt);
                Cnt++;
           }
       }
    }

    cout << endl << endl;
     for(int i=8;i>=1;i--)
    {
       for(int j=1;j<=8;j++)
       {
          printf("%c",Board[i][j]);
       }
       printf("\n");
    }
    cout << endl << endl;

    b1.clear();
    b2.clear();
    int cnt=0;
    for(int i=8;i>=1;i--)
    {
       for(int j=1;j<=8;j++)
       {
         if(mv=='w' && Board[i][j]=='B'){
            Proceed(i,j,cnt);
            cnt++;
         }
         if(mv=='b' && Board[i][j]=='b'){
            Proceed(i,j,cnt);
            cnt++;
         }
       }
    }

    if((int)b1.size()==0 || (int)b2.size()==0)
    {
        printf("[");
        for(int i=0;i<(int)b1.size();i++){
            cout << b1[i];
            if(i!=(int)b1.size()-1)
                cout << ",";
        }
        for(int j=0;j<(int)b2.size();j++)
        {
            cout << b2[j];
            if(j!=(int)b2.size()-1)
                cout << ",";
        }
        printf("]");
    }
    else {
        int ok = 1;
        if(b1[0][3]>b2[0][3]){
               ok = 1;
        }
        else if(b1[0][3]<b2[0][3]){
            ok = -1;
        }
        else if(b1[0][2]<b2[0][2]){
            ok = 1;
        }
        else
            ok = -1;

        if(ok==1){
              printf("[");
            for(int i=0;i<(int)b1.size();i++){
                cout << b1[i];
                if(i!=(int)b1.size()-1)
                    cout << ",";
            }
            for(int j=0;j<(int)b2.size();j++)
            {
                cout << b2[j];
                if(j!=(int)b2.size()-1)
                    cout << ",";
            }
            printf("]");
        }
        else{
             printf("[");
            for(int i=0;i<(int)b2.size();i++){
                cout << b2[i];
                if(i!=(int)b2.size()-1)
                    cout << ",";
            }
            for(int j=0;j<(int)b1.size();j++)
            {
                cout << b1[j];
                if(j!=(int)b1.size()-1)

                    cout << ",";
            }
            printf("]");
        }
    }

    return 0;
}

