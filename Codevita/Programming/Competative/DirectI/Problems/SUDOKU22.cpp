#include<bits/stdc++.h>
using namespace::std;

#define ll  long long
#define ull unsigned ll
#define LD long double

#define mp make_pair
#define bs binary_search
#define gcd __gcd
#define pb push_back
#define pp pop_back
#define ff first
#define ss second

#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL

#define UNASSIGNED 0
#define N 4

bool Find(int grid[N][N], int &row, int &col);
bool isSafe(int grid[N][N], int row, int col, int num);
void printGrid(int grid[N][N]);
int cnt = 0;

vector<int> temp;
vector< vector<int> > solutions;
void generateSolutions(int grid[N][N]){
    int row, col;
    if (!Find(grid, row, col)){
        temp.clear();
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                temp.pb(grid[i][j]);
            }
        }
        solutions.pb(temp);
        return;
    }
    for (int num = 1; num <= 4; num++){
        if (isSafe(grid, row, col, num)){
            grid[row][col] = num;
            generateSolutions(grid);
            grid[row][col] = UNASSIGNED;
        }
    }
    return;
}
bool Find(int grid[N][N], int &row, int &col){
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool UsedInRow(int grid[N][N], int row, int num){
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInCol(int grid[N][N], int col, int num){
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}


bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num){
    for (int row = 0; row < 2; row++)
        for (int col = 0; col < 2; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}


bool isSafe(int grid[N][N], int row, int col, int num){
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row%2 , col - col%2, num);
}

void printGrid(int grid[N][N]){
    for (int row = 0; row < N; row++){
       for (int col = 0; col < N; col++)
             printf("%2d", grid[row][col]);
        printf("\n");
    }
}

int main(){
    int grid[N][N];
    memset(grid,0,sizeof(grid));
    generateSolutions(grid);
    int T;
    int x;
    cin >> T;
    while(T--){
        temp.clear();
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cin >> x;
                temp.pb(x);
            }
        }
        int res = INT_MAX;
        for(int i=0;i<solutions.size();i++){
            int var = 0;
            for(int j=0;j<16;j++){
                int ad = abs(temp[j]-solutions[i][j]);
                var += ad*ad;
            }
            res = min(res,var);
        }
        cout << res << endl;

    }
    return 0;
}
