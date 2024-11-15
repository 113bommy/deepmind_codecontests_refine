#include <bits/stdc++.h>
using namespace std;
int n, m;
struct edge {
  int u, v, nxt, t;
} edges[600008];
int nedge;
int head[300008];
int dfn[300008], low[300008];
int dp[300008];
int cnt;
bool ans;
int a, b;
void add_edge(int u, int v, int t) {
  edges[nedge].u = u;
  edges[nedge].v = v;
  edges[nedge].t = t;
  edges[nedge].nxt = head[u];
  head[u] = nedge++;
}
void tarjan(int u, int fa) {
  dfn[u] = low[u] = ++cnt;
  if (u == b) dp[u] |= 2;
  for (int i = head[u]; i != -1; i = edges[i].nxt) {
    int v = edges[i].v;
    int t = edges[i].t;
    if (v == fa) continue;
    if (dfn[v] != -1) {
      low[u] = min(low[u], dfn[v]);
      dfn[u] |= dfn[v];
      dp[u] |= t;
    } else {
      tarjan(v, u);
      if (ans) return;
      if (dfn[u] >= low[v]) {
        low[u] = min(low[u], low[v]);
        dp[u] |= t;
        dp[u] |= dp[v];
      }
      if (dp[v] >= 2) {
        dp[u] |= 2;
      }
      if (t && dp[v] >= 2) {
        dp[u] = 3;
      }
    }
  }
  if (dp[u] >= 3) {
    ans = 1;
    return;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  memset(head, -1, sizeof head);
  memset(dfn, -1, sizeof dfn);
  memset(low, -1, sizeof low);
  memset(dp, 0, sizeof dp);
  cnt = 0;
  nedge = 0;
  ans = 0;
  int u, v, t;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &u, &v, &t);
    add_edge(u, v, t);
    add_edge(v, u, t);
  }
  scanf("%d %d", &a, &b);
  tarjan(a, -1);
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
