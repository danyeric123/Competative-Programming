#include <bits/stdc++.h>
using namespace::std;
static unsigned long int nextr = 1;
static unsigned long int itr = 0;

int Rand() {
    nextr = (nextr * 1103515245LL + 12345LL)%INT_MAX;
    itr++;
    if (itr % 2 == 0){
        return (unsigned int)(nextr)%250;
    }
    return (unsigned int)(nextr)%INT_MAX;
}

void sRand(unsigned int seed) {
    nextr = seed;
    itr = 0;
}

int findTriplets1(int *A, int len) {
	int res = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			if (A[j] % A[i] != 0) continue;
			for (int k = j+1; k < len; k++) {
				if (A[k] % A[j] == 0)
					res++;
			}
		}
	}
	return res;
}
int findTriplets2(int *A, int len) {
	int res = 0;
	for (int j = 0; j<len; j++) {
		int cntA = 0, cntB = 0;
		for (int i = j - 1; i >= 0; i--) {
			if (A[j] % A[i] == 0) cntA++;
		}
		for (int k = j + 1; k<len; k++) {
			if (A[k] % A[j] == 0) cntB++;
		}
		res += cntA*cntB;
	}
	return res;
}
#include<math.h>
const int NMAX = 1e7 + 25;
int countL[NMAX];
int countR[NMAX];
int countA[NMAX];
int findTriplets(int *A, int len) {
	int k,res = 0;
	for (int i = 0; i < NMAX; i++){
		countL[i] = 0;
		countR[i] = 0;
		countA[i] = 0;
	}
	for (int i = 0; i < len; i++){
		k = sqrt(1.0*A[i]);
		for (int j = 1; j <= k; j++){
			if (A[i] % j == 0){
				if (j == (A[i] / j)){
					countL[i] += countA[j];
				}
				else{
					countL[i] += countA[j];
					countL[i] += countA[A[i] / j];
				}
			}
		}
		countA[A[i]] += 1;
	}
	for (int i = 0; i<NMAX; i++)
		countA[i] = 0;
	for (int i = len - 1; i >= 0; i--){
		k = sqrt(1.0*A[i]);
		for (int j = 1; j <= k; j++){
			if (A[i] % j == 0){
				if (j == (A[i] / j)){
					countA[j]++;
				}
				else{
					countA[j]++;
					countA[A[i] / j]++;
				}
			}
		}
		countR[i] = countA[A[i]] - 1;
	}
	for (int i = 0; i < len; i++){
		res += countL[i] * countR[i];
	}
	return res;
}
int main(){
    int Max = -1;
    int A[100005];
    int len = 100000;
    sRand(15351);
    for (int i = 0; i < len; i++) {
        int k = Rand();
        //cout << k << endl;
        Max = max(k,Max);
    }
    cout << Max << endl;

}
