#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
double dp[1005][1005];
int main() {
  scanf("%d%d%d%d", &n, &m, &x, &y);
  if (x == n)
    puts("0");
  else if (m == 1) {
    printf("%.10f\n", (n - x) * 2.0);
  } else {
    for (int i = n - 1; i >= x; i--) {
      for (int tt = 0; tt < 50; tt++) {
        for (int j = 1; j <= m; j++) {
          if (j == 1)
            dp[i][j] = (dp[i + 1][j] + dp[i][j + 1] + dp[i][j]) / 3.0 + 1;
          else if (j == m)
            dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + dp[i][j]) / 3.0 + 1;
          else
            dp[i][j] =
                (dp[i + 1][j] + dp[i][j] + dp[i][j - 1] + dp[i][j + 1]) / 4.0 +
                1;
        }
      }
    }
    printf("%.10f\n", dp[x][y]);
  }
  return 0;
}
