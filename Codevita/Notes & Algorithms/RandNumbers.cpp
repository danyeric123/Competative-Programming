/*
-----------------------------------------------------------------------------
Author : - PVSM Praveen Kumar -
							Random Numbers
-----------------------------------------------------------------------------
*/

#include<bits/stdc++.h>
using namespace::std;

auto MersenneTwister () {
    srand (time(NULL));
    mt19937 rng(rand());
    return rng;
}

auto rnd = MersenneTwister();

int main()
{
    int Tests = 15;
    int Arr_Size = 15 ;  //Change This.
    int Arr_Max = 20; //Change This.
    int Arr_Min = 1; //Change This.

    cout << Tests << endl;
    for(int T=0;T<Tests;T++)
    {
       int N = 1+rnd()%Arr_Size;
       Arr_Max = N;
       cout << N << endl;
       for(int i=0;i<N;i++)
       {
            cout << Arr_Min+rnd()%(Arr_Max-Arr_Min+1) << " ";
       }
       cout << endl;
    }

	return 0;
}



/*
-----------------------------------------------------------------------------
								The End!
-----------------------------------------------------------------------------
*/

