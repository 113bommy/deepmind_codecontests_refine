#include <bits/stdc++.h>
using namespace std;
const int maxn = 5 * 1000 + 10, inf = 30000000;
int ans = -1, sum, na, n, m, dp[maxn][maxn], u, v, k, je[maxn], a[maxn],
    b[maxn], c[maxn];
vector<int> vec[maxn], ca[maxn];
int main() {
  cin >> n >> m >> k;
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--;
    v--;
    vec[v].push_back(u);
  }
  for (int i = n - 1; i >= 0; i--) {
    je[i] = i;
    for (auto w : vec[i]) je[i] = max(je[i], w);
    ca[je[i]].push_back(c[i]);
  }
  for (int i = 0; i < n; i++) sort(ca[i].begin(), ca[i].end());
  for (int i = 0; i < maxn; i++) {
    if (i == k) continue;
    dp[0][i] = -inf;
  }
  dp[0][k] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < maxn; j++) {
      if (j < a[i] || dp[i][j] < 0) continue;
      na = min(maxn - 1, j + b[i]);
      sum = 0;
      for (int l = 0; l <= min(na, (((int)ca[i].size()))); l++) {
        dp[i + 1][na - l] = max(dp[i + 1][na - l], dp[i][j] + sum);
        if (l < (((int)ca[i].size())))
          sum += ca[i][(((int)ca[i].size())) - l - 1];
      }
    }
  }
  for (int i = 0; i < maxn; i++) ans = max(ans, dp[n][i]);
  if (ans < 0)
    cout << -1;
  else
    cout << ans;
  return 0;
}
