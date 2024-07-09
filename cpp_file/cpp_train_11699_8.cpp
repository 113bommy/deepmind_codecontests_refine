#include <bits/stdc++.h>
int main() {
  int i, j, k, l, m, n;
  double res;
  scanf("%d%d%d", &n, &m, &k);
  res = 1;
  for (i = 0; i < k + 1; i++) {
    res *= m - i;
    res /= n + i + 1;
  }
  if (res < 0) res = 0;
  if (res > 1) res = 1;
  res = 1 - res;
  printf("%.10lf\n", res);
  return 0;
}
