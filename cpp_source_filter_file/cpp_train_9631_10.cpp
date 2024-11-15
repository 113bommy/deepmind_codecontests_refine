#include <bits/stdc++.h>
using namespace std;
const long long N = 2e3 + 5;
const long long p = 1e9 + 7;
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
inline void add(long long &x, long long y) {
  x += y;
  if (x < 0) x += p;
  if (x >= p) x -= p;
}
char a[N], b[N], c[N];
long long dp[N][N][2], n, m, ans = 0;
const long long ADD = 1145141ll;
const long long MOD = 998244353ll;
long long a1[N], a2[N], b1[N], b2[N], c1[N], Pow[N];
long long get1(long long *a, long long l, long long r) {
  return (a[r] - a[l - 1] * Pow[r - l + 1] % MOD + MOD) % MOD;
}
long long get2(long long *a, long long l, long long r) {
  return (a[l] - a[r + 1] * Pow[r - l + 1] % MOD + MOD) % MOD;
}
void solve(bool flag) {
  memset(dp, 0, sizeof(dp));
  Pow[0] = 1;
  for (long long i = 1; i <= max(n, m); i++) Pow[i] = Pow[i - 1] * 27 % MOD;
  for (long long i = 1; i <= n; i++)
    a1[i] = (a1[i - 1] * 27 + a[i] - 'a' + 1 + ADD) % MOD;
  for (long long i = n; i >= 1; i--)
    a2[i] = (a2[i + 1] * 27 + a[i] - 'a' + 1 + ADD) % MOD;
  for (long long i = 1; i <= n; i++)
    b1[i] = (b1[i - 1] * 27 + b[i] - 'a' + 1 + ADD) % MOD;
  for (long long i = n; i >= 1; i--)
    b2[i] = (b2[i + 1] * 27 + b[i] - 'a' + 1 + ADD) % MOD;
  for (long long i = 1; i <= n; i++)
    c1[i] = (c1[i - 1] * 27 + c[i] - 'a' + 1 + ADD) % MOD;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j < i; j++) {
      if ((i - j + 1) * 2 > m) continue;
      long long hash =
          (get2(a2, j, i) * Pow[i - j + 1] % MOD + get1(b1, j, i)) % MOD;
      if (hash == get1(c1, 1, (i - j + 1) * 2)) dp[i][(i - j + 1) * 2][1] = 1;
      hash = (get2(b2, j, i) * Pow[i - j + 1] % MOD + get1(a1, j, i)) % MOD;
      if (hash == get1(c1, 1, (i - j + 1) * 2)) dp[i][(i - j + 1) * 2][0] = 1;
    }
  for (long long i = 0; i <= n; i++)
    for (long long j = 0; j <= 1; j++) dp[i][0][j] = 1;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
      if (a[i] == c[j]) add(dp[i][j][0], dp[i - 1][j - 1][0]);
      if (j >= 2 && a[i] == c[j] && b[i] == c[j - 1])
        add(dp[i][j][0], dp[i - 1][j - 2][1]);
      if (b[i] == c[j]) add(dp[i][j][1], dp[i - 1][j - 1][1]);
      if (j >= 2 && b[i] == c[j] && a[i] == c[j - 1])
        add(dp[i][j][1], dp[i - 1][j - 2][0]);
      if (j == m) add(ans, dp[i][j][0]);
      if (j == m) add(ans, dp[i][j][1]);
    }
  for (long long i = 1; i <= n; i++)
    for (long long j = i + 1; j <= n; j++) {
      if ((j - i + 1) * 2 > m) continue;
      long long hash =
          (get1(a1, i, j) * Pow[j - i + 1] % MOD + get2(b2, i, j)) % MOD;
      if (hash == get1(c1, m - (j - i + 1) * 2 + 1, m))
        add(ans, dp[i - 1][m - (j - i + 1) * 2][0]);
      hash = (get1(b1, i, j) * Pow[j - i + 1] % MOD + get2(a2, i, j)) % MOD;
      if (hash == get1(c1, m - (j - i + 1) * 2 + 1, m))
        add(ans, dp[i - 1][m - (j - i + 1) * 2][1]);
    }
  if (flag) {
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= i; j++) {
        if ((i - j + 1) * 2 != m) continue;
        long long hash =
            (get2(a2, j, i) * Pow[i - j + 1] % MOD + get1(b1, j, i)) % MOD;
        if (hash == get1(c1, 1, (i - j + 1) * 2)) add(ans, -1);
        hash = (get2(b2, j, i) * Pow[i - j + 1] % MOD + get1(a1, j, i)) % MOD;
        if (hash == get1(c1, 1, (i - j + 1) * 2)) add(ans, -1);
      }
    for (long long i = 1; i <= n; i++)
      for (long long j = i + 1; j <= n; j++) {
        if ((j - i + 1) * 2 != m) continue;
        long long hash =
            (get1(a1, i, j) * Pow[j - i + 1] % MOD + get2(b2, i, j)) % MOD;
        if (hash == get1(c1, m - (j - i + 1) * 2 + 1, m)) add(ans, -1);
        hash = (get1(b1, i, j) * Pow[j - i + 1] % MOD + get2(a2, i, j)) % MOD;
        if (hash == get1(c1, m - (j - i + 1) * 2 + 1, m)) add(ans, -1);
      }
  }
}
signed main() {
  scanf("%s%s%s", a + 1, b + 1, c + 1);
  n = strlen(a + 1);
  m = strlen(c + 1);
  solve(0);
  for (long long i = 1; i <= n / 2; i++) {
    swap(a[i], a[n - i + 1]);
    swap(b[i], b[n - i + 1]);
  }
  solve(1);
  if (n == 1 || m == 1)
    print(ans / 2);
  else
    print(ans);
  return 0;
}
