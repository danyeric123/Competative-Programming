#include<bits/stdc++.h>
using namespace std;
const int MAX =  1e7+25;
bool Prime[MAX+25];

void Sieve()
{
    int i,j,POS; Prime[0]=Prime[1]=1;
    for(i=2;i<=sqrt(MAX);i++)
    {
        if(!Prime[i])
            for(j=2;(POS=j*i)<=MAX;j++)
                Prime[POS]=1;
    }
}

void SegmentSieve(int L,int R)
{

	int lim = sqrt(R);
	int i, j;
	for (i = 2; i <= lim; i++)
    {
		if (!Prime[i])
        {
			for (j = L - L%i; j <= R; j += i)
				if (j>=L && !Prime[j] && j!=i)
					Prime[j] = 1;
		}
	}

}


int main()
{
    Sieve();
    /*
    int i,T,L,R;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&L,&R);

        if(R>200)
            SegmentSieve(L,R);

        for(i=L;i<=R;i++)
            if(!Prime[i])
               printf("%d\n",i);

        if(T) printf("\n");
    }
    */
    return 0;
}
