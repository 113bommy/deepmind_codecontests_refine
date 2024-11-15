#include <bits/stdc++.h>
const int N = 100000 + 9, M = 300000 + 9, lim = 314000000;
int monster[N], split[N], n, m, ec, nxt[M], lnk[M], f[N], g[N], sid[N], from[N],
    ind[N], dis[N];
bool inst[N];
struct info {
  int dis, mid;
  info(const int _dis, const int _mid) : dis(_dis), mid(_mid) {}
  bool operator<(const info &o) const { return dis > o.dis; }
};
std::priority_queue<info> q;
inline void addedge(int &x, int y) {
  nxt[++ec] = x;
  lnk[ec] = y;
  x = ec;
}
int dfs(int u);
int calc(int x) {
  int res = 0;
  for (int i = monster[x]; i; i = nxt[i])
    if (lnk[i] != -1 && f[lnk[i]] == -1) return -2;
  for (int i = monster[x]; i; i = nxt[i])
    if (lnk[i] == -1)
      ++res;
    else if (dfs(lnk[i]) == -2)
      return -2;
    else
      res = std::min(res + g[lnk[i]], lim);
  return std::min(lim, res);
}
int dfs(int u) {
  if (g[u] != 0xC0C0C0C0) return g[u];
  if (f[u] == -1) return g[u] = -2;
  if (inst[u]) return g[u] = -2;
  inst[u] = true;
  int res = 0xC0C0C0C0;
  for (int i = sid[u]; i; i = nxt[i]) {
    int t = calc(lnk[i]);
    if (t == -2) return inst[u] = false, g[u] = -2;
    res = std::max(res, t);
  }
  inst[u] = false;
  return g[u] = res;
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1, x, k; i <= m; ++i) {
    scanf("%d%d", from + i, &k);
    addedge(sid[from[i]], i);
    while (k--) {
      scanf("%d", &x);
      addedge(monster[i], x);
      if (x > 0)
        addedge(split[x], i), ++ind[i];
      else
        ++dis[i];
    }
    if (!ind[i]) q.push(info(dis[i], from[i]));
  }
  memset(f, -1, sizeof f);
  memset(g, 0xC0, sizeof g);
  while (!q.empty()) {
    const info res = q.top();
    q.pop();
    if (f[res.mid] != -1) continue;
    f[res.mid] = res.dis;
    for (int i = split[res.mid]; i; i = nxt[i]) {
      dis[lnk[i]] = std::min(dis[lnk[i]] + res.dis, lim);
      if (!--ind[lnk[i]]) q.push(info(dis[lnk[i]], from[lnk[i]]));
    }
  }
  for (int i = 1; i <= n; ++i) dfs(i);
  for (int i = 1; i <= n; ++i)
    printf("%d %d\n", f[i], (f[i] == -1) ? -1 : g[i]);
}
