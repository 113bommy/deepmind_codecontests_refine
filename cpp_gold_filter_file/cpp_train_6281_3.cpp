#include <bits/stdc++.h>
using namespace std;
const int N = 2001000;
int n, u, v, c, m, f[N], y[N], nxt[N], fst[N], w[N], dep[N], cnt[N], id[N],
    F[N][18], tot;
char ch;
long long len[N], ans;
set<int> mp;
void add(int u, int v, int c) {
  tot++;
  y[tot] = v;
  nxt[tot] = fst[u];
  w[tot] = c;
  fst[u] = tot;
}
int LCA(int u, int v) {
  if (dep[u] > dep[v]) swap(u, v);
  for (int k = dep[v] - dep[u], j = 17; j >= 0; j--)
    if ((k >> j) & 1) v = F[v][j], k ^= (1 << j);
  if (u == v) return u;
  for (int k = 17; f[u] != f[v]; u = F[u][k], v = F[v][k])
    for (; k && F[u][k] == F[v][k]; k--)
      ;
  return f[u];
}
void dfs(int u, int p) {
  f[u] = p;
  id[cnt[u] = ++tot] = u;
  for (int j = fst[u]; j; j = nxt[j])
    if (y[j] != p)
      len[y[j]] = len[u] + w[j], dep[y[j]] = dep[u] + 1, dfs(y[j], u);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++)
    scanf("%d%d%d", &u, &v, &c), add(u, v, c), add(v, u, c);
  tot = 0;
  dfs(1, 0);
  id[n + 1] = n + 1;
  for (int i = 0; i < n; i++) F[i + 1][0] = f[i + 1];
  for (int j = 1; j <= 17; j++)
    for (int i = 0; i < n; i++) F[i + 1][j] = F[F[i + 1][j - 1]][j - 1];
  for (scanf("%d", &m); m; m--) {
    scanf(" %c", &ch);
    if (ch == '?')
      printf("%I64d\n", ans);
    else {
      scanf("%d ", &u);
      typeof(mp.begin()) it = mp.lower_bound(cnt[u]);
      if (*it == cnt[u]) mp.erase(cnt[u]), it = mp.lower_bound(cnt[u]);
      if (!mp.size()) {
        if (ch == '+') mp.insert(cnt[u]);
        continue;
      }
      int q = id[(it == mp.end()) ? *mp.begin() : *it],
          p = id[(it-- == mp.begin()) ? *(--mp.end()) : *it];
      long long dt = len[u] - len[LCA(p, u)] - len[LCA(q, u)] + len[LCA(p, q)];
      if (ch == '+')
        ans += dt, mp.insert(cnt[u]);
      else
        ans -= dt;
    }
  }
}
