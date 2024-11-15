#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int inf = 1 << 29;
const int tre = 330;
char S[maxn], T[maxn];
char str[maxn];
int len, bit[maxn];
int bac[maxn], sa[maxn], SA[maxn];
int _ran[maxn], Rank[maxn], h[maxn];
int ord[maxn], val[maxn];
int n, m, q, ans[maxn], id[maxn], idx;
int l[maxn], r[maxn], K[maxn], x[maxn], y[maxn];
struct RMQ {
  int rmq[17][maxn];
  void build(int len) {
    for (int j = 1; j < 17; j++)
      for (int i = 0; i <= len; i++)
        rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i - (1 << j - 1)]);
  }
  int query(int l, int r) {
    if (l > r) return inf;
    int j = bit[r - l + 1];
    return min(rmq[j][r], rmq[j][l + (1 << j) - 1]);
  }
} suf, rmq, rmqj;
void upd(int &x, int y) {
  if (x > y) x = y;
}
void suffix(int alp) {
  for (int i = 0; i <= alp; i++) bac[i] = 0;
  for (int i = 1; i <= len; i++) bac[str[i]]++;
  for (int i = 1; i <= alp; i++) bac[i] += bac[i - 1];
  for (int i = 1; i <= len; i++) sa[bac[str[i]]--] = i;
  for (int i = 1; i <= len; i++)
    _ran[sa[i]] = _ran[sa[i - 1]] + (str[sa[i]] != str[sa[i - 1]]);
  for (int p = 1; p <= len; p <<= 1) {
    for (int i = 1; i <= len; i++) bac[_ran[sa[i]]] = i;
    for (int i = len; i >= 1; i--)
      if (sa[i] > p) SA[bac[_ran[sa[i] - p]]--] = sa[i] - p;
    for (int i = len - p + 1; i <= len; i++) SA[bac[_ran[i]]--] = i;
    for (int i = 1; i <= len; i++)
      Rank[SA[i]] = Rank[SA[i - 1]] + (_ran[SA[i]] != _ran[SA[i - 1]] ||
                                       _ran[SA[i] + p] != _ran[SA[i - 1] + p]);
    swap(SA, sa);
    swap(_ran, Rank);
  }
  for (int i = 1; i <= len; i++) {
    int j = sa[_ran[i] - 1], k = max(0, h[i - 1] - 1);
    while (str[i + k] == str[j + k]) ++k;
    h[i] = k;
    suf.rmq[0][_ran[i]] = k;
  }
  suf.build(len);
}
int lcp(int u, int v) {
  u = _ran[u];
  v = _ran[v];
  if (u > v) swap(u, v);
  return suf.query(u + 1, v);
}
bool comp(int i, int j) {
  if (i == j) return false;
  bool sw = false;
  if (i > j) swap(i, j), sw = true;
  if (j - i >= m) {
    int d = (j - i) - m, w = j - i;
    int lcp1 = lcp(n + 1, i + 1);
    if (lcp1 < m) return (_ran[n + 1] < _ran[i + 1]) ^ sw;
    int lcp2 = lcp(i + 1, i + 1 + m);
    if (lcp2 < d) return (_ran[i + 1] < _ran[i + 1 + m]) ^ sw;
    int lcp3 = lcp(i + 1 + d, n + 1);
    if (lcp3 < m) return (_ran[i + 1 + d] < _ran[n + 1]) ^ sw;
  } else {
    int d = m - (j - i), w = j - i;
    int lcp1 = lcp(n + 1, i + 1);
    if (lcp1 < w) return (_ran[n + 1] < _ran[i + 1]) ^ sw;
    int lcp2 = lcp(n + 1 + w, n + 1);
    if (lcp2 < d) return (_ran[n + 1 + w] < _ran[n + 1]) ^ sw;
    int lcp3 = lcp(i + 1, n + 1 + d);
    if (lcp3 < m) return (_ran[i + 1] < _ran[n + 1 + d]) ^ sw;
  }
  return !sw;
}
int main() {
  scanf("%s", S + 1);
  n = strlen(S + 1);
  scanf("%s", T + 1);
  m = strlen(T + 1);
  for (int i = 1; i <= n; i++) str[++len] = S[i];
  for (int i = 1; i <= m; i++) str[++len] = T[i];
  for (int i = 2; i <= len; i++) bit[i] = bit[i >> 1] + 1;
  suffix(128);
  for (int i = 0; i <= n; i++) ord[i] = i;
  sort(ord, ord + n + 1, comp);
  for (int i = 0; i <= n; i++) val[ord[i]] = i;
  for (int i = 0; i <= n; i++) rmq.rmq[0][i] = val[i];
  rmq.build(n);
  scanf("%d", &q);
  for (int i = 0; i <= q; i++) ans[i] = -1;
  for (int i = 1; i <= q; i++)
    scanf("%d %d %d %d %d", &l[i], &r[i], &K[i], &x[i], &y[i]);
  for (int i = 1; i <= q; i++)
    if (ans[i] < 0) {
      if (K[i] > tre) {
        ans[i] = inf;
        for (int j = 0; j * K[i] <= r[i]; j++)
          upd(ans[i], rmq.query(max(l[i], j * K[i] + x[i]),
                                min(r[i], j * K[i] + y[i])));
      } else {
        idx = 0;
        for (int j = 0; j < K[i]; j++)
          for (int k = 0; k * K[i] + j <= n; k++)
            rmqj.rmq[0][idx] = val[k * K[i] + j], id[k * K[i] + j] = idx++;
        rmqj.build(idx);
        for (int j = i; j <= q; j++)
          if (K[j] == K[i]) {
            ans[j] = inf;
            for (int k = x[j]; k <= y[j]; k++) {
              int L = l[j] / K[j] * K[j] + k;
              int R = r[j] / K[j] * K[j] + k;
              while (L < l[j]) L += K[j];
              while (R > r[j]) R -= K[j];
              if (L <= R) upd(ans[j], rmqj.query(id[L], id[R]));
            }
          }
      }
    }
  for (int i = 1; i <= q; i++) printf("%d ", ans[i] != inf ? ord[ans[i]] : -1);
  return 0;
}
