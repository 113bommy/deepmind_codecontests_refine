#include <bits/stdc++.h>
using namespace std;
const int u = 310, w = 3010;
double p[u][w], f[u][w], d[u], c[w], ans;
int n, m, i, j, k;
int main() {
  cin >> n >> m;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) scanf("%lf", &p[j][i]), p[j][i] *= 0.001;
  for (i = 1; i <= m; i++) {
    f[i][0] = 1;
    for (j = 1; j <= n; j++) f[i][j] = f[i][j - 1] * (1 - p[i][j]);
    d[i] = 1 - f[i][n];
  }
  for (i = 1; i <= n; i++) {
    for (j = 2, k = 1; j <= m; j++)
      if (d[k] < d[j]) k = j;
    for (j = 1; j <= n; j++)
      c[j] = c[j - 1] * (1 - p[k][j]) + f[k][j - 1] * p[k][j];
    for (j = 0; j <= n; j++) f[k][j] = c[j];
    ans += d[k], d[k] -= f[k][n];
  }
  printf("%.12f\n", ans);
  return 0;
}
