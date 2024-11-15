#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int MAXM = 1010;
int n, m;
int H[MAXN], E[MAXM], X[MAXM], B[MAXM], co = 0;
inline void add(int x, int y) {
  E[++co] = y, B[co] = x, X[co] = H[x], H[x] = co;
}
bool del[MAXN], v[MAXN];
int lk[MAXN];
bool find(int x) {
  for (int p = H[x]; p; p = X[p])
    if (!del[p] && !v[E[p]]) {
      v[E[p]] = true;
      if (!lk[E[p]] || find(lk[E[p]])) return lk[E[p]] = x;
    }
  return false;
}
int main() {
  scanf("%d %d", &n, &m);
  int x, y;
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", &x, &y);
    add(x, y);
  }
  int ans = 1000000000, M;
  for (int i = 1; i <= n; ++i) {
    memset(del, false, sizeof del);
    memset(lk, false, sizeof lk);
    M = 0;
    for (int j = 1; j <= m; ++j)
      if (B[j] == i || E[j] == i) del[j] = true, ++M;
    int cur = 0;
    for (int j = 1; j <= n; ++j) {
      memset(v, false, sizeof v);
      cur += find(j);
    }
    cur = (2 * n - 1 - M) + (m - M - cur) + (n - 1 - cur);
    if (cur < ans) ans = cur;
  }
  printf("%d\n", ans);
  return 0;
}
