/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/


#include<bits/stdc++.h>
using namespace::std;


int * find_sequences(int *arr, int len){

	if (len == 1)
		return arr;

	else if (arr == NULL || len < 0)
		return NULL;

	else{
		int *newArr = (int *)malloc(sizeof(int) * 6), k = 0;
		int *diff = (int *)malloc(sizeof(int) * 10), j = 0;

		for (int l = 0; l < len - 1; l++){
			int dfrnc = arr[l + 1] - arr[l];
			diff[j] = dfrnc;
			j++;
		}
		for(int i=0;i<len;i++){
                  printf("%d ",diff[i]);
		}
		int i = 0;
		for (i = 0; i < j; i++){
			if (diff[i] == diff[i + 1]){
				newArr[k] = i;
				i = i + 1;

				while (diff[i] == diff[i + 1]){
					i = i + 1;
				}
				k++;
				newArr[k] = i + 1;
				break;
			}
		}
		cout << endl << "Ret : " ;
		for(int i=0;i<6;i++){
                  cout << newArr[i] << " ";
		}
		int l;
		for (l = i + 1; l < len - 2; l++){
			if (diff[l] == diff[l + 1]){
				k++;
				newArr[k] = l;
				l++;
				while (l < len - 2 && diff[l] == diff[l + 1]){
					l = l+1;
				}
				k++;
				newArr[k] = l + 1;
				break;
			}
		}
            cout << endl << "Ret : " ;
		for(int i=0;i<6;i++){
                  cout << newArr[i] << " ";
		}
		if (l == len - 1){
			for (int m = 0; m < len; m++){
				if ((diff[m] * 2) == diff[m + 1]){
					k++;
					newArr[k] = m;
					m++;
					while(diff[m] == diff[m + 1]){
						m++;
					}
					k++;
					newArr[k] = m;
					break;
				}
			}
		}
		else{
			for (int n = l - 1; n < len - 1; n++){
				if ((diff[n] * 2) == diff[n + 1]){
					k++;
					newArr[k] = n;
					n++;
					while(diff[n] == diff[n + 1]){
						n++;
					}
					k++;
					newArr[k] = n + 1;
					break;
				}
			}
		}
				cout << endl << "Ret : " ;
		for(int i=0;i<6;i++){
                  cout << newArr[i] << " ";
		}
		return newArr;
	}
}


int main(){
      int input[10] = { 10, -10, -30, 10, 20, 40, 10, -20 };
	int ans[6] = { 0, 2, 5, 7, 3, 5 };
	int len = 8;
	int *res = find_sequences(input, len);
	for (int i = 0; i < 6; i++){
		printf("%d ", res[i]);
	}

}
