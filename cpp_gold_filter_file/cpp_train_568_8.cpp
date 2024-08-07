#include <bits/stdc++.h>
using namespace std;
int n, m;
char ss[120][120];
int dp[1 << 20], cv[120][120], a[120][120], co[120][120];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", ss[i] + 1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int tmp = 0;
      for (int k = 1; k <= n; k++) {
        if (ss[i][j] == ss[k][j]) {
          co[i][j] += a[k][j];
          cv[i][j] += (1 << (k - 1));
          tmp = max(tmp, a[k][j]);
        }
      }
      co[i][j] -= tmp;
    }
  }
  for (int i = 1; i < (1 << n); i++) {
    dp[i] = 100000000;
    int lowbit;
    for (int j = 1; j <= n; j++) {
      if (((1 << (j - 1)) & i) != 0) lowbit = j;
    }
    for (int j = 1; j <= m; j++) {
      dp[i] = min(dp[i], dp[i & (i ^ cv[lowbit][j])] + co[lowbit][j]);
      dp[i] = min(dp[i], dp[i ^ (1 << (lowbit - 1))] + a[lowbit][j]);
    }
  }
  printf("%d\n", dp[(1 << n) - 1]);
  return 0;
}
