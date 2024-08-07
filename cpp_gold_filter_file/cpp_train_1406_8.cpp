#include <bits/stdc++.h>
using namespace std;
int n, a, b, r = -1, l;
vector<int> G[5007];
int dp[5007][5007];
bitset<5007> vis;
int sub[5007];
int bef[5007];
void dfs(int v) {
  vis[v] = 1;
  memset(dp[v], 0x3f3f3f3f, sizeof dp[v]);
  if (G[v].size() == 1) {
    sub[v] = 1;
    dp[v][1] = 0;
  } else
    dp[v][0] = 0;
  for (auto it : G[v]) {
    if (!vis[it]) {
      dfs(it);
      memset(bef, 0x3f3f3f3f, sizeof bef);
      for (int j = 0; j <= sub[v]; ++j) {
        bef[j] = dp[v][j];
      }
      memset(dp[v], 0x3f3f3f3f, sizeof dp[v]);
      for (int j = 0; j <= sub[v]; ++j) {
        for (int k = 0; k <= sub[it]; ++k) {
          dp[v][j + k] = min(dp[v][j + k], bef[j] + dp[it][k]);
          dp[v][j + k] = min(dp[v][j + k], bef[j + k] + 1);
          dp[v][j + k] = min(dp[v][j + k], bef[j] + dp[it][sub[it] - k] + 1);
        }
      }
      sub[v] += sub[it];
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i) {
    if (G[i].size() != 1)
      r = i;
    else
      ++l;
  }
  if (r == -1) {
    cout << 1;
    return 0;
  }
  dfs(r);
  cout << dp[r][l / 2];
}
