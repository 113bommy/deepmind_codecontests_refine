#include <bits/stdc++.h>
int main() {
  int dp[2][(501)][(501)], c[(501)], now = 0, pre = 1, n, kk, i, j, k, sum = 0;
  memset(dp, 0, 2 * (501) * (501) * sizeof(int));
  scanf("%d%d", &n, &kk);
  for (i = 1; i <= n; i++) scanf("%d", &c[i]);
  dp[0][0][0] = 1;
  dp[1][0][0] = 1;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= kk; j++) {
      if (j >= c[i])
        dp[now][j][0] = dp[pre][j - c[i]][0] + dp[pre][j][0];
      else
        dp[now][j][0] = dp[pre][j][0];
      for (k = 1; k <= j; k++) {
        if (j >= c[i]) {
          if (k >= c[i])
            dp[now][j][k] = dp[pre][j - c[i]][k - c[i]] + dp[pre][j - c[i]][k] +
                            dp[pre][j][k];
          else
            dp[now][j][k] = dp[pre][j - c[i]][k] + dp[pre][j][k];
        } else
          dp[now][j][k] = dp[pre][j][k];
        if (dp[now][j][k]) dp[now][j][k] = 1;
      }
    }
    pre = now;
    now = (now + 1) % 2;
  }
  for (i = 0; i <= kk; i++)
    if (dp[now][kk][i]) sum++;
  printf("%d\n", sum);
  for (i = 0; i <= kk; i++)
    if (dp[now][kk][i]) printf("%d ", i);
  return 0;
}
