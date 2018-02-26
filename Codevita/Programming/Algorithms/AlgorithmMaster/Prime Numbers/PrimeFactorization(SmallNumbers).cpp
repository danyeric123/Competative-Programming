#include<bits/stdc++.h>
using namespace::std;
const int MAX = 1e5;
typedef long long ll;
bool Prime[MAX+25];
int HPF[MAX+25]; //Highest Prime Factor
void sieve()
{
    int i,j;
    memset(Prime,1,sizeof(Prime));
    Prime[0]=Prime[1]=0;
    for(i=4;i<=MAX;i+=2) {Prime[i]=0; HPF[i] =2;}
    for(i=3;i<=sqrt(MAX);i+=2) {
        if(Prime[i]){
            HPF[i]=i;
            for(j=i*i;j<=MAX;j+=i){
                Prime[j]=0;
                if(!HPF[j])
                    HPF[j]=i;
            }
        }
    }
    for(int i=2;i<=MAX;i++) if(Prime[i]) HPF[i]=i;
}

auto ExpCal(ll N)
{
      vector< pair<int,int> > Fac;
      ll NN = N,Pow,prime;
      while(NN>1){
            Pow=0;
            prime=HPF[NN];
            while(!(NN%prime)){
                  NN=NN/prime;
                  Pow++;
            }
            Fac.push_back(make_pair(prime,Pow));
      }
      return Fac;
}

int main()
{
    sieve();

    auto Fac = ExpCal(740);
    for(auto it=Fac.begin();it!=Fac.end();it++){
      cout << it->first << " " << it->second << endl;
    }
    return 0;
}
