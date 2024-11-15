#include <bits/stdc++.h>
using namespace std;
long long dp[17][1 << 16];
int b[16], w[16], a[16], n;
long long solve(int p) {
  memset(a, -1, sizeof(a));
  int i, j, k;
  for (i = 0; i < p; i++) {
    a[w[i]] = i;
  }
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (i = 0; i < n; i++) {
    for (j = 0; j < 1 << n; j++)
      if (dp[i][j]) {
        for (k = 0; k < n; k++)
          if (!(j & (1 << k))) {
            if (a[i] != -1 && a[i] != k) continue;
            if ((j & b[k]) == b[k]) dp[i + 1][j | 1 << k] += dp[i][j];
          }
      }
  }
  return dp[n][(1 << n) - 1];
}
int main() {
  int m, i, j, k;
  long long y;
  while (~scanf("%d%I64d%d", &n, &y, &m)) {
    memset(b, 0, sizeof(b));
    for (i = 0; i < m; i++) {
      scanf("%d%d", &j, &k);
      j--, k--;
      b[k] |= 1 << j;
    }
    y -= 2001;
    if (y >= solve(0)) {
      puts("The times have changed");
      continue;
    }
    int use = 0;
    long long t;
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) {
        if (!(use & (1 << j))) {
          w[i] = j;
          if ((t = solve(i + 1)) <= y) {
            y -= t;
          } else {
            use |= 1 << j;
            break;
          }
        }
      }
    for (i = 0; i < n; i++) {
      printf("%d ", w[i] + 1);
    }
    puts("");
  }
  return 0;
}
