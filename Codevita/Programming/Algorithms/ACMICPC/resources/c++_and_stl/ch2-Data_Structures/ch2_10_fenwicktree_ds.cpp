#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
#define LSOne(S) (S & (-S))

// initialization: n + 1 zeroes, ignoring index 0, just using index [1..n]
void ft_create(vi &ft, int n) { ft.assign(n + 1, 0); }

int ft_rsq(const vi &ft, int b) {                      // returns RSQ(1, b) //RangeSumQuery.
  int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
  return sum; }

int ft_rsq(const vi &ft, int a, int b) {               // returns RSQ(a, b)
  return ft_rsq(ft, b) - (a == 1 ? 0 : ft_rsq(ft, a - 1)); }

// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
void ft_adjust(vi &ft, int k, int v) {           // note: n = ft.size() - 1
  for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }

int main() {
  vi ft;                  // idx   0 1 2 3 4 5 6 7  8 9 10, no index 0!
  ft_create(ft, 10);      // ft = {-,0,0,0,0,0,0,0, 0,0,0}
  ft_adjust(ft, 2, 1);    // ft = {-,0,1,0,1,0,0,0, 1,0,0}, idx 2,4,8 => +1
  ft_adjust(ft, 4, 1);    // ft = {-,0,1,0,2,0,0,0, 2,0,0}, idx 4,8 => +1
  ft_adjust(ft, 5, 2);    // ft = {-,0,1,0,2,2,2,0, 4,0,0}, idx 5,6,8 => +2
  ft_adjust(ft, 6, 3);    // ft = {-,0,1,0,2,2,5,0, 7,0,0}, idx 6,8 => +3
  ft_adjust(ft, 7, 2);    // ft = {-,0,1,0,2,2,5,2, 9,0,0}, idx 7,8 => +2
  ft_adjust(ft, 8, 1);    // ft = {-,0,1,0,2,2,5,2,10,0,0}, idx 8 => +1
  ft_adjust(ft, 9, 1);    // ft = {-,0,1,0,2,2,5,2,10,1,1}, idx 9,10 => +1
  printf("%d\n", ft_rsq(ft, 1, 1));  // 0 => ft[1] = 0
  printf("%d\n", ft_rsq(ft, 1, 2));  // 1 => ft[2] = 1
  printf("%d\n", ft_rsq(ft, 1, 6));  // 7 => ft[6] + ft[4] = 5 + 2 = 7
  printf("%d\n", ft_rsq(ft, 1, 10)); // 11 => ft[10] + ft[8] = 1 + 10 = 11
  printf("%d\n", ft_rsq(ft, 3, 6));  // 6 => rsq(1, 6) - rsq(1, 2) = 7 - 1

  ft_adjust(ft, 5, 2);                                       // update demo
  printf("Index: ");
  for (int i = 0; i < (int)ft.size(); i++)
    printf("%d ", i);
  printf("\n");
  printf("FT   : ");
  for (int i = 0; i < (int)ft.size(); i++)
    printf("%d ", ft[i]);
  printf("\n");
} // return 0;