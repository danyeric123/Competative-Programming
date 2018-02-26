#include<bits/stdc++.h>
using namespace::std;

vector<int> CharIdx[27];
vector< pair<int,int> > CharPair;

void Process(int p)
{
    int F=0,S=0;
    for(int i=1;i<CharIdx[p].size();i++){
        if(i==1){
            if(CharIdx[p][i]-CharIdx[p][i-1] == 1)
                S++;
            else{
                F++;
            }
        }
        else{
            if(CharIdx[p][i]-CharIdx[p][i-1] == 1){
                   S++;
                   F+= (i-1);
            }
            else{
                F += i;
            }
        }
    }
    CharPair.push_back(make_pair(F,S));
}

int main()
{
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        CharIdx[s[i]-'a'+1].push_back(i);
    }
    for(int i=1;i<=26;i++){
        cout << char('a'+i-1) ;
        for(int j=0;j<CharIdx[i].size();j++){
            cout << CharIdx[i][j] <<  " ";
        }
        cout << endl;
    }
    for(int i=0;i<=26;i++)
        Process(i);

    for(int i=1;i<=26;i++){
        cout << char('a'+i-1) << CharPair[i].first << " " << CharPair[i].second << endl;
    }

    return 0;
}
