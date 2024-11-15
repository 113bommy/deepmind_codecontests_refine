#include <bits/stdc++.h>
using namespace std;
int n;
long long x[1 << 20], y[1 << 20];
int nex[1 << 20];
int st[1 << 20], stop;
int par[1 << 20][20];
int l;
vector<vector<int> > g;
vector<int> tin, tout;
int timer;
vector<vector<int> > up;
void dfs(int v, int p = 0) {
  tin[v] = ++timer;
  up[v][0] = p;
  for (int i = 1; i <= l; ++i) {
    up[v][i] = up[up[v][i - 1]][i - 1];
  }
  for (size_t i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (to != p) dfs(to, v);
  }
  tout[v] = ++timer;
}
bool upper(int a, int b) { return tin[a] <= tin[b] && tout[a] >= tout[b]; }
int lca(int a, int b) {
  if (upper(a, b)) return a;
  if (upper(b, a)) return b;
  for (int i = l; i >= 0; --i)
    if (!upper(up[a][i], b)) a = up[a][i];
  return up[a][0];
}
void lca_pre() {
  g.resize(n);
  for (int i = 1; i < n; ++i) {
    g[i - 1].push_back(nex[i] - 1);
    g[nex[i] - 1].push_back(i - 1);
  }
  tin.resize(n), tout.resize(n), up.resize(n);
  l = 1;
  while ((1 << l) <= n) ++l;
  for (int i = 0; i < n; ++i) up[i].resize(l + 1);
  dfs(n - 1);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a;
    --b;
    int res = lca(a, b);
    if (i + 1 < q)
      printf("%d ", res + 1);
    else
      printf("%d\n", res + 1);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld %lld", &x[i], &y[i]);
  }
  stop = 0;
  nex[n] = 0;
  st[++stop] = n;
  if (n > 1) {
    nex[n - 1] = n;
    st[++stop] = n - 1;
  }
  for (int i = n - 2; i > 0; --i) {
    while (stop >= 2 && (y[st[stop]] - y[i]) * (x[st[stop - 1]] - x[i]) <
                            (y[st[stop - 1]] - y[i]) * (x[st[stop]] - x[i])) {
      --stop;
    }
    nex[i] = st[stop];
    st[++stop] = i;
  }
  lca_pre();
  return 0;
}
