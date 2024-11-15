#include <bits/stdc++.h>
using namespace std;
const long double Eps = 1e-12;
const long double Pi = 4 * atan(1);
int sgn(long double a, long double b = 0) {
  a -= b;
  return (a > Eps) - (a < -Eps);
}
struct Point {
  long double x, y;
  Point operator-(Point p) { return {x - p.x, y - p.y}; }
  Point operator+(Point p) { return {x + p.x, y + p.y}; }
  Point operator*(long double d) { return {x * d, y * d}; }
  Point rot(long double d) {
    long double rx = x * cos(d) - y * sin(d);
    long double ry = x * sin(d) + y * cos(d);
    return {rx, ry};
  }
  long double len2() { return x * x + y * y; }
  long double len() { return sqrt(len2()); }
  long double arg() {
    long double r = atan2(y, x);
    return sgn(r) < 0 ? r + 2 * Pi : r;
  }
};
vector<Point> circle_inter(Point c1, long double r1, Point c2, long double r2) {
  vector<Point> ret;
  long double x = (c1 - c2).len2();
  long double y = ((r1 * r1 - r2 * r2) / x + 1) / 2;
  long double d = r1 * r1 / x - y * y;
  if (sgn(d) == -1) return ret;
  d = max(d, 0.0L);
  Point p1 = c1 + (c2 - c1) * y;
  Point p2 = ((c2 - c1) * sqrt(d)).rot(Pi / 2);
  ret.push_back(p1 - p2);
  ret.push_back(p1 + p2);
  return ret;
}
pair<long double, long double> circle_cover(Point c1, long double r1, Point c2,
                                            long double r2, bool &f) {
  f = false;
  long double d = (c1 - c2).len();
  if (sgn(r1 + r2, d) < 0 || sgn(r2 + d, r1) < 0) return {0, 0};
  f = true;
  if (sgn(r1 + d, r2) <= 0) return {0, 2 * Pi};
  auto p = circle_inter(c1, r1, c2, r2);
  long double a1 = (p[0] - c1).arg();
  long double a2 = (p[1] - c1).arg();
  if (sgn(a1 > a2)) a2 += 2 * Pi;
  return {a1, a2};
}
bool btw(long double a, pair<long double, long double> b) {
  if (sgn(a, 2 * Pi) >= 0) a -= 2 * Pi;
  return (sgn(b.first, a) <= 0 && sgn(a, b.second) <= 0) ||
         (sgn(b.first, a + 2 * Pi) <= 0 && sgn(a + 2 * Pi, b.second) <= 0);
}
bool check(Point c1, long double r1, Point c2, long double r2, Point c3,
           long double r3) {
  vector<Point> ch = {c1, c2, c3};
  auto v1 = circle_inter(c1, r1, c2, r2);
  auto v2 = circle_inter(c2, r2, c3, r3);
  auto v3 = circle_inter(c3, r3, c1, r1);
  for (auto &p : v1) ch.push_back(p);
  for (auto &p : v2) ch.push_back(p);
  for (auto &p : v3) ch.push_back(p);
  for (auto &p : ch)
    if (sgn((p - c1).len(), r1) <= 0 && sgn((p - c2).len(), r2) <= 0 &&
        sgn((p - c3).len(), r3) <= 0)
      return true;
  return false;
}
int main() {
  ios ::sync_with_stdio(false);
  long double t1, t2;
  cin >> t1 >> t2;
  Point c, h, s;
  cin >> c.x >> c.y;
  cin >> h.x >> h.y;
  cin >> s.x >> s.y;
  cout << fixed << setprecision(6);
  if (sgn((c - h).len() + t2, (c - s).len() + (s - h).len()) >= 0)
    cout << min((c - s).len() + (s - h).len() + t1, (c - h).len() + t2) << '\n';
  else {
    long double left = 0;
    long double right = min((c - s).len() + t1, (c - h).len() + t2);
    for (int _ = 0; _ < 50; _++) {
      long double mid = (left + right) / 2;
      if (check(c, mid, s, (c - s).len() + t1 - mid, h,
                (c - h).len() + t2 - mid))
        left = mid;
      else
        right = mid;
    }
    cout << left << '\n';
  }
  return 0;
}
