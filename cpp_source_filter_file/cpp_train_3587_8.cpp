#include <bits/stdc++.h>
const int MAXN = 1505;
const long long int INF = 0x3f3f3f3f3f3f3f3fLL;
long long int dp[MAXN][MAXN];
int val[MAXN][MAXN], n, m;
inline long long int max(long long int a, long long int b) {
  return a > b ? a : b;
}
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= m; ++j) {
      scanf("%d", &val[i][j]);
      val[i][j] += val[i][j - 1];
    }
  dp[1][m + 1] = dp[1][0] = -INF;
  for (i = m; i; --i) dp[1][i] = max(val[1][i], dp[1][i + 1]);
  for (i = 2; i <= n; ++i) {
    for (j = 1; j <= m; ++j)
      if (i & 1)
        dp[i][j] = dp[i - 1][j - 1] + val[i][j];
      else
        dp[i][j] = dp[i - 1][j + 1] + val[i][j];
    dp[i][0] = dp[i][m + 1] = -INF;
    if (i & 1)
      for (i = m; i; --i) dp[i][j] = max(dp[i][j], dp[i][j + 1]);
    else
      for (i = 1; i <= m; ++i) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
  }
  printf("%I64d\n", max(dp[n][1], dp[n][m]));
  return 0;
}
