#include <bits/stdc++.h>
using namespace std;
int gi() {
  char cc = getchar();
  int cn = 0, flus = 1;
  while (cc < '0' || cc > '9') {
    if (cc == '-') flus = -flus;
    cc = getchar();
  }
  while (cc >= '0' && cc <= '9') cn = cn * 10 + cc - '0', cc = getchar();
  return cn * flus;
}
const int N = 100 + 5;
int n, c[N], m;
long double ans, t, f[N][10005];
long double Min(long double x, long double y) { return min(x, y); }
signed main() {
  n = gi(), t = gi(), t /= 2.0;
  for (register int i = (1); i <= (n); ++i) c[i] = gi(), m += c[i];
  f[0][0] = 1;
  for (register int i = (1); i <= (n); ++i)
    for (register int k = (i); k >= (1); --k)
      for (register int j = (c[i]); j <= (m); ++j)
        f[k][j] = (f[k][j] + f[k - 1][j - c[i]] * k / (1.0 * (n - k + 1)));
  for (register int k = (1); k <= (n); ++k)
    for (register int j = (0); j <= (m); ++j)
      ans = (ans + f[k][j] * Min(((long double)n / (long double)k + 1) * t,
                                 (long double)j / ((long double)k)));
  printf("%.10Lf\n", ans);
  return 0;
}
