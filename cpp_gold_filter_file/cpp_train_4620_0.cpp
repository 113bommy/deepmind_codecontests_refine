#include <bits/stdc++.h>
const int MAXN = 131072;
const long long MOD = 777777777;
inline void inc(long long &a, long long b) { a = (a + b) % MOD; }
struct node {
  int l, r;
  long long f[4][4];
} t[MAXN << 1];
int w[4][4];
void change(int p, int l, int r, int u, int v) {
  if (l == r) {
    if (v) {
      memset(t[p].f, 0, sizeof t[p].f);
      t[p].f[v][v] = 1;
    } else
      t[p].f[1][1] = t[p].f[2][2] = t[p].f[3][3] = 1;
    return;
  }
  int m = (l + r) >> 1;
  if (u <= m)
    change(p << 1, l, m, u, v);
  else
    change(p * 2 + 1, m + 1, r, u, v);
  int i, j;
  memset(t[p].f, 0, sizeof t[p].f);
  for (i = 1; i <= 3; ++i)
    for (j = 1; j <= 3; ++j)
      if (w[i][j])
        for (l = 1; l <= 3; ++l)
          for (r = 1; r <= 3; ++r)
            inc(t[p].f[l][r], t[p << 1].f[l][i] * t[p * 2 + 1].f[j][r]);
}
int main() {
  int n, m, i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= 3; ++i)
    for (j = 1; j <= 3; ++j) scanf("%d", w[i] + j);
  for (i = 1; i <= n; ++i) change(1, 1, n, i, 0);
  for (i = 0; i < m; ++i) {
    scanf("%d%d", &j, &k);
    change(1, 1, n, j, k);
    long long ans = 0;
    for (j = 1; j <= 3; ++j)
      for (k = 1; k <= 3; ++k) inc(ans, t[1].f[j][k]);
    printf("%d\n", (int)ans);
  }
  return 0;
}
