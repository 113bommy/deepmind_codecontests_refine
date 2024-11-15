#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 7;
const int MAX_V = 2e6 + 7;
int val[MAX_N];
int h[MAX_N];
vector<int> nei[MAX_N], f[MAX_N], st[MAX_V];
void factor(int n, int p) {
  f[p].clear();
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      f[p].push_back(i);
    }
  if (n > 1) f[p].push_back(n);
}
int ans[MAX_N];
void dfs(int v, int p = -1) {
  ans[v] = -1;
  for (int i = 0; i < ((int)(f[v]).size()); ++i) {
    int x = f[v][i];
    if (!st[x].empty() && (ans[v] == -1 || h[ans[v]] < h[st[x].back()]))
      ans[v] = st[x].back();
    st[x].push_back(v);
  }
  for (int i = 0; i < ((int)(nei[v]).size()); ++i) {
    int u = nei[v][i];
    if (u != p) dfs(u, v);
  }
  for (int i = 0; i < ((int)(f[v]).size()); ++i) {
    int x = f[v][i];
    st[x].pop_back();
  }
}
void pre(int v, int p = -1) {
  for (int i = 0; i < ((int)(nei[v]).size()); ++i) {
    int u = nei[v][i];
    if (u != p) {
      h[u] = h[v] + 1;
      pre(u, v);
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    cin >> val[i];
    factor(val[i], i);
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    nei[u].push_back(v);
    nei[v].push_back(u);
  }
  pre(0);
  dfs(0);
  while (q--) {
    int op, v;
    cin >> op >> v;
    --v;
    if (op == 1)
      cout << (ans[v] == -1 ? -1 : ans[v] + 1) << '\n';
    else {
      cin >> val[v];
      factor(val[v], v);
      dfs(0);
    }
  }
  return 0;
}
