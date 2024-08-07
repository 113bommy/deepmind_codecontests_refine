#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
struct edge {
  int t, next;
} g[210001], g2[210001];
int ans, i, j, k, n, m, st[110001], h2[110001], h[110001], tot, tot2,
    f[110001][2], p[110001], ts[110001], now, a[110001], dep[110001],
    tv[110001], lca[110001][21], tn;
bool cmp(int x, int y) { return p[x] < p[y]; }
void addedge(int x, int y) {
  g[++tot].t = y;
  g[tot].next = h[x];
  h[x] = tot;
}
void addedge2(int x, int y) {
  g2[++tot2].t = y;
  g2[tot2].next = h2[x];
  h2[x] = tot2;
  g2[++tot2].t = x;
  g2[tot2].next = h2[y];
  h2[y] = tot2;
}
void dfs(int x) {
  int i;
  p[x] = ++tn;
  for (i = 1; lca[x][i - 1]; i++) lca[x][i] = lca[lca[x][i - 1]][i - 1];
  for (i = h2[x]; i; i = g2[i].next)
    if (lca[x][0] != g2[i].t) {
      dep[g2[i].t] = dep[x] + 1;
      lca[g2[i].t][0] = x;
      dfs(g2[i].t);
    }
}
int getlca(int x, int y) {
  int i;
  if (dep[x] > dep[y]) swap(x, y);
  for (i = 20; dep[y] > dep[x]; y = lca[y][i])
    for (; dep[lca[y][i]] < dep[x]; i--)
      ;
  for (i = 20; x != y; x = lca[x][i], y = lca[y][i])
    for (; lca[x][i] == lca[y][i] && i; i--)
      ;
  return x;
}
void dp(int x) {
  int i, k, t1, t2, t3, t4;
  for (t1 = t2 = t3 = t4 = k = 0, i = h[x]; i; i = g[i].next) {
    dp(g[i].t);
    t1 += f[g[i].t][1];
    t2 = min(inf, t2 + f[g[i].t][0]);
    if (ts[g[i].t] != now)
      t3 += f[g[i].t][0];
    else
      k++, t3 += f[g[i].t][1];
    t4 = max(t4, f[g[i].t][0] - f[g[i].t][1]);
  }
  if (ts[x] == now) {
    f[x][0] = inf;
    f[x][1] = t2;
  } else {
    f[x][0] = min(t2, 1 + t1);
    if (!k) f[x][1] = min(1 + t1, t2 - t4);
    if (k == 1) f[x][1] = min(1 + t1, t3);
    if (k > 1) f[x][1] = f[x][0];
  }
}
int solve() {
  int i, k, t;
  now++;
  tot = 0;
  for (i = 1; i <= a[0]; i++) ts[a[i]] = tv[a[i]] = now, h[a[i]] = 0;
  for (i = 1; i <= a[0]; i++) {
    if (ts[a[i]] != now) break;
    if (a[i] > 1 && ts[lca[a[i]][0]] == now) return -1;
    if (a[i] > 1 && tv[lca[a[i]][0]] != now) {
      tv[lca[a[i]][0]] = now;
      h[lca[a[i]][0]] = 0;
      a[++a[0]] = lca[a[i]][0];
    }
  }
  sort(a + 1, a + 1 + a[0], cmp);
  for (i = 2, t = 1, st[1] = a[1]; i <= a[0]; i++) {
    k = getlca(st[t], a[i]);
    if (tv[k] != now) tv[k] = now, h[k] = 0;
    for (; t && dep[st[t]] > dep[k]; t--)
      addedge((t > 1 && dep[st[t - 1]] > dep[k]) ? st[t - 1] : k, st[t]);
    if (!t || st[t] != k) st[++t] = k;
    st[++t] = a[i];
  }
  for (i = 2; i <= t; i++) addedge(st[i - 1], st[i]);
  dp(a[1]);
  return f[a[1]][1];
}
int main() {
  scanf("%d", &n);
  memset(lca, 0, sizeof(lca));
  memset(h2, 0, sizeof(h2));
  memset(tv, 0, sizeof(tv));
  memset(ts, 0, sizeof(ts));
  tot2 = now = tn = 0;
  for (i = 1; i < n; i++) scanf("%d%d", &j, &k), addedge2(j, k);
  dep[1] = 1;
  dep[0] = 0;
  dfs(1);
  scanf("%d", &m);
  for (i = 1; i <= m; i++) {
    scanf("%d", &a[0]);
    for (j = 1; j <= a[0]; j++) scanf("%d", &a[j]);
    ans = solve();
    printf("%d\n", ans);
  }
  return 0;
}
