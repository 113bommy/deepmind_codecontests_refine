#include <bits/stdc++.h>
using namespace std;
template <class T>
struct Point {
  T x, y;
  explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
  bool operator<(Point p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(Point p) const { return tie(x, y) == tie(p.x, p.y); }
  Point operator+(Point p) const { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) const { return Point(x - p.x, y - p.y); }
  Point operator*(T d) const { return Point(x * d, y * d); }
  Point operator/(T d) const { return Point(x / d, y / d); }
  T dot(Point p) const { return x * p.x + y * p.y; }
  T cross(Point p) const { return x * p.y - y * p.x; }
  T cross(Point a, Point b) const { return (a - *this).cross(b - *this); }
  T dist2() const { return x * x + y * y; }
  long double dist() const { return sqrt((long double)dist2()); }
  long double angle() const { return atan2(y, x); }
  Point unit() const { return *this / dist(); }
  Point perp() const { return Point(-y, x); }
  Point normal() const { return perp().unit(); }
  Point rotate(long double a) const {
    return Point(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
  Point inv() const { return Point(x / dist2(), y / dist2()); }
};
template <class Point>
pair<Point, Point> circleTangents(const Point& p, const Point& c,
                                  long double r) {
  Point a = p - c;
  long double x = r * r / a.dist2(), y = sqrt(x - x * x);
  return make_pair(c + a * x + a.perp() * y, c + a * x - a.perp() * y);
}
long double ccRadius(const Point<long double>& A, const Point<long double>& B,
                     const Point<long double>& C) {
  return (B - A).dist() * (C - B).dist() * (A - C).dist() /
         abs((B - A).cross(C - A)) / 2;
}
Point<long double> ccCenter(const Point<long double>& A,
                            const Point<long double>& B,
                            const Point<long double>& C) {
  Point<long double> b = C - A, c = B - A;
  return A + (b * c.dist2() - c * b.dist2()).perp() / b.cross(c) / 2;
}
int main() {
  long double a, b;
  cin >> a >> b;
  Point<long double> p1(a, b);
  cin >> a >> b;
  Point<long double> p2(a, b);
  p2 = p2 - p1;
  int n;
  cin >> n;
  long double z = p2.angle();
  p2 = p2.rotate(-z);
  p2 = p2.inv();
  vector<pair<long double, long double> > g;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    Point<long double> px(a, b);
    px = px - p1;
    px = px.rotate(-z);
    long double r;
    cin >> r;
    Point<long double> new1 = px + Point<long double>(r, 0);
    Point<long double> new2 = px + Point<long double>(-r, 0);
    Point<long double> new3 = px + Point<long double>(0, r);
    new1 = new1.inv();
    new2 = new2.inv();
    new3 = new3.inv();
    long double newradius = ccRadius(new1, new2, new3);
    Point<long double> newcenter = ccCenter(new1, new2, new3);
    pair<Point<long double>, Point<long double> > ans =
        circleTangents(p2, newcenter, newradius);
    long double ang1 = Point<long double>(ans.first - p2).angle();
    long double ang2 = Point<long double>(ans.second - p2).angle();
    if (ang1 < 0 || ang2 < 0) {
      ang1 += 2.0 * asin(1.0);
      ang2 += 2.0 * asin(1.0);
    }
    g.push_back(make_pair(ang1, ang2));
  }
  g.push_back(make_pair(0, 0));
  g.push_back(make_pair(2 * asin(1.0), 2 * asin(1.0)));
  sort(g.begin(), g.end());
  vector<long double> poss;
  long double curmax = 0.0;
  for (int i = 0; i + 1 < g.size(); i++) {
    curmax = max(curmax, g[i].second);
    if (curmax <= g[i + 1].first + 0.000000000000000000001) {
      poss.push_back(curmax);
      if (curmax <= asin(1.0) + 0.000000000000000000001) {
        if (asin(1.0) + 0.000000000000000000001 <= g[i + 1].first) {
          poss.push_back(asin(1.0));
        }
      }
      poss.push_back(g[i + 1].first);
    }
  }
  long double bestang = 100.0;
  for (int i = 0; i < poss.size(); i++) {
    bestang = min(bestang, abs(asin(1.0) - poss[i]));
  }
  long double dist = p2.dist() * cos(bestang);
  long double diam = 1.0 / dist;
  printf("%.15Lf\n", diam / 2.0);
}
