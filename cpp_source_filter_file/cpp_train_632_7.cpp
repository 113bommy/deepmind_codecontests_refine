#include <bits/stdc++.h>
using namespace std;
long long q, k, n;
int main(void) {
  int i, T, p, flag = 0;
  scanf("%I64d", &n);
  scanf("%I64d", &k);
  scanf("%d", &p);
  T = n;
  if (k == 0) flag = 1;
  if (n % 2 == 1) {
    n--;
    if (k > 0) k--;
  }
  for (i = 0; i < p; i++) {
    scanf("%I64d", &q);
    if (flag) {
      printf(".");
      continue;
    }
    if (q == T) {
      printf("X");
      continue;
    }
    if (k <= n / 2) {
      if (q <= (n - 2 * k))
        printf(".");
      else {
        if ((q - (n - 2 * k)) % 2 == 0)
          printf("X");
        else
          printf(".");
      }
    } else {
      if (n > 2 * (n - k))
        printf("X");
      else {
        if (q % 2 == 1)
          printf(".");
        else
          printf("X");
      }
    }
  }
  return 0;
}
