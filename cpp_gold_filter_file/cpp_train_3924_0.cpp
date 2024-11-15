#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  for (x = c - '0'; (c = getchar()) >= '0' && c <= '9';) x = x * 10 + c - '0';
  return x;
}
struct edge {
  int nx, t;
} e[200000 * 2 + 5];
int h[200000 + 5], en, d[200000 + 5], u[18][200000 + 5], fa[18][200000 + 5],
    l[200000 + 5], r[200000 + 5], cnt;
int A[200000 + 5], B[200000 + 5], a[200000 + 5], b[200000 + 5], c[200000 + 5],
    s[200000 + 5], t[200000 + 5];
vector<int> v[200000 + 5];
void add(int x) {
  for (; x <= 200000; x += x & -x) ++t[x];
}
int sum(int x) {
  int res = 0;
  for (; x; x -= x & -x) res += t[x];
  return res;
}
inline void ins(int x, int y) {
  e[++en] = (edge){h[x], y};
  h[x] = en;
  e[++en] = (edge){h[y], x};
  h[y] = en;
}
void dfs(int x) {
  l[x] = ++cnt;
  for (int i = h[x]; i; i = e[i].nx)
    if (e[i].t != fa[0][x])
      fa[0][e[i].t] = x, u[0][e[i].t] = d[e[i].t] = d[x] + 1, dfs(e[i].t);
  r[x] = cnt;
}
int lca(int x, int y) {
  int k = d[x] - d[y], i;
  if (k < 0) k = -k, swap(x, y);
  for (i = 0; k; k >>= 1, ++i)
    if (k & 1) x = fa[i][x];
  if (x == y) return x;
  for (i = 18; i--;)
    if (fa[i][x] != fa[i][y]) x = fa[i][x], y = fa[i][y];
  return fa[0][x];
}
void dp(int x) {
  for (int i = h[x]; i; i = e[i].nx)
    if (e[i].t != fa[0][x]) dp(e[i].t), u[0][x] = min(u[0][x], u[0][e[i].t]);
}
int up(int x, int y) {
  for (int i = 0; y; y >>= 1, ++i)
    if (y & 1) x = fa[i][x];
  return x;
}
void solve(int x) {
  for (int i = 0; i < v[x].size(); ++i)
    if (v[x][i] > 0) s[v[x][i]] -= sum(r[b[v[x][i]]]) - sum(l[b[v[x][i]]] - 1);
  for (int i = 0; i < v[x].size(); ++i)
    if (v[x][i] < 0) add(l[-v[x][i]]);
  for (int i = h[x]; i; i = e[i].nx)
    if (e[i].t != fa[0][x]) solve(e[i].t);
  for (int i = 0; i < v[x].size(); ++i)
    if (v[x][i] > 0) s[v[x][i]] += sum(r[b[v[x][i]]]) - sum(l[b[v[x][i]]] - 1);
}
int main() {
  int n, t, m, i, j, l;
  n = read();
  for (i = 2; i <= n; ++i) ins(i, read());
  dfs(1);
  for (l = 1; l < 18; ++l)
    for (i = 1; i <= n; ++i) fa[l][i] = fa[l - 1][fa[l - 1][i]];
  t = read();
  for (i = 1; i <= t; ++i) {
    l = lca(A[i] = read(), B[i] = read());
    u[0][A[i]] = min(u[0][A[i]], d[l]);
    u[0][B[i]] = min(u[0][B[i]], d[l]);
    v[A[i]].push_back(-B[i]);
    v[B[i]].push_back(-A[i]);
  }
  dp(1);
  for (i = 1; i <= n; ++i) u[0][i] = up(i, d[i] - u[0][i]);
  for (l = 1; l < 18; ++l)
    for (i = 1; i <= n; ++i) u[l][i] = u[l - 1][u[l - 1][i]];
  m = read();
  for (i = 1; i <= m; ++i) {
    l = lca(a[i] = read(), b[i] = read());
    if (b[i] == l) swap(a[i], b[i]);
    if (a[i] == l) {
      for (j = 18; j--;)
        if (d[u[j][b[i]]] > d[l]) b[i] = u[j][b[i]], c[i] += 1 << j;
      if (d[u[0][b[i]]] > d[l]) c[i] = -1;
      continue;
    }
    for (j = 18; j--;)
      if (d[u[j][a[i]]] > d[l]) a[i] = u[j][a[i]], c[i] += 1 << j;
    for (j = 18; j--;)
      if (d[u[j][b[i]]] > d[l]) b[i] = u[j][b[i]], c[i] += 1 << j;
    if (d[u[0][a[i]]] > d[l] || d[u[0][b[i]]] > d[l])
      c[i] = -1;
    else
      ++c[i], v[a[i]].push_back(i);
  }
  solve(1);
  for (i = 1; i <= m; ++i) {
    if (c[i] + 1 - bool(s[i]) == 0)
      printf("-1\n");
    else
      printf("%d\n", c[i] + 1 - bool(s[i]));
  }
  return 0;
}
