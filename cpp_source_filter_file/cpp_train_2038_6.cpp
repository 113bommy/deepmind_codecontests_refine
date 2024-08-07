#include <bits/stdc++.h>
using namespace std;
const int mn = 110;
const double inf = 1e20, eps = 1e-8;
struct node {
  int x, y;
} p[mn], a, b, c, d;
double len[mn];
int n, m;
int sqr(int x) { return x * x; }
double dis(node a, node b) { return sqrt(sqr(b.x - a.x) + sqr(b.y - a.y)); }
int area(node a, node b, node c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
double calc(double id) {
  int i = int(id);
  return len[i] + (len[i + 1] - len[i]) * (id - i);
}
int main() {
  scanf("%d%d%d%d", &a.x, &a.y, &b.x, &b.y);
  scanf("%d", &n);
  int i;
  double lo = 1, hi = 0, lid = 1, hid = 1, t, id;
  for (i = 1; i <= n; ++i) scanf("%d%d", &p[i].x, &p[i].y);
  p[n + 1] = p[1];
  for (i = 1; i <= n; ++i) len[i + 1] = len[i] + dis(p[i], p[i + 1]);
  for (i = 1; i <= n; ++i)
    if (fabs(dis(a, b) - dis(a, p[i]) - dis(b, p[i])) < eps) {
      t = dis(a, p[i]) / dis(a, b);
      if (t > hi) hi = t, hid = i;
      if (t < lo) lo = t, lid = i;
    }
  for (i = 0; i <= n; ++i) {
    c = p[i], d = p[i + 1];
    if (area(a, b, c) * area(a, b, d) < 0 &&
        area(c, d, a) * area(c, d, b) < 0) {
      t = (double)area(c, d, a) / (area(c, d, a) - area(c, d, b));
      id = i + (double)area(a, b, c) / (area(a, b, c) - area(a, b, d));
      if (t > hi) hi = t, hid = id;
      if (t < lo) lo = t, lid = id;
    }
  }
  if (lo > hi)
    printf("%.9lf\n", dis(a, b));
  else {
    double p1 = calc(lid), p2 = calc(hid), ans;
    if (p1 > p2) swap(p1, p2);
    printf("%.9lf\n", min(dis(a, b) * (1.0 + hi - lo),
                          dis(a, b) * (1.0 - hi + lo) +
                              min(p2 - p1, len[n + 1] - p2 + p1)));
  }
  return 0;
}
