#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int to, cost, flow, cap, ind;
  Edge* ret;
  Edge() {}
  Edge(int to, int cap, int cost, int ind)
      : to(to), cap(cap), cost(cost), ind(ind), flow(0) {}
};
const int MX = 405, inf = 2000000;
int n1, n2, m, r, b, off, dis[MX], vis[MX], p[MX];
Edge* from[MX];
vector<Edge*> adj[MX];
string s1, s2, t;
void add(int u, int v, int cap, int cost, int ind) {
  Edge* uv = new Edge(v, cap, cost, ind);
  Edge* vu = new Edge(u, 0, -cost, ind);
  uv->ret = vu;
  vu->ret = uv;
  adj[u].push_back(uv);
  adj[v].push_back(vu);
}
void dijkstra(int s, int t) {
  vis[s] = 1;
  dis[s] = 0;
  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                 greater<pair<long long, long long>>>
      pq;
  pq.emplace(0, s);
  while (pq.size()) {
    int u = pq.top().second;
    int d = pq.top().first;
    pq.pop();
    if (d > dis[u]) continue;
    for (Edge* e : adj[u])
      if (e->flow < e->cap) {
        int w = d + e->cost;
        int v = e->to;
        if (!vis[v] || dis[v] > w) {
          vis[v] = 1;
          dis[v] = w;
          p[v] = u;
          from[v] = e;
          pq.emplace(w, v);
        }
      }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n1 >> n2 >> m >> r >> b >> s1 >> s2;
  for (int i = 0; i < n1; i++)
    if (s1[i] == 'R') {
      add(0, i + 1, 1, -inf, -1);
      add(0, i + 1, inf, 0, -1);
      off++;
    } else if (s1[i] == 'B') {
      add(i + 1, 404, 1, -inf, -1);
      add(i + 1, 404, inf, 0, -1);
      off++;
    } else {
      add(0, i + 1, inf, 0, -1);
      add(i + 1, 404, inf, 0, -1);
    }
  for (int i = 0; i < n2; i++)
    if (s2[i] == 'R') {
      add(n1 + i + 1, 404, 1, -inf, -1);
      add(n1 + i + 1, 404, inf, 0, -1);
      off++;
    } else if (s2[i] == 'B') {
      add(0, n1 + i + 1, 1, -inf, -1);
      add(0, n1 + i + 1, inf, 0, -1);
      off++;
    } else {
      add(i, n1 + i + 1, inf, 0, -1);
      add(n1 + i + 1, 404, inf, 0, -1);
    }
  t.assign(m, 'U');
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    add(u + 1, n1 + v + 1, 1, r, i);
    add(n1 + v + 1, u + 1, 1, b, i);
  }
  long long res = 0;
  while (1) {
    memset(vis, 0, sizeof(vis));
    dijkstra(0, 404);
    if (!vis[404] || dis[404] >= 0) break;
    res += dis[404];
    int u = 404;
    while (u) {
      Edge* e = from[u];
      e->flow++;
      e->ret->flow--;
      u = p[u];
    }
  }
  res += inf * off;
  if (res >= inf) {
    cout << -1 << '\n';
  } else {
    cout << res << '\n';
    for (int i = 1; i <= n1; i++)
      for (Edge* e : adj[i]) {
        if (e->cost == r && e->flow == 1) t[e->ind] = 'R';
        if (e->ret->cost == b && e->ret->flow == 1) t[e->ind] = 'B';
      }
    cout << t << '\n';
  }
  return 0;
}
