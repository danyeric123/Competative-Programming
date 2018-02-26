#include<bits/stdc++.h>
using namespace::std;

void rotateArray(int arr[][3], int len, char *seq)
{
	if (len == 0 || arr == NULL || seq==NULL)
		return;
	//Manipulate input array for output
	int L = 0, R = 0;
	for (int i = 0; seq[i]; i++){
		if (seq[i] == 'l' || seq[i] == 'L') L++;
		if (seq[i] == 'r' || seq[i] == 'R') R++;
	}
	if (L == R)
		return;
	int times = abs(L-R);
	if(L>R) times = times%4;
      else times = (times+2)%4;
     // printf("%d %d %d\n",L,R,times);
      for(int i=0;i<times;i++){
            for (int x = 0; x < len / 2; x++)
            {
                  for (int y = x; y < len-x-1; y++)
                  {
                        int temp = arr[x][y];
                        arr[x][y] = arr[y][len-1-x];
                        arr[y][len-1-x] = arr[len-1-x][len-1-y];
                        arr[len-1-x][len-1-y] = arr[len-1-y][x];
                        arr[len-1-y][x] = temp;
                  }
            }
      }
      return;
}


int main()
{
      int arr[3][3] = {
                  {1,	2,	3},
                  {4,	5,	6},
                  {7,	8	,9}
            };

      for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                  printf("%d ",arr[i][j]);
            }
            printf("\n");
      }
      rotateArray(arr,3,"LLRRR");
      printf("\n\n");
      for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                  printf("%d ",arr[i][j]);
            }
            printf("\n");
      }
	return 0;
}

