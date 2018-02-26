#include<iostream>
#include<algorithm>
using namespace std;

// Returns minimum number of platforms reqquired
int findPlatform(int arr[], int dep[], int n){
   sort(arr, arr+n);
   sort(dep, dep+n);
   int plat_needed = 1, result = 1;
   int i = 1, j = 0;
   while (i < n && j < n){
      if (arr[i] < dep[j]){
          plat_needed++;
          i++;
          if (plat_needed > result)
              result = plat_needed;
      }
      else{
          plat_needed--;
          j++;
      }
   }

   return result;
}

int arr[100],dep[100];
int main()
{
    int T;
    cin >> T;
    while(T--){
            int n;
            cin >> n;
            for(int i=0;i<n;i++)
                cin >> arr[i] >> dep[i];

            cout << findPlatform(arr, dep, n) << endl;
    }

    return 0;
}
