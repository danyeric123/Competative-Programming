#include <iostream>
#include <limits.h>
using namespace std;
int maxWeight(int wt[], int color[],int W,int N,int M)
{
	bool dp[M][W+1];
	for(int i =0;i<M;i++)
	{
		for(int j = 0;j<W+1;j++)
			dp[i][j] = false;
	}
	int i = 0;
	while(color[i]==1)
	{
		dp[0][wt[i]]=true;
		i++;
	}
	int current_color = 2;
	for(int i = 1;i<N;i++)
	{
		int j = 0;
		while(j<=W)
		{
			if(color[i]==current_color)
			{
				if(wt[i]<=j)
					dp[current_color][j] = max(dp[current_color][j],dp[current_color-1][j-wt[i]]);
				j++;
			}
			else
			{
				current_color = color[i];
			}
		}
	}
	int maxm = 0;
	for(int i =0;i<=W;i++ )
	{
		if(dp[M-1][i])
		{
			maxm = i;
		}
	}
	return maxm==0?-1: W-maxm;
}
int main()
{
	int T;
	cin>>T;
	for(int t = 0;t<T;t++)
	{
		int N;
		int C;
		int W;
		cin>>N>>C>>W;
		int wt[N];
		int color[N];
		for(int i = 0;i<N;i++)
			cin>>wt[i];
		for(int i = 0;i<N;i++)
			cin>>color[i];
		cout<<maxWeight(wt,color,W,N,C)<<endl;
	}
	return 0;
}
