#include <bits/stdc++.h>
using namespace std;
const int MX = 5005, inf = 1e9;
struct FlowGraph {
  struct Edge {
    int to;
    int flow, cap, cost;
    Edge *res;
    Edge() : to(0), flow(0), cap(0), cost(0), res(0) {}
    Edge(int to, int flow, int cap, int cost)
        : to(to), flow(flow), cap(cap), cost(cost), res(0) {}
    void addFlow(int f) {
      flow += f;
      res->flow -= f;
    }
  };
  vector<vector<Edge *>> adj;
  vector<int> dis, pos;
  int n;
  FlowGraph(int n) : n(n), adj(n), dis(n), pos(n) {}
  void add(int u, int v, int cap, int cost) {
    Edge *x = new Edge(v, 0, cap, cost);
    Edge *y = new Edge(u, cap, cap, -cost);
    x->res = y;
    y->res = x;
    adj[u].push_back(x);
    adj[v].push_back(y);
  }
  pair<int, int> maxFlowMinCost(int s, int t) {
    vector<bool> inQueue(n);
    vector<int> dis(n), cap(n);
    vector<Edge *> par(n);
    int maxFlow = 0, minCost = 0;
    while (1) {
      fill(dis.begin(), dis.end(), inf);
      fill(par.begin(), par.end(), nullptr);
      fill(cap.begin(), cap.end(), 0);
      dis[s] = 0;
      cap[s] = inf;
      queue<int> q;
      q.push(s);
      while (q.size()) {
        int u = q.front();
        q.pop();
        inQueue[u] = 0;
        for (Edge *v : adj[u]) {
          if (v->cap > v->flow && dis[v->to] > dis[u] + v->cost) {
            dis[v->to] = dis[u] + v->cost;
            par[v->to] = v;
            cap[v->to] = min(cap[u], v->cap - v->flow);
            if (!inQueue[v->to]) {
              q.push(v->to);
              inQueue[v->to] = 1;
            }
          }
        }
      }
      if (!par[t]) break;
      maxFlow += cap[t];
      minCost += cap[t] * dis[t];
      for (int u = t; u != s; u = par[u]->res->to) par[u]->addFlow(cap[t]);
    }
    return {maxFlow, minCost};
  }
};
int n, x, y, u, v, q, a[MX];
int p[2][MX], d[2][MX], sz[2][MX], sig[2][MX];
vector<int> adj[2][MX];
void no() {
  cout << -1 << '\n';
  exit(0);
}
void dfs(int u, int j) {
  for (int v : adj[j][u])
    if (v != p[j][u]) {
      p[j][v] = u;
      dfs(v, j);
    }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(d, -1, sizeof(d));
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    adj[0][u].push_back(v);
    adj[0][v].push_back(u);
  }
  for (int i = 1; i < n; i++) {
    cin >> u >> v;
    adj[1][u].push_back(v);
    adj[1][v].push_back(u);
  }
  cin >> q;
  while (q--) {
    cin >> u >> v;
    d[0][u] = v;
  }
  cin >> q;
  while (q--) {
    cin >> u >> v;
    d[1][u] = v;
  }
  p[0][x] = -1;
  dfs(x, 0);
  p[1][y] = -1;
  dfs(y, 1);
  for (int j = 0; j < 2; j++)
    for (int i = 1; i <= n; i++) {
      int u = i;
      while (d[j][u] == -1) u = p[j][u];
      sig[j][i] = u;
      if (d[j][i] != -1) {
        sz[j][i] += d[j][i];
        if (p[j][u] != -1) {
          u = p[j][u];
          while (d[j][u] == -1) u = p[j][u];
          sz[j][u] -= d[j][i];
        }
      }
    }
  FlowGraph fg(2 * n + 5);
  int s = 0, t = 2 * n + 4;
  for (int i = 1; i <= n; i++) {
    if (d[0][i] != -1) {
      if (sz[0][i] < 0) no();
      fg.add(s, i, sz[0][i], 0);
    }
    if (d[1][i] != -1) {
      if (sz[1][i] < 0) no();
      fg.add(n + i, t, sz[1][i], 0);
    }
    fg.add(sig[0][i], n + sig[1][i], 1, -a[i]);
  }
  pair<int, int> res = fg.maxFlowMinCost(s, t);
  if (res.first != d[0][x] || res.first != d[1][y]) no();
  cout << -res.second << '\n';
  return 0;
}
