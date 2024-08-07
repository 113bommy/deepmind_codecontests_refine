#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, W, L, tr[N], d1[N], d2[N], sz[N], msz[N];
bool used[N];
vector<int> all;
long long ans;
struct edge {
  int to, nx, w;
} ee[N * 2];
int eq[N], en = 1;
void prep_sz(int u, int p) {
  sz[u] = 1;
  msz[u] = 0;
  for (int j = eq[u], v; v = ee[j].to, j; j = ee[j].nx)
    if (!used[v])
      if (v != p) {
        prep_sz(v, u);
        sz[u] += sz[v];
        msz[u] = max(msz[u], sz[v]);
      }
  all.push_back(u);
}
void prep_d(int u, int p) {
  for (int j = eq[u], v; v = ee[j].to, j; j = ee[j].nx)
    if (!used[v])
      if (v != p) {
        d1[v] = d1[u] + 1;
        d2[v] = d2[u] + ee[j].w;
        prep_d(v, u);
      }
}
bool cmp_d2(int i, int j) { return d2[i] < d2[j]; }
void add(int w, int v) {
  for (int j = ++w; j <= n; j += j & -j) tr[j] += v;
}
int ask(int w) {
  if (w < 0) return 0;
  int ret = 0;
  for (int j = ++w; j; j -= j & -j) ret += tr[j];
  return ret;
}
void workans(vector<int> st, int val) {
  sort(st.begin(), st.end(), cmp_d2);
  int n = st.size(), q = 0;
  for (int j = n - 1; j >= 0; --j) {
    int lim = W - d2[st[j]];
    while (q < n && d2[st[q]] <= lim) {
      add(d1[st[q]], val);
      ++q;
    }
    ans += ask(L - d1[st[j]]);
  }
  while (q) add(d1[st[--q]], -val);
}
void solve(int ut) {
  all.clear();
  prep_sz(ut, 0);
  int tot = sz[ut], cd = 0;
  for (int i = 0; i < tot; ++i) {
    int u = all[i];
    if (max(msz[u], tot - sz[u]) < max(msz[cd], tot - sz[cd])) cd = u;
  }
  d1[cd] = d2[cd] = 0;
  prep_d(cd, 0);
  workans(all, 1);
  for (int j = eq[cd], v; v = ee[j].to, j; j = ee[j].nx)
    if (!used[v]) {
      all.clear();
      prep_sz(v, cd);
      workans(all, -1);
    }
  used[cd] = 1;
  for (int j = eq[cd], v; v = ee[j].to, j; j = ee[j].nx)
    if (!used[v]) solve(v);
}
void link(int u, int v, int w) { ee[++en] = (edge){v, eq[u], w}, eq[u] = en; }
int main() {
  scanf("%d %d %d", &n, &L, &W);
  for (int i = 2; i <= n; ++i) {
    int j, w;
    scanf("%d %d", &j, &w);
    link(i, j, w);
    link(j, i, w);
  }
  solve(1);
  printf("%I64d\n", ans - n >> 1);
}
