#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-4;
struct Point {
  double x, y;
  Point() { x = y = 0; }
  Point(double xx, double yy) { x = xx, y = yy; }
  Point operator+(Point b) { return Point(x + b.x, y + b.y); }
  Point operator-(Point b) { return Point(x - b.x, y - b.y); }
  double dist() { return sqrt(x * x + y * y); }
  double operator*(Point b) { return x * b.y - y * b.x; }
  double operator%(Point b) { return x * b.x + y * b.y; }
  Point operator*(double k) { return Point(x * k, y * k); }
  void norm() {
    double d = (*this).dist();
    x /= d;
    y /= d;
  }
  void print() { printf("%.4f %.4f\n", x, y); }
};
vector<Point> a;
bool check(Point a, Point b, Point c, Point d) {
  double p1 = (b - a) * (c - a);
  double p2 = (b - a) * (d - a);
  double p3 = (d - c) * (a - c);
  double p4 = (d - c) * (b - c);
  if (fabs(p1) < eps) p1 = 0.0;
  if (fabs(p2) < eps) p2 = 0.0;
  if (fabs(p1) < eps) p3 = 0.0;
  if (fabs(p1) < eps) p4 = 0.0;
  if (p1 * p2 < eps && p3 * p4 < eps) {
    return 1;
  }
  return 0;
}
int main() {
  Point s, e;
  cin >> s.x >> s.y;
  cin >> e.x >> e.y;
  Point c = e - s;
  double l = c.dist();
  c.norm();
  int n;
  cin >> n;
  a.resize(n);
  vector<double> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
    Point f = (a[i] - s);
    b[i] = c * f;
  }
  double p1 = 0, p2 = 0;
  int f = 1;
  for (int i = 0; i < n; i++) {
    if (check(s, e, a[i], a[(i + 1) % n])) {
      f = 0;
    }
  }
  if (f) {
    printf("%.10f", l);
    return 0;
  }
  f = 1;
  for (int i = 0; i < n; i++) {
    if (b[i] <= -eps) {
      f = 0;
    }
  }
  if (f) {
    printf("%.10f\n", l);
    return 0;
  }
  f = 1;
  for (int i = 0; i < n; i++) {
    if (b[i] >= eps) {
      f = 0;
    }
  }
  if (f) {
    printf("%.10f", l);
    return 0;
  }
  double mx = -1e18, mn = 1e18;
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    double d = (a[j] - a[i]).dist();
    if (b[i] >= 0.0 && b[j] >= 0) {
      p1 += d;
    } else if (b[i] < 0.0 && b[j] < 0.0) {
      p2 += d;
    } else if (b[i] > -eps && b[j] < eps) {
      double v = fabs(b[i]);
      double u = fabs(b[j]);
      p1 += v * d / (v + u);
      p2 += u * d / (v + u);
      double x = (u * (a[i] % c) + v * (a[j] % c)) / (v + u);
      mx = max(mx, x);
      mn = min(mn, x);
    } else {
      double v = fabs(b[i]);
      double u = fabs(b[j]);
      p2 += v * d / (v + u);
      p1 += u * d / (v + u);
      double x = (u * (a[i] % c) + v * (a[j] % c)) / (v + u);
      mx = max(mx, x);
      mx = max(mx, x);
      mn = min(mn, x);
    }
  }
  double p = min(p1, p2);
  double h = mx - mn;
  if (p < eps) {
    h = 0.0;
  }
  printf("%.10f", max(l, min(p, 2 * h) + l - h));
  return 0;
}
