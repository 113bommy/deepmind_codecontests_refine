#include <bits/stdc++.h>
using namespace std;
long long d[251000];
int n, x[251000], y[251000], m[251000], p[251000], r[251000], h, t, s[251000],
    _d[251000], __d[251000];
struct pt {
  int _;
};
bool operator<(pt a, pt b) {
  return m[a._] != m[b._] ? m[a._] < m[b._] : a._ < b._;
}
set<pt> Map[251000];
bool cmp(int a, int b) { return d[a] < d[b]; }
int Get(long long R) {
  if (d[_d[1]] > R) return 0;
  int l(1), r(n + 1);
  for (; l + 1 < r;)
    if (d[_d[(l + r) / 2]] <= R)
      l = (l + r) / 2;
    else
      r = (l + r) / 2;
  return l;
}
void Ins(pt a) {
  for (int i(__d[a._]); i <= n; i += i & -i) Map[i].insert(a);
}
void Del(pt a) {
  for (int i(__d[a._]); i <= n; i += i & -i) Map[i].erase(a);
}
int main() {
  int i, MaxD;
  scanf("%d%d%d%d%d", x, y, p, r, &n);
  for (i = 1; i <= n; i++)
    scanf("%d%d%d%d%d", x + i, y + i, m + i, p + i, r + i);
  for (i = 1; i <= n; i++)
    d[i] = 1ll * (x[i] - x[0]) * (x[i] - x[0]) +
           1ll * (y[i] - y[0]) * (y[i] - y[0]);
  for (i = 1; i <= n; i++) _d[i] = i;
  sort(_d + 1, _d + n + 1, cmp);
  for (i = 1; i <= n; i++) __d[_d[i]] = i;
  for (i = 1; i <= n; i++) Ins((pt){i});
  for (t = 1; h < t; h++) {
    MaxD = Get(r[s[h]] * r[s[h]]);
    for (; MaxD; MaxD &= MaxD - 1)
      for (; !Map[MaxD].empty() && m[s[t] = Map[MaxD].begin()->_] <= p[s[h]];
           Del((pt){s[t++]}))
        ;
  }
  printf("%d\n", t - 1);
  return 0;
}
