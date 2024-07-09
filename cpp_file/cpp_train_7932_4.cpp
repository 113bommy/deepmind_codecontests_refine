#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  return x * f;
}
int n, c[105], tot = 0;
long double x, f[105][10005];
signed main() {
  n = read();
  scanf("%Lf", &x);
  x /= 2.0;
  for (int i = 1; i <= n; i++) c[i] = read(), tot += c[i];
  f[0][0] = 1.0;
  for (int i = 1; i <= n; i++)
    for (int k = i; k; k--)
      for (int j = c[i]; j <= tot; j++)
        f[k][j] += 1.0 * f[k - 1][j - c[i]] * k / (1.0 * n - k + 1);
  long double ans = 0.0;
  for (int k = 1; k <= n; k++)
    for (int j = 0; j <= tot; j++)
      ans += f[k][j] * min((long double)(1.0 * j / k),
                           (long double)(1.0 * n / k + 1) * x);
  printf("%.10Lf\n", ans);
  return 0;
}
