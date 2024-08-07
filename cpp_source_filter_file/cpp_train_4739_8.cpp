#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
vector<int> g[maxn], w[maxn];
int ans, m, dis[maxn], n, v, u, d;
bool mark[maxn];
void dfs(int v) {
  mark[v] = true;
  for (int i = 0; i < g[v].size(); i++)
    if (mark[g[v][i]] == false) {
      dis[g[v][i]] = dis[v] + w[v][i];
      dfs(g[v][i]);
    }
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> v >> u >> d;
    g[v].push_back(u);
    g[u].push_back(v);
    w[u].push_back(d);
    w[v].push_back(d);
    ans += (2 * d);
  }
  dis[1] = 0;
  dfs(1);
  for (int i = 2; i <= n; i++)
    if (g[i].size() == 1 && dis[i] > m) m = dis[i];
  cout << ans - m << endl;
  return 0;
}
