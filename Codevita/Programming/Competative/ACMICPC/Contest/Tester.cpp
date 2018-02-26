#include<bits/stdc++.h>
using namespace::std;
string s="ABC";
char Table[1000][1000];
void Generate(int N){
      for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                  Table[i][j] = s[rand()%3];
            }
      }
}
void PrintTable(int N){
      for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                  printf("%c ",Table[i][j]);
            }
            printf("\n");
      }
}
int main(){
      int N = 10;
      srand(NULL);
      Generate(N);
      printf("Generated\n");
      PrintTable(N);

      ifstream infile;
      infile.open("input.txt");

      int K;
      int x1,y1,x2,y2;
      infile >> K;

      for(int i=1;i<=K;i++){
            infile >> x1 >> y1 >> x2 >> y2;
            if(Table[x1][y1] == Table[x2][y2])
                  continue;
            if(Table[x1][y1]=='A'){
                  if(Table[x2][y2]=='B'){
                        Table[x1][y1] = 'C';
                        Table[x2][y2] = 'C';
                  }
                  else{
                        Table[x1][y1] = 'B';
                        Table[x2][y2] = 'B';
                  }
            }
            else if(Table[x1][y1]=='B'){
                  if(Table[x2][y2]=='A'){
                        Table[x1][y1] = 'C';
                        Table[x2][y2] = 'C';
                  }
                  else{
                        Table[x1][y1] = 'A';
                        Table[x2][y2] = 'A';
                  }
            }
            else if(Table[x1][y1]=='C'){
                  if(Table[x2][y2]=='B'){
                        Table[x1][y1] = 'A';
                        Table[x2][y2] = 'A';
                  }
                  else{
                        Table[x1][y1] = 'B';
                        Table[x2][y2] = 'B';
                  }
            }
      }


      printf("\n\n\nAfter Execution\n\n");
      PrintTable(N);
}
