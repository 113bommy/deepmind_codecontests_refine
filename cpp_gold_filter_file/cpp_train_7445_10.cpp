#include <bits/stdc++.h>
using namespace std;
bool ff;
int n, k, i, x, y, l, r, mid, ans, tot, fir[400400], ne[400400], la[400400],
    g[400400], zs[400400], g2[400400], f[400400], sum[400400], up[400400],
    a[400400];
void ins(int x, int y) {
  la[++tot] = y;
  ne[tot] = fir[x];
  fir[x] = tot;
}
void dfs(int x, int fa, int w) {
  if (a[x] >= w)
    zs[x] = 0;
  else
    zs[x] = 1;
  g[x] = 0;
  g2[x] = 0;
  f[x] = 0;
  for (int i = fir[x], y; i; i = ne[i])
    if (la[i] != fa) {
      y = la[i];
      dfs(y, x, w);
      if (!zs[y])
        f[x] += f[y];
      else if (f[y] > g[x])
        g2[x] = g[x], g[x] = f[y];
      else if (f[y] > g2[x])
        g2[x] = f[y];
      zs[x] += zs[y];
    }
  sum[x] = f[x];
  if (a[x] < w)
    f[x] = 0;
  else
    f[x] += 1 + g[x];
}
void dfs2(int x, int fa, int w) {
  int v = 0, mx = 0, i, y;
  if (a[x] >= w) {
    if (zs[1] - zs[x] == 0)
      v += up[x];
    else
      mx = max(mx, up[x]);
    for (i = fir[x]; i; i = ne[i])
      if (la[i] != fa)
        if (zs[y = la[i]] == 0)
          v += f[y];
        else
          mx = max(mx, f[y]);
    v += mx + 1;
    if (v >= k) {
      ff = 1;
      return;
    }
  }
  for (i = fir[x]; i; i = ne[i])
    if (la[i] != fa) {
      y = la[i];
      if (a[x] < w)
        up[y] = 0;
      else {
        v = sum[x];
        mx = 0;
        if (zs[y] == 0)
          v -= f[y];
        else if (g[x] == f[y])
          mx = max(mx, g2[x]);
        else
          mx = max(mx, g[x]);
        if (zs[1] - zs[x] == 0)
          v += up[x];
        else
          mx = max(mx, up[x]);
        up[y] = v + mx + 1;
      }
      dfs2(y, x, w);
    }
}
bool ok(int x) {
  dfs(1, 0, x);
  ff = 0;
  dfs2(1, 0, x);
  return ff;
}
int main() {
  for (scanf("%d%d", &n, &k), i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i < n; i++) scanf("%d%d", &x, &y), ins(x, y), ins(y, x);
  for (l = 1, r = 1000000; l <= r;)
    if (ok(mid = l + r >> 1))
      l = (ans = mid) + 1;
    else
      r = mid - 1;
  printf("%d", ans);
}
