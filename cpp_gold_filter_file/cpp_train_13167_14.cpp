#include <bits/stdc++.h>
using namespace std;
const int N = 300100;
int head[N], tot;
struct edge {
  int v, nx, d;
  edge(int v = 0, int nx = 0, int d = 0) : v(v), nx(nx), d(d) {}
} e[N * 2];
void add(int u, int v, int d) {
  e[tot] = edge(v, head[u], d);
  head[u] = tot++;
}
struct data {
  long long len;
  int id, u;
  data() {}
  data(long long len, int id, int u) : len(len), id(id), u(u) {}
  bool operator<(data a) const {
    return a.len < len || (a.len == len && e[a.id].d < e[id].d);
  }
};
const long long INF = 1LL << 60;
long long d[N];
int vis[N], n, m, res[N * 2];
void dij(int u) {
  priority_queue<data> q;
  for (int i = 1; i <= n; i++) d[i] = INF;
  memset(vis, 0, sizeof vis);
  d[u] = 0;
  long long ans = 0;
  q.push(data(0, -1, u));
  while (!q.empty()) {
    data x = q.top();
    q.pop();
    int id = x.id, u = x.u;
    if (vis[u]) continue;
    if (id >= 0) {
      res[id] = 1;
      ans += e[id].d;
    }
    vis[u] = 1;
    for (int i = head[u]; ~i; i = e[i].nx) {
      int v = e[i].v;
      if (d[v] >= d[u] + e[i].d) {
        d[v] = d[u] + e[i].d;
        q.push(data(d[v], i, v));
      }
    }
  }
  cout << ans << endl;
  for (int i = 0; i < 2 * m; i++) {
    if (res[i]) printf("%d ", i / 2 + 1);
  }
}
int main() {
  cin >> n >> m;
  memset(head, -1, sizeof head);
  tot = 0;
  int u, v, d;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &u, &v, &d);
    add(u, v, d);
    add(v, u, d);
  }
  cin >> u;
  dij(u);
}
