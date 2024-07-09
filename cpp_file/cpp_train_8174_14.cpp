#include <bits/stdc++.h>
int main() {
  int i, j, k, n;
  int d[100010], a[100010], b[100010], min = 1000000000, e[100010];
  scanf("%d", &n);
  d[0] = 0;
  for (i = 1; i <= n; i++) scanf("%d", a + i);
  for (i = 1; i <= n; i++) scanf("%d", b + i);
  for (i = 1; i <= n; i++) {
    d[i] = d[i - 1] + a[i] - b[i];
    if (min > d[i]) min = d[i];
  }
  if (min >= 0) e[1] = 1;
  for (i = 2; i <= n; i++) {
    min -= a[i - 1] - b[i - 1];
    if (min >= 0) e[i] = 1;
  }
  d[n + 1] = 0;
  b[0] = b[n];
  min = 1000000000;
  for (i = n; i >= 1; i--) {
    d[i] = d[i + 1] + a[i] - b[i - 1];
    if (min > d[i]) min = d[i];
  }
  if (min >= 0) e[n] += 1;
  for (i = n - 1; i >= 1; i--) {
    min -= a[i + 1] - b[i];
    if (min >= 0) e[i] += 1;
  }
  k = 0;
  for (i = 1; i <= n; i++)
    if (e[i]) k++;
  printf("%d\n", k);
  for (i = 1; i <= n; i++) {
    if (e[i]) {
      k--;
      printf("%d%c", i, k ? ' ' : '\n');
    }
  }
  getchar();
}
