#include <bits/stdc++.h>
int primeFactor[1003];
int main() {
  int n, ans = 0, i, j;
  scanf("%d", &n);
  for (i = 2; i <= n; i++)
    if (primeFactor[i] == 0)
      for (j = i + i; j <= n; j += i) primeFactor[j]++;
  for (i = 2; i <= n; i++)
    if (primeFactor[i] < 2) ans++;
  printf("%d\n", ans);
  for (i = 2; i <= n; i++)
    if (primeFactor[i] < 2) printf("%d ", i);
  return 0;
}
