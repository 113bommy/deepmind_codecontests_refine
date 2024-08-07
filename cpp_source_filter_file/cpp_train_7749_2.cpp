#include <bits/stdc++.h>
using namespace std;
const int maxn = 402;
vector<int> e[maxn];
int dp[maxn][maxn], path[maxn][maxn][maxn], id[maxn][maxn], fa[maxn], n;
void dfs(int u, int pre) {
  fa[u] = pre;
  dp[u][1] = 0;
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i];
    if (v == pre) continue;
    dfs(v, u);
    for (int j = n; j >= 0; j--) {
      dp[u][j]++;
      for (int l = 0; l <= j; l++)
        if (dp[u][j] >= dp[u][j - l] + dp[v][l])
          dp[u][j] = dp[u][j - l] + dp[v][l], path[u][v][j] = l;
    }
  }
}
void out(int u, int k, int pre) {
  int t = k;
  for (int i = e[u].size() - 1; i >= 0; i--) {
    int v = e[u][i];
    if (v == pre) continue;
    if (path[u][v][t] == 0)
      cout << id[u][v] << ' ';
    else {
      out(v, path[u][v][t], u);
      t -= path[u][v][t];
    }
  }
}
int main() {
  int k;
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
    id[u][v] = id[v][u] = i;
  }
  memset(dp, 0x11, sizeof(dp));
  dfs(1, 0);
  int ans = dp[1][k], root = 1;
  for (int i = 2; i <= n; i++)
    if (dp[i][k] + 1 < ans) ans = dp[i][k] + 1, root = i;
  cout << ans << endl;
  if (root != 1) cout << id[root][fa[root]];
  out(root, k, fa[root]);
  return 0;
}
