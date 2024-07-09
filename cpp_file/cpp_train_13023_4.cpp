#include <bits/stdc++.h>
using namespace std;
int deg[4];
vector<int> e[4][4];
bool was[4];
int sum, min_val, cnt_node, cnt_deg;
void dfs(int u) {
  was[u] = true;
  cnt_deg += deg[u];
  cnt_node += 1;
  for (int c : e[u][u]) {
    sum += c;
  }
  for (int v = 0; v < 4; ++v) {
    if (!e[u][v].empty()) {
      if (u < v) {
        for (int c : e[u][v]) {
          sum += c;
          min_val = min(min_val, c);
        }
      }
      if (!was[v]) dfs(v);
    }
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int u, v, c;
    cin >> u >> c >> v;
    deg[--u] ^= 1;
    deg[--v] ^= 1;
    e[u][v].push_back(c);
    if (u != v) e[v][u].push_back(c);
  }
  int res = 0;
  for (int i = 0; i < 4; ++i)
    if (!was[i]) {
      sum = 0;
      min_val = 1e9;
      dfs(i);
      if (cnt_deg != 4) {
        res = max(res, sum);
      } else {
        res = max(res, sum - min_val);
      }
    }
  cout << res << endl;
  return 0;
}
