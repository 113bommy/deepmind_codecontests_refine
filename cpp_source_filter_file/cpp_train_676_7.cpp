#include <bits/stdc++.h>
using namespace std;
char s[105][105][105];
int a[105][105][105];
int h, n, m;
int main() {
  int i, j, k, u, v;
  scanf("%d%d%d", &h, &n, &m);
  for (k = 1; k <= h; k++) {
    for (i = 1; i <= n; i++) scanf("%s", s[k][i]);
  }
  for (k = 1; k <= h; k++) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) a[k][i][j] = s[k][i][j] - '0';
    }
  }
  int ans = 0;
  for (i = 1; i <= h; i++)
    for (j = 1; j <= n; j++)
      for (k = 1; k <= m; k++)
        if (a[i][j][k])
          ans += a[i - 1][j][k] &&
                     (a[i + 1][j][k] || a[i][j + 1][k] && !a[i - 1][j + 1][k] ||
                      a[i][j][k + 1] && !a[i - 1][j][k + 1]) ||
                 a[i][j - 1][k] &&
                     (a[i][j + 1][k] || a[i + 1][j][k] && !a[i + 1][j - 1][k] ||
                      a[i][j][k + 1] && !a[i][j - 1][k + 1]) ||
                 a[i][j][k - 1] &&
                     (a[i][j][k + 1] || a[i][j + 1][k] && !a[i][j + 1][k - 1] ||
                      a[i + 1][j][k] && !a[i + 1][j][k - 1]);
  printf("%d\n", ans);
  return 0;
}
