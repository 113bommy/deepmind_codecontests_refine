#include <bits/stdc++.h>
using namespace std;
double t1, t2;
struct node {
  double x, y;
} c, h, s;
double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double dist(node a, node b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double work(double du) {
  node x = {s.x * (1 - du) + h.x * du, s.y * (1 - du) + h.y * du};
  double ac = dist(x, c), as = dist(x, s), ah = dist(x, h);
  if (ac + ah <= t2 && ac + as <= t1) return min(t2 - ah, t1 - as);
  double l = 0, r = 1.0;
  for (int i = 1; i <= 300; i++) {
    double mid = (l + r) / 2.0;
    node b = {c.x * (1 - mid) + x.x * mid, c.y * (1 - mid) + x.y * mid};
    double bc = dist(b, c), bs = dist(b, s), bh = dist(b, h);
    if (bc + bh <= t2 && bc + bs <= t1)
      l = mid;
    else
      r = mid;
  }
  node b = {c.x * (1 - l) + x.x * l, c.y * (1 - l) + x.y * l};
  return dist(b, c);
}
int main() {
  int i, j, u, v;
  while (cin >> t1 >> t2) {
    cin >> c.x >> c.y;
    cin >> h.x >> h.y;
    cin >> s.x >> s.y;
    double a = dist(c, s), b = dist(c, h), c = dist(h, s);
    if (b + t2 >= a + c) {
      printf("%.8lf\n", min(a + t1 + c, b + t2));
      continue;
    }
    t1 += a + 1e-10;
    t2 += b + 1e-10;
    double l = 0, r = 1.0, ans = 0;
    for (i = 1; i <= 300; i++) {
      double mid1 = (l + r) / 2.0, mid2 = (mid1 + r) / 2.0;
      double ans1 = work(mid1), ans2 = work(mid2);
      if (ans1 < ans2)
        l = mid1;
      else
        r = mid2;
      ans = max(ans, max(ans1, ans2));
    }
    printf("%.8lf\n", ans);
  }
  return 0;
}
