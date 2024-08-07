#include <bits/stdc++.h>
using namespace std;
const long long N = 5e3 + 5;
long long read() {
  long long s = 0;
  char c = getchar(), lc = '+';
  while (c < '0' || '9' < c) lc = c, c = getchar();
  while ('0' <= c && c <= '9') s = s * 10 + c - '0', c = getchar();
  return lc == '-' ? -s : s;
}
void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x < 10)
    putchar(x + '0');
  else {
    write(x / 10);
    putchar(x % 10 + '0');
  }
}
void print(long long x, char c = '\n') {
  write(x);
  putchar(c);
}
long long dp[N][N], a[N], q[N];
signed main(signed Recall, char *_902_[]) {
  (void)Recall, (void)_902_;
  long long n = read(), k = read(), m = read(), ans = -1;
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= n; i++) dp[i][0] = dp[0][i] = -1;
  for (long long j = 1; j <= m; j++)
    for (long long i = 1, h = 0, t = q[0] = 0; i <= n; i++) {
      while (h <= t && i - q[h] > k) h++;
      if (h <= t && dp[q[h]][j - 1] >= 0)
        dp[i][j] = dp[q[h]][j - 1] + a[i];
      else
        dp[i][j] = -1;
      while (h <= t && dp[q[t]][j - 1] <= dp[i][j - 1]) t--;
      q[++t] = i;
    }
  for (long long i = max(n - k + 1, 1LL); i <= n; i++) ans = max(ans, dp[i][m]);
  print(ans);
  return 0;
}
