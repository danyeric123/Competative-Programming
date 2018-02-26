#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int t = 0;t<T;t++)
	{
		int N;
		int M;
		cin>>N>>M;
		int mat[3][N];
		for(int i= 0;i<3;i++)
		{
			for(int j = 0;j<N;j++)
				mat[i][j] = 0;
		}
		for(int i = 0;i<M;i++)
		{
			int start;
			int end;
			int row;
			cin>>row>>start>>end;
			row--;
			start--;
			end--;
			mat[row][start]++;
			mat[row][end]--;
		}
		for(int i = 0;i<3;i++)
		{
			int current = 0;
			for(int j = 0;j<N;j++)
			{
				int temp = mat[i][j];
				if(mat[i][j]> 0 || current>0)
				{
					mat[i][j] = 1;
				}
				current = current+temp;
			}

		}
		for(int i = 1;i<3;i++)
		{
			for(int j = 0;j<N;j++)
			{
				if(mat[i][j]>0)
				{
					mat[i][j]= mat[i][j]+mat[i-1][j];
				}
			}
		}

		int max_area = 0;
		for(int i = 0;i<3;i++)
		{
			int st = 0;
			while(st<N)
			{
				int len = 0;
				while(st<N && mat[i][st]>0)
				{
					st++;
					len++;
				}
				max_area = max(max_area,len);
				st++;
			}
			st = 0;
			while(st<N)
			{
				int len = 0;
				while(st<N && mat[i][st]>1)
				{
					st++;
					len++;
				}
				max_area = max(max_area,len*2);
				st++;
			}
			st = 0;
			while(st<N)
			{
				int len = 0;
				while(st<N && mat[i][st]>2)
				{
					st++;
					len++;
				}
				max_area = max(max_area,3*len);
				st++;
			}
		}
		cout<<max_area<<endl;
	}
}
