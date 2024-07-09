#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,inline,unroll-loops")
int n, d[4005][4005], x[4005], y[4005], p[4005];
int main() {
  int r = 0, i, j, k, b, c;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d%d", x + i, y + i);
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++)
      d[i][j] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++)
      if (d[i][j] > r) {
        for (k = j + 1; k <= n; k++) {
          b = d[i][k], c = d[j][k];
          if (b > c) b = c;
          if (r < b) r = b;
        }
        if (r > d[i][j]) r = d[i][j];
      }
  printf("%.12lf\n", sqrt(r) * .5);
  return 0;
}
