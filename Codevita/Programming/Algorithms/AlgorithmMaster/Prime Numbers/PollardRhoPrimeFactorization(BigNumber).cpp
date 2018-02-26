#include<bits/stdc++.h>
using namespace::std;

#define ll long long 

ll pollardRho(ll n) {
  if(n%2==0)
    return 2 ;
  srand (time(NULL)) ; 
  ll x, y , g=1 , a;
  x = rand() % n + 1 ;
  y = x ;
  a = rand() % n + 1 ;
  while(g==1) {
    x = ((x*x) + a)%n ;  
    y = ((y*y) + a)%n ;
    y = ((y*y) + a)%n ;  
    g = gcd(abs(x - y), n) ;
  }
  return g ;
}

int main(){
	int n;
	while(1)
	{
		cin >> n;
		cout << pollardRho(n);
	}
}