#include <bits/stdc++.h>
using namespace std;
int res[100001];
int dp[1000001];
int n, m, k, i, j, a, b;
vector<pair<int, int> > g[100001];
int dfs(int v) {
  if (dp[v]) return dp[v];
  dp[v] = 1;
  for (int j = 0; j < g[v].size(); j++)
    if (dfs(g[v][j].first) + 1 > dp[v]) {
      dp[v] = dp[g[v][j].first] + 1;
      res[v] = max(res[g[v][j].first], g[v][j].second);
    }
  return dp[v];
}
int main() {
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> a >> b;
    g[a].push_back(make_pair(b, i));
  }
  for (i = 1; i <= n; i++)
    if (dfs(i) == n) {
      cout << res[i];
      return 0;
    }
  cout << -1;
  return 0;
}
