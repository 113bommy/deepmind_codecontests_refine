#include <bits/stdc++.h>
using namespace std;
const int maxn = 21;
int n, m;
int a[maxn], b[maxn];
long long dp[maxn][maxn][maxn], ans[maxn][maxn], s[maxn][maxn];
void cal(long long a[maxn][maxn], long long b[maxn][maxn]) {
  long long s[maxn][maxn];
  memset(s, 50, sizeof(s));
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      for (int k = 0; k <= n; k++) s[i][j] = min(s[i][j], a[i][k] + b[k][j]);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) a[i][j] = s[i][j];
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  memset(dp, 50, sizeof(dp));
  for (int k = 0; k <= n; k++) {
    dp[k][0][k] = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j <= n; j++) {
        dp[k][i + 1][j + 1] = min(dp[k][i + 1][j + 1], dp[k][i][j] + a[i + 1]);
        if (j - 1 >= 0)
          dp[k][i + 1][j - 1] =
              min(dp[k][i + 1][j - 1], dp[k][i][j] + b[i + 1]);
      }
  }
  memset(ans, 50, sizeof(ans));
  for (int i = 0; i <= n; i++) ans[i][i] = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) s[i][j] = dp[i][n][j];
  while (m) {
    if (m & 1) cal(ans, s);
    cal(s, s);
    m /= 2;
  }
  cout << ans[0][0] << endl;
  return 0;
}
