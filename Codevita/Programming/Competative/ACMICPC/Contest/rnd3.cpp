#include<bits/stdc++.h>
using namespace::std;
struct node
{
	int num;
	struct node *prev;
	struct node *next;
};


int fact(int n){
	int ans = 1;
	for (int i = 1; i <= n; i++) ans = ans*i;
	return ans;
}

int Right(char* str, int low, int high)
{
	int cc = 0, i;

	for (i = low + 1; i <= high; ++i)
		if (str[i] < str[low])
			++cc;
	return cc;
}

int findRank(char* str)
{
	int len = strlen(str);
	int mul = fact(len);
	int Rank = 1;
	int countRight;
	int i;
	for (i = 0; i < len; ++i){
		mul /= len - i;
		countRight = Right(str, i, len - 1);
		Rank += countRight * mul;
	}
	return Rank;
}


int doorstoCross(struct node *passKey)
{
	if (passKey == NULL)
		return NULL;
	struct node *temp = passKey;
	int len = 0, k = 0;
	char key[50] = { '\0' };
	while (temp){
		key[k++] = temp->num + '0';
		temp = temp->next;

	}
	key[k] = '\0';
	if (k == 0) return NULL;
	puts(key);

	return fact(k) - findRank(key) + 1;

}

int main(){
      //cout << findRank("875");
      cout << INT_MAX << endl << fact(12) ;
}
