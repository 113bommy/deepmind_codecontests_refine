#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-8;
const double PI = acos(-1);
template <class T, class S>
inline void add(T& a, S b) {
  a += b;
  if (a >= mod) a -= mod;
}
template <class T, class S>
inline void sub(T& a, S b) {
  a -= b;
  if (a < 0) a += mod;
}
template <class T, class S>
inline bool chkmax(T& a, S b) {
  return a < b ? a = b, true : false;
}
template <class T, class S>
inline bool chkmin(T& a, S b) {
  return a > b ? a = b, true : false;
}
int n, m, q;
int in[N], ot[N], idx;
int pa[N][20], depth[N];
int go[N][20];
int ans[N];
vector<int> G[N];
vector<int> seg[N];
vector<pair<int, int> > qus[N];
struct BIT {
  int a[N];
  void modify(int x, int v) {
    for (int i = x; i < N; i += i & -i) a[i] += v;
  }
  int sum(int x) {
    int ans = 0;
    for (int i = x; i; i -= i & -i) ans += a[i];
    return ans;
  }
  int query(int L, int R) {
    if (L > R) return 0;
    return sum(R) - sum(L - 1);
  }
} bit;
void dfs(int u, int fa) {
  depth[u] = depth[fa] + 1;
  pa[u][0] = fa;
  in[u] = ++idx;
  for (int i = 1; i < 20; i++) pa[u][i] = pa[pa[u][i - 1]][i - 1];
  for (auto& v : G[u]) {
    if (v == fa) continue;
    dfs(v, u);
  }
  ot[u] = idx;
}
int getLca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int dis = depth[u] - depth[v];
  for (int i = 19; i >= 0; i--)
    if (dis >> i & 1) u = pa[u][i];
  if (u == v) return u;
  for (int i = 19; i >= 0; i--)
    if (pa[u][i] != pa[v][i]) u = pa[u][i], v = pa[v][i];
  return pa[u][0];
}
void dfs2(int u, int fa) {
  for (auto& v : G[u]) {
    if (v == fa) continue;
    dfs2(v, u);
    if (depth[go[v][0]] < depth[go[u][0]]) {
      go[u][0] = go[v][0];
    }
  }
}
void dfs3(int u, int fa) {
  vector<int> preVal(((int)qus[u].size()));
  for (int i = 0; i < ((int)qus[u].size()); i++)
    preVal[i] = bit.query(in[qus[u][i].first], ot[qus[u][i].first]);
  for (auto& v : seg[u]) bit.modify(in[v], 1);
  for (auto& v : G[u]) {
    if (v == fa) continue;
    dfs3(v, u);
  }
  for (int i = 0; i < ((int)qus[u].size()); i++) {
    if (bit.query(in[qus[u][i].first], ot[qus[u][i].first]) == preVal[i])
      ans[qus[u][i].second] += 2;
    else
      ans[qus[u][i].second]++;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) go[i][0] = i;
  for (int i = 2; i <= n; i++) {
    int fa;
    scanf("%d", &fa);
    G[fa].push_back(i);
  }
  dfs(1, 0);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    int lca = getLca(u, v);
    if (depth[lca] < depth[go[u][0]]) go[u][0] = lca;
    if (depth[lca] < depth[go[v][0]]) go[v][0] = lca;
    seg[u].push_back(v);
    seg[v].push_back(u);
  }
  dfs2(1, 0);
  for (int j = 1; j < 20; j++)
    for (int i = 1; i <= n; i++) go[i][j] = go[go[i][j - 1]][j - 1];
  scanf("%d", &q);
  for (int o = 1; o <= q; o++) {
    int u, v;
    scanf("%d%d", &u, &v);
    int lca = getLca(u, v);
    if (lca == u) {
      for (int i = 19; i >= 0; i--)
        if (depth[go[v][i]] > depth[lca]) v = go[v][i], ans[o] += 1 << i;
      if (depth[go[v][0]] > depth[lca])
        ans[o] = -1;
      else
        ans[o]++;
    } else if (lca == v) {
      for (int i = 19; i >= 0; i--)
        if (depth[go[u][i]] > depth[lca]) u = go[u][i], ans[o] += 1 << i;
      if (depth[go[u][0]] > depth[lca])
        ans[o] = -1;
      else
        ans[o]++;
    } else {
      for (int i = 19; i >= 0; i--)
        if (depth[go[v][i]] > depth[lca]) v = go[v][i], ans[o] += 1 << i;
      for (int i = 19; i >= 0; i--) {
        if (depth[go[u][i]] > depth[lca]) {
          u = go[u][i], ans[o] += 1 << i;
        }
      }
      if (depth[go[u][0]] > depth[lca] || depth[go[v][0]] > depth[lca])
        ans[o] = -1;
      else
        qus[u].push_back(make_pair(v, o));
    }
  }
  dfs3(1, 0);
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
