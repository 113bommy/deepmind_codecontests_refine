#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int gcd(int x, int y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
int main() {
  scanf("%d%d", &n, &m);
  while (gcd(n, m) > 1) m /= gcd(n, m), k++;
  if (m == 1) {
    printf("2-type\n%d", k);
    goto die;
  }
  if (k == 0 && n % m == 1) {
    printf("3-type\n");
    goto die;
  }
  if (k == 0 && n % m == m - 1) {
    printf("11-type\n");
    goto die;
  }
  if ((n * n - 1) / (n % 2 + 1) % m == 0) {
    printf("6-type\n");
    goto die;
  }
  printf("7-type\n");
die:;
  return 0;
}
