#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
const int mod = 1000000007, MAX = 1000005, INF = 1 << 30;
const long double eps = 1e-6;
const long double pi = acos((long double)-1.0L);
long double torad(long double deg) { return (long double)(deg)*pi / 180.0; }
long double todeg(long double ang) { return ang * 180.0 / pi; }
class Point {
 public:
  long double x, y;
  Point(long double x = 0, long double y = 0) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(long double a) { return Point(a * x, a * y); }
  Point operator/(long double a) { return Point(x / a, y / a); }
  long double abs() { return sqrt(norm()); }
  long double norm() { return x * x + y * y; }
  bool operator<(const Point &p) const {
    return x + eps < p.x || ((fabs((x) - (p.x)) < eps) && y + eps < p.y);
  }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < eps && fabs(y - p.y) < eps;
  }
};
long double norm(Point a) { return a.x * a.x + a.y * a.y; }
long double abs(Point a) { return sqrt(norm(a)); }
long double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
long double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
struct Segment {
  Point p1, p2;
};
bool isOrthogonal(Point a, Point b) {
  return (fabs((dot(a, b)) - (0.0)) < eps);
}
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) {
  return isOrthogonal(a1 - a2, b1 - b2);
}
bool isOrthogonal(Segment s1, Segment s2) {
  return (fabs((dot(s1.p2 - s1.p1, s2.p2 - s2.p1)) - (0.0)) < eps);
}
bool isParallel(Point a, Point b) {
  return (fabs((cross(a, b)) - (0.0)) < eps);
}
bool isParallel(Point a1, Point a2, Point b1, Point b2) {
  return isParallel(a1 - a2, b1 - b2);
}
bool isParallel(Segment s1, Segment s2) {
  return (fabs((cross(s1.p2 - s1.p1, s2.p2 - s2.p1)) - (0.0)) < eps);
}
Point project(Segment s, Point p) {
  Point base = s.p2 - s.p1;
  long double r = dot(p - s.p1, base) / norm(base);
  return s.p1 + base * r;
}
Point reflect(Segment s, Point p) { return p + (project(s, p) - p) * 2.0; }
Point turn(Point p, Point c, long double pi) {
  long double q = atan2(p.y - c.y, p.x - c.x);
  q += pi;
  p = c + Point{cos(q) * abs(p - c), sin(q) * abs(p - c)};
  return p;
}
static const int counter_clockwise = 1;
static const int clockwise = -1;
static const int online_back = 2;
static const int online_front = -2;
static const int on_segment = 0;
int ccw(Point p0, Point p1, Point p2) {
  Point a = p1 - p0;
  Point b = p2 - p0;
  if (cross(a, b) > eps) return counter_clockwise;
  if (cross(a, b) < -eps) return clockwise;
  if (dot(a, b) < -eps) return online_back;
  if (a.norm() < b.norm()) return online_front;
  return on_segment;
}
bool intersect(Point p1, Point p2, Point p3, Point p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
bool intersect(Segment s1, Segment s2) {
  return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}
bool overlap(Segment s1, Segment s2) {
  int a = ccw(s1.p1, s1.p2, s2.p1), b = ccw(s1.p1, s1.p2, s2.p2);
  if (a & 1 || b & 1) return 0;
  if (a == 2) {
    if (b == -2 || (b == 0 && !(s2.p2 == s1.p1)))
      return 1;
    else
      return 0;
  }
  if (a == -2) {
    if (b == 2 || (b == 0 && !(s2.p2 == s1.p2)))
      return 1;
    else
      return 0;
  }
  if (a == 0) {
    if (s1.p1 == s2.p1) {
      if (b != 2)
        return 1;
      else
        return 0;
    } else if (s1.p2 == s2.p1) {
      if (b != -2)
        return 1;
      else
        return 0;
    } else
      return 1;
  }
  return 0;
}
long double getDistance(Point a, Point b) { return abs(a - b); }
long double getDistanceLP(Segment l, Point p) {
  return abs(cross(l.p2 - l.p1, p - l.p1) / abs(l.p2 - l.p1));
}
long double getDistanceSP(Segment s, Point p) {
  if (dot(s.p2 - s.p1, p - s.p1) < 0.0) return abs(p - s.p1);
  if (dot(s.p1 - s.p2, p - s.p2) < 0.0) return abs(p - s.p2);
  return getDistanceLP(s, p);
}
long double getDistance(Segment s1, Segment s2) {
  if (intersect(s1, s2)) return 0.0;
  return min({getDistanceSP(s1, s2.p1), getDistanceSP(s1, s2.p2),
              getDistanceSP(s2, s1.p1), getDistanceSP(s2, s1.p2)});
}
Point getCrossPointS(Segment s1, Segment s2) {
  Point base = s2.p2 - s2.p1;
  long double d1 = abs(cross(base, s1.p1 - s2.p1));
  long double d2 = abs(cross(base, s1.p2 - s2.p1));
  long double t = d1 / (d1 + d2);
  return s1.p1 + (s1.p2 - s1.p1) * t;
}
Point getCrossPointL(Segment l1, Segment l2) {
  Point v1 = l1.p2 - l1.p1, v2 = l2.p2 - l2.p1;
  return l1.p1 + v1 * cross(v2, l2.p1 - l1.p1) / cross(v2, v1);
}
Segment ParallelSegment(Segment s, long double d) {
  Point v = {-(s.p2 - s.p1).y, (s.p2 - s.p1).x};
  v = v / abs(v);
  s.p1 = s.p1 + v * d;
  s.p2 = s.p2 + v * d;
  return s;
}
Point naisin(Point p1, Point p2, Point p3) {
  if (p1 == p2 && p2 == p3 && p3 == p1) return p1;
  return (p1 * abs(p2 - p3) + p2 * abs(p1 - p3) + p3 * abs(p1 - p2)) /
         (abs(p2 - p3) + abs(p1 - p3) + abs(p1 - p2));
}
Point naisin(Segment l1, Segment l2, Segment l3) {
  Point p1 = getCrossPointL(l1, l2), p2 = getCrossPointL(l1, l3),
        p3 = getCrossPointL(l2, l3);
  return naisin(p1, p2, p3);
}
class Circle {
 public:
  Point c;
  long double r;
  Circle(Point c = Point(), long double r = 0.0) : c(c), r(r) {}
};
Point CircleCenter(Point a, Point b, Point c) {
  Point u = a - b, v = a - c;
  long double m1 = (norm(a) - norm(b)) / 2.0, m2 = (norm(a) - norm(c)) / 2.0;
  Point res;
  if (cross(u, v) == 0.0) {
    res.x = 1e9;
    res.y = 1e9;
    return res;
  }
  res.x = (m1 * v.y - m2 * u.y) / cross(u, v);
  res.y = (m1 * v.x - m2 * u.x) / cross(v, u);
  return res;
}
int not_intersect(Circle c1, Circle c2) {
  long double d = getDistance(c1.c, c2.c);
  long double r1 = c1.r, r2 = c2.r;
  if (r1 < r2) {
    if (d < (r2 - r1)) return 1;
  }
  if (r1 > r2) {
    if (d < (r1 - r2)) return 2;
  }
  if (d <= r1 + r2)
    return 0;
  else
    return 3;
}
pair<Point, Point> segCrossPpoints(Circle c, Segment l) {
  Point pr = project(l, c.c);
  Point e = (l.p2 - l.p1) / abs(l.p2 - l.p1);
  long double base = sqrt(c.r * c.r - norm(pr - c.c));
  return make_pair(pr + e * base, pr - e * base);
}
long double arg(Point p) { return atan2(p.y, p.x); }
Point polar(long double a, long double r) {
  return Point(cos(r) * a, sin(r) * a);
}
pair<Point, Point> getCrossPoints(Circle c1, Circle c2) {
  long double d = abs(c1.c - c2.c);
  long double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
  long double t = arg(c2.c - c1.c);
  return make_pair(c1.c + polar(c1.r, t + a), c1.c + polar(c1.r, t - a));
}
vector<Segment> Commontangent(Circle c1, Circle c2) {
  vector<Segment> res;
  Point p = c2.c - c1.c;
  if (abs(p) >= (c1.r + c2.r)) {
    Point a, b;
    a.x = c1.r *
          (p.x * (c1.r + c2.r) +
           p.y * sqrt(norm(p) - (c1.r + c2.r) * (c1.r + c2.r))) /
          norm(p);
    a.y = c1.r *
          (p.y * (c1.r + c2.r) -
           p.x * sqrt(norm(p) - (c1.r + c2.r) * (c1.r + c2.r))) /
          norm(p);
    b.x = c1.r *
          (p.x * (c1.r + c2.r) -
           p.y * sqrt(norm(p) - (c1.r + c2.r) * (c1.r + c2.r))) /
          norm(p);
    b.y = c1.r *
          (p.y * (c1.r + c2.r) +
           p.x * sqrt(norm(p) - (c1.r + c2.r) * (c1.r + c2.r))) /
          norm(p);
    res.push_back(Segment{a + c1.c, a + c1.c + Point{-a.y, a.x}});
    if (!(a == b)) {
      res.push_back(Segment{b + c1.c, b + c1.c + Point{-b.y, b.x}});
    }
  }
  if (abs(p) >= abs(c1.r - c2.r)) {
    Point a, b;
    a.x = c1.r *
          (p.x * (c1.r - c2.r) +
           p.y * sqrt(norm(p) - (c1.r - c2.r) * (c1.r - c2.r))) /
          norm(p);
    a.y = c1.r *
          (p.y * (c1.r - c2.r) -
           p.x * sqrt(norm(p) - (c1.r - c2.r) * (c1.r - c2.r))) /
          norm(p);
    b.x = c1.r *
          (p.x * (c1.r - c2.r) -
           p.y * sqrt(norm(p) - (c1.r - c2.r) * (c1.r - c2.r))) /
          norm(p);
    b.y = c1.r *
          (p.y * (c1.r - c2.r) +
           p.x * sqrt(norm(p) - (c1.r - c2.r) * (c1.r - c2.r))) /
          norm(p);
    res.push_back(Segment{a + c1.c, a + c1.c + Point{-a.y, a.x}});
    if (!(a == b)) {
      res.push_back(Segment{b + c1.c, b + c1.c + Point{-b.y, b.x}});
    }
  }
  return res;
}
int contains(vector<Point> g, Point p) {
  int n = int(g.size());
  bool x = false;
  for (int i = 0; i < n; i++) {
    Point a = g[i] - p, b = g[(i + 1) % n] - p;
    if (a.y > b.y) swap(a, b);
    if (a.y < eps && 0 < b.y && cross(a, b) < 0) x = !x;
    if (abs(cross(a, b)) < eps && dot(a, b) < eps) return 1;
  }
  return (x ? 2 : 0);
}
vector<Point> andrewScan(vector<Point> s, bool ok) {
  vector<Point> u, l;
  sort((s).begin(), (s).end());
  if (int(s.size()) < 3) return s;
  int n = int(s.size());
  u.push_back(s[0]);
  u.push_back(s[1]);
  l.push_back(s[n - 1]);
  l.push_back(s[n - 2]);
  if (ok) {
    for (int i = 2; i < n; i++) {
      for (int j = int(u.size());
           j >= 2 && ccw(u[j - 2], u[j - 1], s[i]) == counter_clockwise; j--) {
        u.pop_back();
      }
      u.push_back(s[i]);
    }
    for (int i = int(s.size()) - 3; i >= 0; i--) {
      for (int j = int(l.size());
           j >= 2 && ccw(l[j - 2], l[j - 1], s[i]) == counter_clockwise; j--) {
        l.pop_back();
      }
      l.push_back(s[i]);
    }
  }
  if (!ok) {
    for (int i = 2; i < n; i++) {
      for (int j = int(u.size());
           j >= 2 && ccw(u[j - 2], u[j - 1], s[i]) != clockwise; j--) {
        u.pop_back();
      }
      u.push_back(s[i]);
    }
    for (int i = int(s.size()) - 3; i >= 0; i--) {
      for (int j = int(l.size());
           j >= 2 && ccw(l[j - 2], l[j - 1], s[i]) != clockwise; j--) {
        l.pop_back();
      }
      l.push_back(s[i]);
    }
  }
  reverse((l).begin(), (l).end());
  for (int i = int(u.size()) - 2; i >= 1; i--) l.push_back(u[i]);
  return l;
}
vector<Point> convex_cut(const vector<Point> &P, const Segment &l) {
  vector<Point> Q;
  for (int i = 0; i < int(P.size()); i++) {
    Point A = P[i], B = P[(i + 1) % int(P.size())];
    if (ccw(l.p1, l.p2, A) != -1) Q.push_back(A);
    if (ccw(l.p1, l.p2, A) * ccw(l.p1, l.p2, B) < 0)
      Q.push_back(getCrossPointL(Segment{A, B}, l));
  }
  return Q;
}
long double area(Point a, Point b, Point c) {
  b = b - a;
  c = c - a;
  return abs(b.x * c.y - b.y * c.x) / 2.0;
}
long double area(vector<Point> &P) {
  if (int(P.size()) == 0) return 0.0;
  long double res = 0;
  Point c = {0.0, 0.0};
  for (int i = 0; i < int(P.size()); i++) {
    c = c + P[i];
  }
  c = c / int(P.size());
  for (int i = 0; i < int(P.size()); i++) {
    res += area(c, P[i], P[(i + 1) % int(P.size())]);
  }
  return res;
}
int main() {
  std::ifstream in("text.txt");
  std::cin.rdbuf(in.rdbuf());
  cin.tie(0);
  ios::sync_with_stdio(false);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int N;
  cin >> N;
  if (N <= 2) {
    cout << -1 << endl;
    return 0;
  };
  vector<Point> P(N);
  Point G = {0, 0};
  for (int i = 0; i < N; i++) {
    cin >> P[i].x >> P[i].y;
    G = G + P[i];
  }
  G = G / N;
  vector<Point> Q(N);
  for (int i = 0; i < N; i++) Q[i] = P[i] - G;
  sort((Q).begin(), (Q).end());
  bool ok = true;
  for (int i = 0; i < N / 2; i++) {
    if (!(Q[i] == Q[N - 1 - i] * (-1))) ok = false;
  }
  if (N & 1) {
    if (!(Q[N / 2] == Point{0, 0})) ok = false;
  }
  if (ok) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> used(N);
  for (int i = 0; i < N; i++) {
    if (used[i]) continue;
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      if (used[j]) continue;
      if (P[i] + P[j] == G + G) {
        used[i] = true;
        used[j] = true;
        break;
      }
    }
  }
  if (N & 1) {
    for (int i = 0; i < N; i++) {
      if (used[i]) continue;
      if (P[i] == G) {
        used[i] = true;
        break;
      }
    }
  }
  vector<Point> PP;
  for (int i = 0; i < N; i++)
    if (!used[i]) PP.push_back(P[i]);
  P = PP;
  N = int(P.size());
  vector<Point> SE;
  int xx = rng() % N;
  for (int i = 0; i < N; i++) {
    Point m = (P[xx] + P[i]) / 2.0;
    Segment s = {m, G};
    s.p2 = s.p2 - s.p1;
    s.p1 = {0, 0};
    swap(s.p2.x, s.p2.y);
    s.p2.y = s.p2.y * (-1);
    if (s.p2.x < 0) {
      s.p2 = s.p2 * (-1);
    }
    vector<Point> R(N);
    Point GG = project(s, G);
    for (int j = 0; j < N; j++) {
      R[j] = project(s, P[j]);
    }
    for (int j = 0; j < N; j++) R[j] = R[j] - GG;
    sort((R).begin(), (R).end());
    bool ok = true;
    for (int j = 0; j < N / 2; j++) {
      if (!(R[j] == R[N - 1 - j] * (-1))) ok = false;
    }
    if (ok) {
      long double dd = s.p2.abs();
      s.p2 = s.p2 / dd;
      SE.push_back(s.p2);
    }
  }
  sort((SE).begin(), (SE).end());
  SE.erase(unique((SE).begin(), (SE).end()), SE.end());
  cout << int(SE.size()) << endl;
}
