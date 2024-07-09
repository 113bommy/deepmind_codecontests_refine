#include <bits/stdc++.h>
using namespace std;
double tb, tc;
struct data {
  double x, y;
} a, b, c;
inline double dis(data p, data q) {
  return sqrt(((p.x - q.x) * (p.x - q.x)) + ((p.y - q.y) * (p.y - q.y)));
}
double calc(double k) {
  data u = (data){c.x * (1 - k) + b.x * k, c.y * (1 - k) + b.y * k};
  double au = dis(a, u), ub = dis(u, b), uc = dis(u, c);
  if (au + ub < tb && au + uc < tc) return min(tb - ub, tc - uc);
  double L = 0.0, R = 1.0;
  while (R - L > 1e-15) {
    double mid = (L + R) * 0.5;
    data uu = (data){mid * u.x + (1 - mid) * a.x, mid * u.y + (1 - mid) * a.y};
    if (mid * au + dis(uu, b) < tb && mid * au + dis(uu, c) < tc)
      L = mid;
    else
      R = mid;
  }
  return au * (L + R) * 0.5;
}
int main() {
  scanf("%lf%lf", &tb, &tc);
  scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &c.x, &c.y, &b.x, &b.y);
  double ab = dis(a, b), bc = dis(b, c), ac = dis(a, c);
  tc += ac + 1e-10, tb += ab + 1e-10;
  if (tc > ab + bc) return printf("%.8lf", min(tb + bc, tc)), 0;
  double l = 0.0, r = 1.0;
  while (r - l > 1e-10) {
    double mid = (l + r) * 0.5;
    double midmid = (mid + r) * 0.5;
    double tmpm = calc(mid);
    double tmpmm = calc(midmid);
    if (tmpm > tmpmm)
      r = midmid;
    else
      l = mid;
  }
  printf("%.8lf", calc((l + r) * 0.5));
  return 0;
}
