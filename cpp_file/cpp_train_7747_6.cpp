#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int oo = 0x3f;
int n[4], d[4], chl[100010][4], l, r;
long long a[100010][4], ma[4], h[100010][4], ans = 0, res = 0, dp[100010][4];
vector<int> g[100010][4];
void init(int id, int u, int p) {
  chl[u][id] = 1;
  for (auto v : g[u][id])
    if (v != p) {
      h[v][id] = h[u][id] + 1;
      init(id, v, u);
      chl[u][id] += chl[v][id];
      d[id] += chl[v][id];
    }
}
void cal(int id, int u, int p, long long x) {
  ans += x;
  a[u][id] = x;
  ma[id] = max(ma[id], x);
  for (auto v : g[u][id])
    if (v != p) cal(id, v, u, x + n[id] - 2 * chl[v][id]);
}
void readf() {
  cin >> n[1] >> n[2] >> n[3];
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j < n[i]; ++j) {
      int u, v;
      cin >> u >> v;
      g[u][i].push_back(v);
      g[v][i].push_back(u);
    }
  }
}
void DFS(int id, int u, int p) {
  for (auto v : g[u][id])
    if (v != p) DFS(id, v, u);
  dp[u][0] = a[u][id] * n[l] + n[l] * n[r] * h[u][id];
  dp[u][1] = a[u][id] * n[r] + n[l] * n[r] * h[u][id];
  long long x, y;
  x = n[id] * (n[l] + n[r]) + n[l] * n[r] * 2 + ma[l] * (n[id] + n[r]) +
      ma[r] * (n[id] + n[l]);
  y = h[u][id] * n[l] * n[r];
  for (auto v : g[u][id])
    if (v != p) {
      res = max(res, x - y * 2 + max(dp[u][0] + dp[v][1], dp[u][1] + dp[v][0]));
      dp[u][0] = max(dp[u][0], dp[v][0]);
      dp[u][1] = max(dp[u][1], dp[v][1]);
    }
  res = max(res, x - y * 2 + a[u][id] * (n[l] + n[r]));
}
void solve() {
  for (int i = 1; i <= 3; ++i) init(i, 1, 0);
  for (int i = 1; i <= 3; ++i) cal(i, 1, 0, d[i]);
  for (int i = 1; i <= 3; ++i) {
    l = (i + 2) % 4, r = (i + 1) % 4;
    l += (l <= i);
    r += (r <= i);
    DFS(i, 1, 0);
  }
  cout << res + ans / 2;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  readf();
  solve();
}
