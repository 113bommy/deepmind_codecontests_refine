#include <bits/stdc++.h>
using namespace std;
int n, m;
double a[5005][5005];
int M[100008][20], mx[5005], sz[5005];
int b[100009];
vector<int> G[5005];
struct node {
  int l, r;
  double p;
  bool operator<(const node &rhs) const {
    if (l != rhs.l)
      return l < rhs.l;
    else
      return r > rhs.r;
  }
} p[5005];
void dfs(int u) {
  sz[u] = 1;
  for (int i = 0; i < (int)G[u].size(); i++) {
    int v = G[u][i];
    dfs(v);
    sz[u] += sz[v];
  }
  for (int i = 1; i <= sz[u]; i++) {
    double tmp = p[u].p;
    for (int j = 0; j < (int)G[u].size(); j++) {
      int v = G[u][j];
      int id = min(sz[v], mx[u] - mx[v] + i - 1);
      tmp *= a[v][id];
    }
    a[u][i] += tmp;
  }
  for (int i = 0; i <= sz[u]; i++) {
    double tmp = 1.0 - p[u].p;
    for (int j = 0; j < (int)G[u].size(); j++) {
      int v = G[u][j];
      int id = min(sz[v], mx[u] - mx[v] + i);
      tmp *= a[v][id];
    }
    a[u][i] += tmp;
  }
}
int rmq(int l, int r) {
  int k = log2(r - l + 1);
  return max(M[l][k], M[r - (1 << k) + 1][k]);
}
void init() {
  for (int i = 0; i <= n; i++) M[i][0] = b[i];
  for (int j = 1; 1 << j <= n; j++)
    for (int i = 0; i + (1 << j) - 1 < n; i++)
      M[i][j] = max(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]);
}
bool in(int a, int b) { return p[b].r >= p[a].r && p[b].l <= p[a].l; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  init();
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%lf", &p[i].l, &p[i].r, &p[i].p);
    p[i].l--;
    p[i].r--;
  }
  sort(p + 1, p + 1 + m);
  m++;
  p[0].l = 0;
  p[0].r = n - 1;
  p[0].p = 0;
  for (int i = 1; i < m; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (in(i, j)) {
        G[j].push_back(i);
        break;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    mx[i] = rmq(p[i].l, p[i].r);
  }
  dfs(0);
  double ans = a[0][0] * mx[0];
  for (int i = 1; i <= sz[0]; i++) {
    ans += (a[0][i] - a[0][i - 1]) * (mx[0] + i);
  }
  printf("%.9f\n", ans);
  return 0;
}
