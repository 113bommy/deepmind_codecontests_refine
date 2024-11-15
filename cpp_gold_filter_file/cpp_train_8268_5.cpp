#include <bits/stdc++.h>
using std::min;
int n, m, q, o, x, y, a, b, ans, s, t;
int u[1024][1024], d[1024][1024], l[1024][1024], r[1024][1024];
bool c[1024][1024];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &o);
      c[i][j] = o;
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (c[i][j]) {
        u[i][j] = u[i - 1][j] + 1;
        l[i][j] = l[i][j - 1] + 1;
      }
  for (int i = n; i; --i)
    for (int j = m; j; --j)
      if (c[i][j]) {
        d[i][j] = d[i + 1][j] + 1;
        r[i][j] = r[i][j + 1] + 1;
      }
  while (q--) {
    scanf("%d%d%d", &o, &x, &y);
    if (o == 1) {
      if (c[x][y]) {
        u[x][y] = d[x][y] = l[x][y] = r[x][y] = c[x][y] = false;
        for (int i = x - 1; c[i][y]; --i) d[i][y] = d[i + 1][y] + 1;
        for (int i = x + 1; c[i][y]; ++i) u[i][y] = u[i - 1][y] + 1;
        for (int j = y - 1; c[x][j]; --j) r[x][j] = r[x][j + 1] + 1;
        for (int j = y + 1; c[x][j]; ++j) l[x][j] = l[x][j - 1] + 1;
      } else {
        c[x][y] = true;
        for (int i = x; c[i][y]; --i) d[i][y] = d[i + 1][y] + 1;
        for (int i = x; c[i][y]; ++i) u[i][y] = u[i - 1][y] + 1;
        for (int j = y; c[x][j]; --j) r[x][j] = r[x][j + 1] + 1;
        for (int j = y; c[x][j]; ++j) l[x][j] = l[x][j - 1] + 1;
      }
    } else {
      ans = 0;
      t = u[x][y];
      for (a = b = y; 1 <= a && b <= m;) {
        s = (b - a + 1) * t;
        if (ans < s) ans = s;
        if (u[x][a - 1] < u[x][b + 1])
          t = min(t, u[x][++b]);
        else
          t = min(t, u[x][--a]);
      }
      t = d[x][y];
      for (a = b = y; 1 <= a && b <= m;) {
        s = (b - a + 1) * t;
        if (ans < s) ans = s;
        if (d[x][a - 1] < d[x][b + 1])
          t = min(t, d[x][++b]);
        else
          t = min(t, d[x][--a]);
      }
      t = l[x][y];
      for (a = b = x; 1 <= a && b <= n;) {
        s = (b - a + 1) * t;
        if (ans < s) ans = s;
        if (l[a - 1][y] < l[b + 1][y])
          t = min(t, l[++b][y]);
        else
          t = min(t, l[--a][y]);
      }
      t = r[x][y];
      for (a = b = x; 1 <= a && b <= n;) {
        s = (b - a + 1) * t;
        if (ans < s) ans = s;
        if (r[a - 1][y] < r[b + 1][y])
          t = min(t, r[++b][y]);
        else
          t = min(t, r[--a][y]);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
