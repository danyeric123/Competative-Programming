#include <iostream>
using namespace std;
bool recursive(char grid[128][128], int m, int n, string word,bool visited[128][128],int x,int y,int index)
{
	visited[x][y] = true;
	if(index==word.length())
		return true;
	static int arr1[8] = {-1,-1,-1,0,0,1,1,1};
	static int arr2[8] = {-1,0,1,-1,1,-1,0,1};
	int nx;
	int ny;
	for(int i = 0;i<8;i++)
	{
		nx = x+arr1[i];
		ny = y+arr2[i];
		if(nx>=0 && ny>=0 && nx<m  && ny<n && !visited[nx][ny] && grid[nx][ny] == word.at(index))
		{
			if(recursive(grid,m,n,word,visited,nx,ny,index+1))
				return true;
		}
	}
	visited[x][y] = false;
	return false;
}
bool findWordInAGrid(char grid[128][128], int m, int n, char arr[])
{
	string word = string(arr);
	bool visited[128][128] = {0};
	for(int i = 0;i<m;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(grid[i][j]==word.at(0))
			{
				if(recursive(grid,m,n,word,visited,i,j,1))
					return true;
			}
		}
	}
	return false;
}
int main()
{
	char grid[128][128] = {{'a','b','c'},{'d','e','f'},{'g','h','i'}};
	char word[] = "abc";
	cout<<findWordInAGrid(grid,3,3,word)<<endl;
	return 0;
}
