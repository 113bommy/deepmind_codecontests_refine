#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const int NN = 20005;
bool Prime[NN];
int n, s, t, tot, a[N];
bool dp[N];
int head[N], edge_id = 1;
struct node {
  int to, val, next;
} e[N * N * 2];
void add_edge(int u, int v, int val) {
  ++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, e[edge_id].val = val,
             head[u] = edge_id;
}
void add(int u, int v, int val) { add_edge(u, v, val), add_edge(v, u, 0); }
int dep[N], las[N];
bool bfs() {
  fill(dep + 1, dep + tot + 1, 1e9);
  queue<int> q;
  q.push(s), dep[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].to;
      if (dep[v] == 1e9 && e[i].val) dep[v] = dep[u] + 1, las[v] = i, q.push(v);
    }
  }
  return dep[t] < (int)(1e9);
}
int EK() {
  int res = 0;
  while (bfs()) {
    int minn = 1e9;
    for (int i = t; i != s; i = e[las[i] ^ 1].to)
      minn = min(minn, e[las[i]].val);
    for (int i = t; i != s; i = e[las[i] ^ 1].to)
      e[las[i]].val -= minn, e[las[i] ^ 1].val += minn;
    res += minn;
  }
  return res;
}
int to[N][2], len[N], stot;
bool vis[N];
vector<int> ve[N];
void dfs(int x) {
  ve[stot].push_back(x), vis[x] = 1;
  if (!vis[to[x][0]]) return (void)(dfs(to[x][0]));
  if (!vis[to[x][1]]) return (void)(dfs(to[x][1]));
}
int main() {
  scanf("%d", &n), tot = n;
  s = ++tot, t = ++tot;
  for (int i = 2; i <= 20000; i++)
    for (int j = 2; j <= 20000 / i; j++) Prime[i * j] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] % 2 == 1)
      add(s, i, 2);
    else
      add(i, t, 2);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (!Prime[a[i] + a[j]] && a[i] % 2 == 1 && a[j] % 2 == 0) add(i, j, 1);
  int ans = EK();
  if (ans != n) return printf("Impossible\n"), 0;
  for (int x = 1; x <= n; x++)
    if (a[x] % 2)
      for (int i = head[x]; i; i = e[i].next)
        if (e[i].to <= n && !e[i].val)
          to[x][len[x]++] = e[i].to, to[e[i].to][len[e[i].to]++] = x;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) ++stot, dfs(i);
  printf("%d\n", stot);
  for (int i = 1; i <= stot; i++) {
    printf("%d ", (int)(ve[i].size()));
    for (int x : ve[i]) printf("%d ", x);
    puts("");
  }
  return 0;
}
