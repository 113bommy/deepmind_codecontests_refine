#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 100 + 10;
int n;
long long a[N], ans, d[N], dia[N], up[N], upd[N];
vector<int> adj[N], cld[N];
struct DS {
  long long mx[5];
  DS() { fill(mx, mx + 5, 0); }
  void insert(long long x, int ind) {
    for (int i = 4; i > ind; i--) swap(mx[i], mx[i - 1]);
    mx[ind] = x;
  }
  void add(long long x) {
    for (int i = 0; i < 5; i++)
      if (mx[i] <= x) {
        insert(x, i);
        return;
      }
  }
  long long b() { return mx[0]; }
  long long bb() { return mx[1]; }
  void clear() { *this = DS(); }
};
void dfs_down(int v, int par = -1) {
  d[v] = dia[v] = a[v];
  for (auto u : adj[v])
    if (u != par) {
      cld[v].push_back(u);
      dfs_down(u, v);
      dia[v] = max({dia[v], dia[u], d[v] + d[u]});
      d[v] = max(d[v], d[u] + a[v]);
    }
}
void dfs_up(int v) {
  DS all;
  for (auto u : cld[v]) all.add(dia[u]);
  for (auto u : cld[v]) {
    up[u] = max(up[u], up[v]);
    if (dia[u] != all.b()) up[u] = max(up[u], all.b());
    up[u] = max(up[u], all.bb());
    up[u] = max(up[u], upd[v]);
    upd[u] = max(upd[u], upd[v] + a[v]);
  }
  all.clear();
  for (auto u : cld[v]) {
    all.add(d[u]);
  }
  for (auto u : cld[v]) {
    if (d[u] != all.b()) {
      up[u] = max(up[u], all.b() + a[v] + upd[v]);
      upd[u] = max(upd[u], all.b() + a[v]);
    }
    up[u] = max(up[u], all.bb() + a[v] + upd[v]);
    upd[u] = max(upd[u], all.bb() + a[v]);
  }
  for (auto u : cld[v]) {
    long long res = 0;
    int cnt = 0;
    bool flag = true;
    for (int i = 0; i < 4; i++)
      if (cnt < 2) {
        if (all.mx[i] == d[u] && flag) {
          flag = false;
          continue;
        }
        res += all.mx[i], cnt++;
      }
    res += a[v];
    up[u] = max(up[u], res);
  }
  for (auto u : cld[v]) dfs_up(u);
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1, v, u; i < n; i++) {
    cin >> v >> u;
    --v, --u;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  dfs_down(0), dfs_up(0);
  long long ans = 0;
  for (int i = 0; i < n; i++) ans = max(ans, dia[i] + up[i]);
  cout << ans << '\n';
  return 0;
}
