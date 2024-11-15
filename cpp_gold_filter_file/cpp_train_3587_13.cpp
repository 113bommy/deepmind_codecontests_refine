#include <bits/stdc++.h>
using namespace std;
long long int sum[1505][1505];
long long int dp[1505][1505];
int main() {
  int n, m, i, j;
  long long int t, s, ans;
  while (~scanf("%d %d", &n, &m)) {
    for (i = 0; i < n; i++) {
      s = 0;
      for (j = 0; j < m; j++) {
        scanf("%I64d", &t);
        s += t;
        sum[i][j] = s;
      }
    }
    for (i = 0; i < m; i++) dp[0][i] = sum[0][i];
    for (i = 1; i < n; i++) {
      if (i % 2 == 1) {
        dp[i][m - 1] = -1e18;
        t = -1e18;
        for (j = m - 2; j >= 0; j--) {
          t = max(dp[i - 1][j + 1], t);
          dp[i][j] = t + sum[i][j];
        }
      } else {
        dp[i][0] = -1e18;
        t = -1e18;
        for (j = 1; j < m; j++) {
          t = max(dp[i - 1][j - 1], t);
          dp[i][j] = t + sum[i][j];
        }
      }
    }
    ans = -1e18;
    for (i = 0; i < m; i++) ans = max(dp[n - 1][i], ans);
    printf("%I64d\n", ans);
  }
}
