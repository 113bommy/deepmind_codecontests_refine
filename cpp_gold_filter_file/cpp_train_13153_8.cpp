#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
class edge {
 public:
  int e, nxt, cap;
  edge(int e1 = -1, int nxt1 = -1, int cap1 = 0) {
    e = e1, nxt = nxt1, cap = cap1;
  }
};
int S, T, n, m, K, t, ss, tt;
int dep[410], degl[410], degr[410];
bool vis[410];
int id[210][210];
class graph {
 public:
  edge g[100000];
  int head[410], tmpcnt;
  int cur[410];
  void init() {
    memset(head, 255, sizeof(head));
    tmpcnt = 0;
  }
  void addedge(int s, int e, int cap) {
    if (cap == 0) return;
    g[tmpcnt] = edge(e, head[s], cap), head[s] = tmpcnt++;
    g[tmpcnt] = edge(s, head[e], 0), head[e] = tmpcnt++;
  }
  bool bfs() {
    memset(vis, 0, sizeof(vis));
    memset(dep, 0, sizeof(dep));
    queue<int> q;
    q.push(S);
    vis[S] = 1;
    while (!q.empty()) {
      int fr = q.front();
      q.pop();
      for (int i = head[fr]; i != -1; i = g[i].nxt) {
        if (g[i].cap > 0 && !vis[g[i].e]) {
          dep[g[i].e] = dep[fr] + 1;
          vis[g[i].e] = 1;
          q.push(g[i].e);
        }
      }
    }
    return vis[T];
  }
  int dfs(int np, int maxflow) {
    int f;
    int flow = 0;
    if (np == T || !maxflow) return maxflow;
    for (int i = cur[np]; i != -1; i = g[i].nxt) {
      cur[np] = i;
      if (g[i].cap > 0 && dep[g[i].e] == dep[np] + 1 &&
          (f = dfs(g[i].e, min(g[i].cap, maxflow))) > 0) {
        g[i].cap -= f;
        g[i ^ 1].cap += f;
        flow += f;
        maxflow -= f;
        if (!maxflow) break;
      }
    }
    return flow;
  }
  int dinic() {
    int out = 0;
    while (bfs()) memcpy(cur, head, sizeof(cur)), out += dfs(S, INF);
    return out;
  }
} G;
int st[5010], ed[5010], ans[5010], cntl[210], cntr[210];
int main() {
  scanf("%d%d%d%d", &n, &m, &K, &t);
  G.init();
  for (int i = 1; i <= K; i++) {
    scanf("%d%d", &st[i], &ed[i]);
    degl[st[i]]++;
    degr[ed[i]]++;
    id[st[i]][ed[i]] = i;
    G.addedge(st[i], ed[i] + n, 1);
  }
  int ret = 0, basL = 0, basR = 0;
  for (int i = 1; i <= n; i++) ret += (degl[i] % t != 0), basL += degl[i] / t;
  for (int i = 1; i <= m; i++) ret += (degr[i] % t != 0), basR += degr[i] / t;
  printf("%d\n", ret);
  S = n + m + 1;
  T = n + m + 2;
  ss = n + m + 3;
  tt = n + m + 4;
  for (int i = t; i >= 1; i--) {
    G.init();
    for (int j = 1; j <= K; j++)
      if (!ans[j]) G.addedge(st[j], ed[j] + n, 1);
    for (int j = 1; j <= n; j++) {
      G.addedge(S, j, degl[j] / i);
      G.addedge(ss, T, degl[j] / i);
      if (degl[j] % i) G.addedge(ss, j, 1);
    }
    for (int j = 1; j <= m; j++) {
      G.addedge(S, tt, degr[j] / i);
      G.addedge(j + n, T, degr[j] / i);
      if (degr[j] % i) G.addedge(j + n, tt, 1);
    }
    G.addedge(tt, ss, INF);
    G.dinic();
    for (int j = 1; j <= n; j++) {
      for (int k = G.head[j]; k != -1; k = G.g[k].nxt) {
        int v = G.g[k].e;
        if (v > n && v <= n + m) {
          if (!G.g[k].cap && !ans[id[j][v - n]])
            ans[id[j][v - n]] = i, degl[j]--, degr[v - n]--;
        }
      }
    }
  }
  for (int i = 1; i <= K; i++) printf("%d ", ans[i]);
  return 0;
}
