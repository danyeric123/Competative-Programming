#include<bits/stdc++.h>
using namespace std;
#define N 100
#define sz(a) (int)a.size()
double adj[N][N];
double inv[N][N];
double Arr[N][N];

void getCofactor(double A[N][N], double temp[N][N], int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

double determinant(double A[N][N], int n)
{
    double D = 0.00;
    if (n == 1)
        return A[0][0];
    double temp[N][N];
    int sign = 1;
    for (int f = 0; f < n; f++)
    {
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }

    return D;
}

void adjoint(double A[N][N],double adj[N][N],int n)
{
    if (N == 1)
    {
        adj[0][0] = 1;
        return;
    }

    int sign = 1;
    double temp[N][N];

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            getCofactor(A, temp, i, j, n);
            sign = ((i+j)%2==0)? 1: -1;
            adj[j][i] = (sign)*(determinant(temp, n-1));
        }
    }
}


bool inverse(double A[N][N], double inverse[N][N],int n)
{
    double det = determinant(A, n);
    if (det == 0)
    {
        cout << "Invalid Input";
        return false;
    }

    adjoint(A, adj,n);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            inverse[i][j] = adj[i][j]/float(det);

    return true;
}


void display(double A[N][N],int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> Arr[i][j];
		}
	}

	adjoint(Arr, adj,n);
	inverse(Arr, inv,n);
    //    display(inv,n);
	/*
    cout << "Input matrix is :\n";
    display(Arr,n);

    cout << "\nThe Adjoint is :\n";

    display(adj,n);

    cout << "\nThe Inverse is :\n";

	*/
    string s;
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			int k = round(inv[i][j]);
			s += char(int('a')+k-1);
		}
	}
	int p=sz(s);
	for(int i=sz(s)-1;i>=1;i--){
		if(s[i]!=s[i-1]){
			p = i+1;
			break;
		}
	}
	int count = sz(s)-p;
	//cout << p << " " << sz(s) << " " << count << endl;
	string res = s.substr(0,p);
	for(int i=0;i<=count;i++){
		cout << res << " ";
		res += s[sz(s)-1];
	}
    return 0;
}
