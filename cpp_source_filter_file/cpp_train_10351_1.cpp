#include <bits/stdc++.h>
using namespace std;
long long SUM[3][110000], TOT[3][110000], L[3], *l, *sum, *tot;
int SZ[3][110000], *sz;
vector<int> ADJ[3][110000], *adj;
int par[110000];
long long besta[110000], bestb[110000], best[110000];
int N[3], M, A, B;
void dfs(int u) {
  int i, v, deg = adj[u].size();
  sum[u] = 0;
  sz[u] = 1;
  for (i = 0; i < deg; i++) {
    v = adj[u][i];
    if (v == par[u]) continue;
    par[v] = u;
    dfs(v);
    sum[u] += sum[v] + sz[v];
    sz[u] += sz[v];
    *l += 1LL * sz[v] * (M - sz[v]);
  }
}
void calctot(int u) {
  if (u)
    tot[u] = tot[par[u]] + (M - 2 * sz[u]);
  else
    tot[u] = sum[u];
  int i, v, deg = adj[u].size();
  for (i = 0; i < deg; i++) {
    v = adj[u][i];
    if (v == par[u]) continue;
    calctot(v);
  }
}
void calc(int u) {
  int i, j, k, v, deg = adj[u].size();
  besta[u] = tot[u] * A;
  bestb[u] = tot[u] * B;
  best[u] = max(besta[u], bestb[u]);
  for (i = 0; i < deg; i++) {
    v = adj[u][i];
    if (v == par[u]) continue;
    par[v] = u;
    calc(v);
    besta[u] = max(besta[u], besta[v] + 1LL * A * B);
    bestb[u] = max(bestb[u], bestb[v] + 1LL * A * B);
    best[u] = max(best[u], besta[v] + 1LL * A * B + tot[u] * B);
    best[u] = max(best[u], bestb[v] + 1LL * A * B + tot[u] * A);
  }
  if (deg == 1) return;
  for (i = 0, j = k = -1; i < deg; i++) {
    v = adj[u][i];
    if (v == par[u]) continue;
    if (j == -1 || besta[j] < besta[v]) j = v;
    if (k == -1 || bestb[j] < bestb[v]) k = v;
  }
  if (j != k) {
    best[u] = max(best[u], besta[j] + bestb[k] + 2LL * A * B);
  } else {
    for (i = 0; i < deg; i++) {
      v = adj[u][i];
      if (v == par[u] || v == j) continue;
      best[u] = max(best[u], besta[v] + bestb[k] + 2LL * A * B);
      best[u] = max(best[u], besta[j] + bestb[v] + 2LL * A * B);
    }
  }
}
int main() {
  int i, j, k, u, v, id[5];
  long long maxv[5], a, b, ans;
  scanf("%d%d%d", &N[0], &N[1], &N[2]);
  for (i = 0; i < 3; i++) {
    for (j = 1; j < N[i]; j++) {
      scanf("%d%d", &u, &v);
      u--, v--;
      ADJ[i][u].push_back(v);
      ADJ[i][v].push_back(u);
    }
    par[0] = -1;
    adj = ADJ[i];
    sum = SUM[i];
    sz = SZ[i];
    tot = TOT[i];
    M = N[i];
    l = L + i;
    *l = 0;
    dfs(0);
    calctot(0);
    maxv[i] = *max_element(tot, tot + M);
  }
  ans = -1;
  for (i = 0; i < 3; i++) id[i] = i;
  do {
    i = id[0];
    j = id[1];
    k = id[2];
    if (j > k) continue;
    adj = ADJ[i];
    sum = SUM[i];
    sz = SZ[i];
    tot = TOT[i];
    M = N[i];
    A = N[j];
    B = N[k];
    par[0] = -1;
    calc(0);
    a = L[0] + L[1] + L[2] + maxv[j] * (B + M) + maxv[k] * (A + M) +
        2LL * A * B + 1LL * M * (A + B);
    b = *max_element(best, best + M);
    ans = max(ans, a + b);
  } while (next_permutation(id, id + 3));
  printf("%I64d\n", ans);
  return 0;
}
