#include <bits/stdc++.h>
using namespace std;
const int MAXD = 40;
int n, a[300005];
long long f[300005][MAXD + 5];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) a[i] /= 100;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= MAXD; ++j) f[i][j] = 1e18;
  f[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= MAXD; ++j) {
      if (f[i - 1][j] == 1e18) continue;
      if (j >= a[i])
        f[i][j - a[i]] = min(f[i][j - a[i]], f[i - 1][j]);
      else
        f[i][0] = min(f[i][0], f[i - 1][j] + (a[i] - j) * 100);
      f[i][min(j + a[i] / 10, MAXD)] =
          min(f[i][min(j + a[i] / 10, MAXD)], f[i - 1][j] + a[i] * 100);
    }
  }
  long long ans = 1e18;
  for (int i = 0; i <= MAXD; ++i) ans = min(ans, f[n][i]);
  printf("%I64d\n", ans);
  return 0;
}
