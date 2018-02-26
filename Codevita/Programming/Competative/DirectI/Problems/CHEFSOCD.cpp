#include <bits/stdc++.h>
using namespace::std;

int findImperfectCake(int N, int M, int numBoxesCompared[100],int boxesLeft[100][1000], int boxesRight[100][1000], char compRes[100])
{
    unordered_map<int,int> has[N+1];
    for(int i=0;i<M;i++){
        for(int j=0;j<numBoxesCompared[i];j++){
            has[i][boxesLeft[i][j]]++;
            has[i][boxesRight[i][j]]--;
        }
    }
    vector<int> answers;
    for(int imperfectcake=1;imperfectcake<=N;imperfectcake++){
        bool ok = true;
        for(int i=0;i<M;i++){
            if(has[i][imperfectcake] > 0){
                if(compRes[i] == '<' || compRes[i] == '=') ok = false;
            }
            else if(has[i][imperfectcake] < 0){
                if(compRes[i] == '>' || compRes[i] == '=') ok = false;
            }
        }
        if(ok) answers.push_back(imperfectcake);
    }
    if(answers.size() != 1)
        return 0;
	return answers[0];
}

int main() {
    int T, N, M;
    int numBoxesCompared[100];
    int boxesLeft[100][1000], boxesRight[100][1000];
    char compRes[100];
    int i, j;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++) {
        scanf("%d %d",&N,&M);
        for(i=0;i<M;i++) {
            scanf("%d",&numBoxesCompared[i]);
            for(j=0;j<numBoxesCompared[i];j++) {
                scanf("%d",&boxesLeft[i][j]);
            }
            for(j=0;j<numBoxesCompared[i];j++) {
                scanf("%d",&boxesRight[i][j]);
            }
            scanf("%s",&compRes[i]);
        }
        printf("#CASE : %d :%d\n",tt,findImperfectCake(N,M,numBoxesCompared,
                    boxesLeft,boxesRight,compRes));
    }
    return 0;
}

