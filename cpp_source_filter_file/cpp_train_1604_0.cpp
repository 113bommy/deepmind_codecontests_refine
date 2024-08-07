#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 5, Q = (int)1e5 + 5, logT = 51;
const long long oo = (long long)1e18;
int sign(int x) { return x > 0 ? 1 : x < 0 ? -1 : 0; }
int n, b, q;
long long tim[Q];
struct arrow *null;
struct arrow {
  int x0, y0, x1, y1, dx, dy;
  arrow *to[logT];
  long long dis[logT];
  void read() {
    scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
    dx = sign(x1 - x0);
    dy = sign(y1 - y0);
  }
  void read2() {
    char c;
    scanf("%d%d %c", &x0, &y0, &c);
    x1 = x0;
    y1 = y0;
    switch (c) {
      case 'L':
        dx--;
        break;
      case 'R':
        dx++;
        break;
      case 'D':
        dy--;
        break;
      case 'U':
        dy++;
        break;
    }
  }
} a[N], *ord[N];
bool cmpx0(arrow *a, arrow *b) { return max(a->x0, a->x1) < max(b->x0, b->x1); }
bool cmpx1(arrow *a, arrow *b) { return min(a->x0, a->x1) > min(b->x0, b->x1); }
bool cmpy0(arrow *a, arrow *b) { return max(a->y0, a->y1) < max(b->y0, b->y1); }
bool cmpy1(arrow *a, arrow *b) { return min(a->y0, a->y1) > min(b->y0, b->y1); }
void work(int dx, int dy, int arrow::*y0, int arrow::*y1,
          bool (*cmp)(arrow *, arrow *)) {
  for (int i = 1; i <= n + q; i++) ord[i] = a + (n + q + 1 - i);
  stable_sort(ord + 1, ord + n + q + 1, cmp);
  typedef multimap<int, arrow *> mia;
  mia s;
  for (int i = 1; i <= n + q; i++) {
    if (ord[i] <= a + n) {
      mia::iterator lo = s.lower_bound(min(ord[i]->*y0, ord[i]->*y1)),
                    hi = s.upper_bound(max(ord[i]->*y0, ord[i]->*y1)), it;
      for (it = lo; it != hi; s.erase(it++)) {
        arrow *tmp = it->second;
        tmp->to[0] = ord[i];
        tmp->dis[0] = abs(ord[i]->x1 - tmp->x1) + abs(ord[i]->y1 - tmp->y1);
      }
    }
    if (ord[i]->dx == dx && ord[i]->dy == dy)
      s.insert(make_pair(ord[i]->*y0, ord[i]));
  }
  for (mia::iterator it = s.begin(); it != s.end(); it++) {
    arrow *tmp = it->second;
    tmp->to[0] = null;
    tmp->dis[0] = oo;
  }
}
int main() {
  null = a;
  scanf("%d%d", &n, &b);
  for (int i = 1; i <= n; i++) a[i].read();
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) a[n + i].read2(), scanf("%I64d", &tim[i]);
  work(1, 0, &arrow::y0, &arrow::y1, cmpx0);
  work(-1, 0, &arrow::y0, &arrow::y1, cmpx1);
  work(0, 1, &arrow::x0, &arrow::x1, cmpy0);
  work(0, -1, &arrow::x0, &arrow::x1, cmpy1);
  null->to[0] = null;
  for (int j = 1; j < logT; j++)
    for (int i = 0; i <= n + q; i++)
      a[i].to[j] = a[i].to[j - 1]->to[j - 1],
      a[i].dis[j] = a[i].dis[j - 1] + a[i].to[j - 1]->dis[j - 1];
  for (int i = 1; i <= q; i++) {
    arrow *u = a + n + i;
    for (int j = logT - 1; j >= 0; j--)
      if (u->dis[j] <= tim[i]) tim[i] -= u->dis[j], u = u->to[j];
    if (u->to[0] != null && tim[i] > (u->to[0]->x1 - u->x1) * u->dx +
                                         (u->to[0]->y1 - u->y1) * u->dy)
      tim[i] -= u->dis[0], u = u->to[0];
    printf("%I64d %I64d\n", min(max(u->x1 + tim[i] * u->dx, 0LL), (long long)b),
           min(max(u->y1 + tim[i] * u->dy, 0LL), (long long)b));
  }
}
