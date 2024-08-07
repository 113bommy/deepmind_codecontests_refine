#include <bits/stdc++.h>
const int inf = (1ll << 30) - 1;
const int maxn = (int)1e5 + 10;
using namespace std;
int n;
vector<int> g[100100];
int a[100100];
int in[100100];
int out[100100];
int dp[100100];
map<int, int> t[400400];
int timer = 0;
void dfs(int v) {
  in[v] = timer;
  a[timer] = v;
  timer++;
  dp[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    dfs(to);
    dp[v] += dp[to];
  }
  out[v] = timer - 1;
}
void build(int v, int l, int r) {
  if (l == r) {
    t[v][dp[a[l]]]++;
  } else {
    int mid = (l + r) >> 1;
    build(v * 2, l, mid);
    build(v * 2 + 1, mid + 1, r);
    for (int i = l; i <= r; i++) t[v][dp[a[i]]]++;
  }
}
int getu(int v, int l, int r, int tl, int tr, int x) {
  if (tl > tr) return inf;
  if (l == tl && tr == r) {
    map<int, int>::iterator pos = t[v].lower_bound(x);
    if (pos != t[v].end()) return pos->first;
    return inf;
  }
  int mid = (l + r) >> 1;
  return min(getu(v * 2, l, mid, tl, min(tr, mid), x),
             getu(v * 2 + 1, mid + 1, r, max(tl, mid + 1), tr, x));
}
int getd(int v, int l, int r, int tl, int tr, int x) {
  if (tl > tr) return -inf;
  if (l == tl && tr == r) {
    map<int, int>::iterator pos = t[v].lower_bound(x + 1);
    if (pos != t[v].begin()) return (--pos)->first;
    return -inf;
  }
  int mid = (l + r) >> 1;
  return max(getd(v * 2, l, mid, tl, min(tr, mid), x),
             getd(v * 2 + 1, mid + 1, r, max(tl, mid + 1), tr, x));
}
void ADD(int v, int l, int r, int pos, int x) {
  t[v][x]++;
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid) {
    ADD(v * 2, l, mid, pos, x);
  } else
    ADD(v * 2 + 1, mid + 1, r, pos, x);
}
void DEL(int v, int l, int r, int pos, int x) {
  t[v][x]--;
  if (t[v][x] == 0) t[v].erase(x);
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid) {
    DEL(v * 2, l, mid, pos, x);
  } else
    DEL(v * 2 + 1, mid + 1, r, pos, x);
}
int ans[100100];
set<int> PA;
void calc(int v, int szz) {
  int cv = dp[v];
  DEL(1, 0, n - 1, in[v], cv);
  PA.insert(dp[v]);
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    cv = szz + dp[v] - dp[to];
    calc(to, szz + dp[v] - dp[to]);
  }
  PA.erase(dp[v]);
  vector<pair<int, int> > cur;
  if (szz) cur.push_back(make_pair(szz, 0));
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    cur.push_back(make_pair(dp[to], to));
  }
  sort(cur.begin(), cur.end());
  int d = cur.size();
  if (cur.size() <= 1 || cur[d - 2].first == cur.back().first) {
    ans[v] = cur.back().first;
    ADD(1, 0, n - 1, in[v], dp[v]);
    return;
  }
  ans[v] = cur[d - 1].first;
  int sz = (cur[0].first + cur[d - 1].first) / 2 - cur[0].first;
  int xx;
  int V = cur[d - 1].second;
  if (V)
    xx = getu(1, 0, n - 1, in[V], out[V], sz);
  else {
    xx = min(getu(1, 0, n - 1, 0, in[v] - 1, sz),
             getu(1, 0, n - 1, out[v] + 1, n - 1, sz));
    set<int>::iterator it = PA.lower_bound(sz + dp[v]);
    if (it != PA.end()) xx = min(xx, *it - dp[v]);
  }
  ans[v] = min(ans[v], max(cur[d - 2].first,
                           max(cur[0].first + xx, cur[d - 1].first - xx)));
  if (V)
    xx = getd(1, 0, n - 1, in[V], out[V], sz);
  else {
    xx = max(getd(1, 0, n - 1, 0, in[v] - 1, sz),
             getd(1, 0, n - 1, out[v] + 1, n - 1, sz));
    set<int>::iterator it = PA.upper_bound(sz + dp[v]);
    if (it != PA.begin()) xx = min(xx, *(--it) - dp[v]);
  }
  ans[v] = min(ans[v], max(cur[d - 2].first,
                           max(cur[0].first + xx, cur[d - 1].first - xx)));
  ADD(1, 0, n - 1, in[v], dp[v]);
}
void solve() {
  scanf("%d", &n);
  int root = 0;
  for (int i = 1, x, y; i <= n; i++) {
    scanf("%d%d", &x, &y);
    if (x)
      g[x].push_back(y);
    else
      root = y;
  }
  if (n == 1) {
    printf("0\n");
    return;
  }
  if (n == 2) {
    printf("1\n1\n");
    return;
  }
  dfs(root);
  build(1, 0, n - 1);
  calc(root, 0);
  for (int i = 1; i <= n; i++) {
    printf("%d\n", ans[i]);
  }
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
