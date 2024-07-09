#include <bits/stdc++.h>
using namespace std;
const int N = 6666;
const int INF = 0x77777777;
struct MCMF {
  struct Edge {
    int u, v, c, f, co, nx;
    Edge() {}
    Edge(int u, int v, int c, int f, int co, int nx)
        : u(u), v(v), c(c), f(f), co(co), nx(nx) {}
  } edge[N << 2];
  int dis[N], eh[N], ec;
  void init() {
    memset(eh, -1, sizeof(eh));
    ec = 0;
  }
  void addedge(int u, int v, int f, int c) {
    edge[ec] = Edge(u, v, f, 0, c, eh[u]);
    eh[u] = ec++;
    edge[ec] = Edge(v, u, 0, 0, -c, eh[v]);
    eh[v] = ec++;
  }
  int s, t, cost, pre[N];
  bool conf[N];
  int bfs() {
    priority_queue<pair<int, int> > pq;
    memset(dis, 0x77, sizeof(dis));
    memset(conf, 0, sizeof(conf));
    pq.push(pair<int, int>(0, s));
    dis[s] = 0;
    int mf = INF;
    bool nf = true;
    while (pq.size() && nf) {
      int u = pq.top().second;
      pq.pop();
      if (conf[u]) continue;
      conf[u] = true;
      for (int i = eh[u]; ~i && nf; i = edge[i].nx) {
        Edge &e = edge[i];
        int v = e.v, df = e.c - e.f, co = e.co;
        if (df <= 0) continue;
        mf = min(mf, df);
        if (dis[v] > dis[u] + co) {
          dis[v] = dis[u] + co;
          pre[v] = i;
          if (v == t) nf = false;
          pq.push(pair<int, int>(-dis[v], v));
        }
      }
    }
    if (dis[t] == INF) return false;
    cost += dis[t] * mf;
    for (int u = t; u != s; u = edge[pre[u]].u) {
      int p = pre[u];
      edge[p].f += mf;
      edge[p ^ 1].f -= mf;
    }
    return true;
  }
  int cal(int S, int T) {
    s = S, t = T;
    cost = 0;
    while (bfs())
      ;
    return cost;
  }
} mxf;
const int M = 88;
int mat[M][M];
int n, m;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
inline bool inmat(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }
int main() {
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) scanf("%d", mat[i] + j);
    }
    mxf.init();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int id = i * m + j;
        if (i + j & 1) {
          mxf.addedge(n * m, id, 1, 0);
          for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (!inmat(ni, nj)) continue;
            int nid = ni * m + nj;
            mxf.addedge(id, nid, 1, mat[i][j] != mat[ni][nj]);
          }
        } else
          mxf.addedge(id, n * m + 1, 1, 0);
      }
    }
    cout << mxf.cal(n * m, n * m + 1) << endl;
  }
  return 0;
}
