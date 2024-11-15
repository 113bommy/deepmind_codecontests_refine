#include <bits/stdc++.h>
using namespace std;
struct Flow {
  int S, T, t, head[20005], lk[200005], next[200005], c[200005], d[20005],
      q[20005];
  void set(int _s, int _t) { S = _s, T = _t, t = 1; }
  void add(int u, int v, int x) {
    lk[++t] = v, c[t] = x, next[t] = head[u], head[u] = t;
    lk[++t] = u, c[t] = 0, next[t] = head[v], head[v] = t;
  }
  bool bfs() {
    memset(d, 0, sizeof(d));
    q[1] = S, d[S] = 1;
    for (int l = 1, r = 1; l <= r; l++)
      for (int u = q[l], i = head[u], v; v = lk[i], i; i = next[i])
        if (c[i] && !d[v]) {
          d[v] = d[u] + 1, q[++r] = v;
          if (v == T) return 1;
        }
    return 0;
  }
  int dinic(int u, int low) {
    if (u == T) return low;
    int s = 0, f;
    for (int i = head[u], v; v = lk[i], i && s < low; i = next[i])
      if (c[i] && d[v] == d[u] + 1 && (f = dinic(v, min(c[i], low - s))))
        c[i] -= f, c[i ^ 1] += f, s += f;
    if (!s) d[u] = -1;
    return s;
  }
  int max_flow() {
    int res = 0;
    for (; bfs();) res += dinic(S, 1e9);
    return res;
  }
} G;
int N, M, K, a[20005];
void doit() {
  int ans = 0;
  scanf("%d%d%d", &N, &M, &K), G.set(0, N + M + 1);
  for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
  for (int i = 1, v; i <= N; i++)
    scanf("%d", &v), G.add(a[i] ? i : G.S, a[i] ? G.T : i, v);
  for (int i = 1, x, y, w, k; i <= M; i++) {
    scanf("%d%d%d", &x, &w, &k), ans += w;
    for (int j = 1, o; j <= k; j++)
      scanf("%d", &o), G.add(x ? o : i + N, x ? i + N : o, 1e9);
    scanf("%d", &y);
    if (x)
      G.add(i + N, G.T, w + y * K);
    else
      G.add(G.S, i + N, w + y * K);
  }
  printf("%d\n", ans - G.max_flow());
}
int main() {
  doit();
  return 0;
}
