#include <bits/stdc++.h>
using namespace std;
struct edge {
  int f, t;
  long long cap;
} E[2000005];
vector<int> adj[20005];
queue<int> q;
int path[20005];
int S, T, N;
void add_edge(int u, int v, long long cap) {
  E[N].f = u, E[N].t = v, E[N].cap = cap;
  adj[u].push_back(N), N++;
  E[N].f = v, E[N].t = u, E[N].cap = 0;
  adj[v].push_back(N), N++;
}
bool find() {
  while (q.size()) q.pop();
  memset(path, -1, sizeof(path));
  path[S] = -2, q.push(S);
  while (q.size()) {
    int u = q.front();
    q.pop();
    if (u == T) return 1;
    for (int i = 0; i < adj[u].size(); ++i) {
      int v = E[adj[u][i]].t;
      if (E[adj[u][i]].cap > 0 && path[v] == -1) path[v] = adj[u][i], q.push(v);
    }
  }
  return 0;
}
long long flow() {
  long long ret = 0;
  while (find()) {
    long long bot = 1ll << 60;
    int u = T;
    while (path[u] >= 0) {
      bot = min(bot, E[path[u]].cap);
      u = E[path[u]].f;
    }
    u = T;
    while (path[u] >= 0) {
      E[path[u]].cap -= bot;
      E[path[u] ^ 1].cap += bot;
      u = E[path[u]].f;
    }
    ret += bot;
  }
  return ret;
}
int n, m;
int a[55], b[55], c[55];
int L[55], R[55];
int pad = 110;
int node(int u, int x) { return u * pad * 2 + x + pad; }
int main() {
  S = 18000, T = 19000;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d%d%d", a + i, b + i, c + i);
  for (int i = 0; i < n; ++i) scanf("%d%d", L + i, R + i);
  for (int u = 0; u < n; ++u) {
    add_edge(S, node(u, L[u] - 1), (1ll << 50));
    for (int x = L[u] - 1; x < R[u]; ++x)
      add_edge(
          node(u, x), node(u, x + 1),
          (1ll << 20) - (a[u] * (x + 1) * (x + 1) + b[u] * (x + 1) + c[u]));
    add_edge(node(u, R[u]), T, (1ll << 50));
  }
  for (int z = 0; z < m; ++z) {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d), u--, v--;
    for (int x = L[u]; x <= R[u]; ++x)
      if (L[v] <= x - d && x - d <= R[v])
        add_edge(node(u, x), node(v, x - d), (1ll << 50));
  }
  long long f = flow();
  cout << (1ll << 20) * n - f << endl;
}
