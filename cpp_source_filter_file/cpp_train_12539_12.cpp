#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9, PI = acos(-1.);
const long long LINF = 0x3f3f3f3f3f3f3f3f, LMOD = 1011112131415161719ll;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n, m, a, b;
int vis[N], pty[N], cur[N];
vector<int> adj[N], path;
int dfs(int v, int par) {
  if (vis[v]) return 0;
  vis[v] = 1;
  path.push_back(v);
  cur[v] ^= 1;
  for (auto u : adj[v])
    if (pty[v] or adj[u].size() > 1) {
      if (dfs(u, v)) {
        path.push_back(v);
        cur[v] ^= 1;
      }
    }
  if (pty[v] != cur[v]) {
    if (par) {
      path.push_back(par);
      cur[par] ^= 1;
      path.push_back(v);
      cur[v] ^= 1;
    } else {
      path.pop_back();
      cur[v] ^= 1;
    }
  }
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) scanf("%d", &pty[i]);
  for (int i = 1; i <= n; i++) {
    if (!vis[i] and pty[i]) {
      dfs(i, 0);
      break;
    }
  }
  int ok = 1;
  for (int i = 1; i <= n; i++)
    if (cur[i] != pty[i]) ok = 0;
  if (!ok)
    printf("-1\n");
  else {
    printf("%d\n", (int)path.size());
    if (path.size()) {
      for (auto k : path) printf("%d ", k);
      printf("\n");
    }
  }
  return 0;
}
