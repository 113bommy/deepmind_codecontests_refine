#include <bits/stdc++.h>
using namespace std;
int f[110000], _f[110000], i, Ans, Last, s[110000], st, n;
struct pt {
  int _, v, s, l, r;
} p[110000];
map<int, int> Map, _Map;
bool cmp(pt a, pt b) {
  return (a.l + a.r + a.s) != (b.l + b.r + b.s)
             ? (a.l + a.r + a.s < b.l + b.r + b.s)
             : (a._ < b._);
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    p[i]._ = i;
    scanf("%d%d%d%d", &p[i].v, &p[i].s, &p[i].l, &p[i].r);
  }
  sort(p + 1, p + n + 1, cmp);
  Map[0] = 0;
  for (i = 1; i <= n; i++) {
    if (i && p[i].l + p[i].r + p[i].s != p[i - 1].l + p[i - 1].r + p[i - 1].s) {
      Map.clear();
      Map[0] = 0;
    }
    if (Map.count(p[i].l)) {
      f[i] = Map[p[i].l] + p[i].v;
      _f[i] = _Map[p[i].l];
    } else
      f[i] = -1000000000;
    if (f[i] > Map[p[i].l + p[i].s]) {
      Map[p[i].l + p[i].s] = f[i];
      _Map[p[i].l + p[i].s] = i;
    }
    if (p[i].r == 0 && f[i] > Ans) {
      Ans = f[i];
      Last = i;
    }
  }
  for (; Last; Last = _f[Last]) s[st++] = p[Last]._;
  printf("%d\n", st);
  for (i = st - 1; i >= 0; i--) printf("%d ", s[i]);
  return 0;
}
