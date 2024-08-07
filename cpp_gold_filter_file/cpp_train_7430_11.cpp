#include <bits/stdc++.h>
using namespace std;
long long dp[155][155][155][2][2], sum[4][155][155];
int ans, i, j, k, t1, t2, n, m;
const int MOD = 1000000007;
long long work(int A, int B, int C, int D, int E) {
  return (sum[A][D][E] - sum[A][B - 1][E] - sum[A][D][C - 1] +
          sum[A][B - 1][C - 1] + 2 * MOD) %
         MOD;
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++)
      for (k = j; k <= m; k++) {
        dp[i][j][k][0][0] = 1 + work(0, j, j, k, k);
        if (k != m)
          dp[i][j][k][0][1] = work(0, j, k + 1, k, m) + work(1, j, k, k, m);
        if (j != 1)
          dp[i][j][k][1][0] = work(0, 1, j, j - 1, k) + work(2, 1, j, j, k);
        if (k != m && j != 1)
          dp[i][j][k][1][1] = work(0, 1, k + 1, j - 1, m) +
                              work(1, 1, k, j - 1, m) +
                              work(2, 1, k + 1, j, m) + work(3, 1, k, j, m);
        for (t1 = 0; t1 < 2; t1++)
          for (t2 = 0; t2 < 2; t2++) dp[i][j][k][t1][t2] %= MOD;
      }
    for (j = 1; j <= m; j++)
      for (k = 1; k <= m; k++) {
        sum[0][j][k] = dp[i][j][k][0][0];
        sum[1][j][k] = dp[i][j][k][0][1];
        sum[2][j][k] = dp[i][j][k][1][0];
        sum[3][j][k] = dp[i][j][k][1][1];
      }
    for (t1 = 0; t1 < 4; t1++)
      for (j = 1; j <= m; j++)
        for (k = 1; k <= m; k++)
          sum[t1][j][k] = (sum[t1][j][k] + sum[t1][j][k - 1]) % MOD;
    for (t1 = 0; t1 < 4; t1++)
      for (j = 1; j <= m; j++)
        for (k = 1; k <= m; k++)
          sum[t1][j][k] = (sum[t1][j][k] + sum[t1][j - 1][k]) % MOD;
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      for (k = j; k <= m; k++)
        for (t1 = 0; t1 < 2; t1++)
          for (t2 = 0; t2 < 2; t2++) ans = (ans + dp[i][j][k][t1][t2]) % MOD;
  cout << ans;
  return 0;
}
