#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
double INF = 1e100;
double EPS = 1e-12;
struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y) {}
  PT operator+(const PT &p) const { return PT(x + p.x, y + p.y); }
  PT operator-(const PT &p) const { return PT(x - p.x, y - p.y); }
  PT operator*(double c) const { return PT(x * c, y * c); }
  PT operator/(double c) const { return PT(x / c, y / c); }
};
double dot(PT p, PT q) { return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q) { return dot(p - q, p - q); }
double cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  return os << "(" << p.x << "," << p.y << ")";
}
PT RotateCCW90(PT p) { return PT(-p.y, p.x); }
PT RotateCW90(PT p) { return PT(p.y, -p.x); }
PT RotateCCW(PT p, double t) {
  return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}
PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b - a, b - a);
  if (fabs(r) < EPS) return a;
  r = dot(c - a, b - a) / r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b - a) * r;
}
double DistancePointSegment(PT a, PT b, PT c) {
  return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}
double DistancePointPlane(double x, double y, double z, double a, double b,
                          double c, double d) {
  return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}
bool LinesParallel(PT a, PT b, PT c, PT d) {
  return fabs(cross(b - a, c - d)) < EPS;
}
bool LinesCollinear(PT a, PT b, PT c, PT d) {
  return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < EPS &&
         fabs(cross(c - d, c - a)) < EPS;
}
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS || dist2(b, c) < EPS ||
        dist2(b, d) < EPS)
      return true;
    if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0 && dot(c - b, d - b) > 0)
      return false;
    return true;
  }
  if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return false;
  if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return false;
  return true;
}
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b = b - a;
  d = c - d;
  c = c - a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b * cross(c, d) / cross(b, d);
}
PT ComputeCircleCenter(PT a, PT b, PT c) {
  b = (a + b) / 2;
  c = (a + c) / 2;
  return ComputeLineIntersection(b, b + RotateCW90(a - b), c,
                                 c + RotateCW90(a - c));
}
bool PointInPolygon(const vector<PT> &p, PT q) {
  bool c = 0;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    if ((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) &&
        q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}
bool PointOnPolygon(const vector<PT> &p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < EPS)
      return true;
  return false;
}
vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r) {
  vector<PT> ret;
  b = b - a;
  a = a - c;
  double A = dot(b, b);
  double B = dot(a, b);
  double C = dot(a, a) - r * r;
  double D = B * B - A * C;
  if (D < -EPS) return ret;
  ret.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
  if (D > EPS) ret.push_back(c + a + b * (-B - sqrt(D)) / A);
  return ret;
}
vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R) {
  vector<PT> ret;
  double d = sqrt(dist2(a, b));
  if (d > r + R || d + min(r, R) < max(r, R)) return ret;
  double x = (d * d - R * R + r * r) / (2 * d);
  double y = sqrt(r * r - x * x);
  PT v = (b - a) / d;
  ret.push_back(a + v * x + RotateCCW90(v) * y);
  if (y > 0) ret.push_back(a + v * x - RotateCCW90(v) * y);
  return ret;
}
double ComputeSignedArea(const vector<PT> &p) {
  double area = 0;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    area += p[i].x * p[j].y - p[j].x * p[i].y;
  }
  return area / 2.0;
}
double ComputeArea(const vector<PT> &p) { return fabs(ComputeSignedArea(p)); }
PT ComputeCentroid(const vector<PT> &p) {
  PT c(0, 0);
  double scale = 6.0 * ComputeSignedArea(p);
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    c = c + (p[i] + p[j]) * (p[i].x * p[j].y - p[j].x * p[i].y);
  }
  return c / scale;
}
bool IsSimple(const vector<PT> &p) {
  for (int i = 0; i < p.size(); i++) {
    for (int k = i + 1; k < p.size(); k++) {
      int j = (i + 1) % p.size();
      int l = (k + 1) % p.size();
      if (i == l || j == k) continue;
      if (SegmentsIntersect(p[i], p[j], p[k], p[l])) return false;
    }
  }
  return true;
}
bool cmp(PT a, PT b) { return make_pair(a.x, a.y) < make_pair(b.x, b.y); }
void convex(vector<PT> &poly) {
  vector<PT> res;
  if (poly.size() <= 3) {
    poly.clear();
    return;
  }
  for (int i = 0; i < (int)poly.size(); i++) {
    while (res.size() >= 2 && cross(res.back() - res[res.size() - 2],
                                    poly[i] - res[res.size() - 2]) >= 0) {
      res.pop_back();
    }
    res.push_back(poly[i]);
  }
  int t = res.size();
  for (int i = (int)poly.size() - 2; i >= 0; i--) {
    while (res.size() > t && cross(res.back() - res[res.size() - 2],
                                   poly[i] - res[res.size() - 2]) >= 0) {
      res.pop_back();
    }
    res.push_back(poly[i]);
  }
  res.pop_back();
  poly = res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  double h, f;
  cin >> n >> h >> f;
  vector<pair<double, double> > v(n);
  double res = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    vector<PT> poly(4);
    poly[0] = {v[i].first, h};
    poly[1] = {v[i].second, h};
    poly[2] = {(-h - f) * (-v[i].second) / (f - h), -h};
    poly[3] = {(-h - f) * (-v[i].first) / (f - h), -h};
    res += 2.0 * ComputeArea(poly);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      vector<PT> poly;
      if (!LinesParallel(PT(0, f), PT(v[i].second, h), PT(0, -f),
                         PT(v[j].second, -h))) {
        poly.push_back(ComputeLineIntersection(PT(0, f), PT(v[i].second, h),
                                               PT(0, -f), PT(v[j].second, -h)));
        if (poly.back().y >= h || poly.back().y <= -h) {
          poly.pop_back();
        }
      }
      if (!LinesParallel(PT(0, f), PT(v[i].first, h), PT(0, -f),
                         PT(v[j].second, -h))) {
        poly.push_back(ComputeLineIntersection(PT(0, f), PT(v[i].first, h),
                                               PT(0, -f), PT(v[j].second, -h)));
        if (poly.back().y >= h || poly.back().y <= -h) {
          poly.pop_back();
        }
      }
      if (!LinesParallel(PT(0, f), PT(v[i].second, h), PT(0, -f),
                         PT(v[j].first, -h))) {
        poly.push_back(ComputeLineIntersection(PT(0, f), PT(v[i].second, h),
                                               PT(0, -f), PT(v[j].first, -h)));
        if (poly.back().y >= h || poly.back().y <= -h) {
          poly.pop_back();
        }
      }
      if (!LinesParallel(PT(0, f), PT(v[i].first, h), PT(0, -f),
                         PT(v[j].first, -h))) {
        poly.push_back(ComputeLineIntersection(PT(0, f), PT(v[i].first, h),
                                               PT(0, -f), PT(v[j].first, -h)));
        if (poly.back().y >= h || poly.back().y <= -h) {
          poly.pop_back();
        }
      }
      double l, r;
      r = (-h - f) * (-v[i].second) / (f - h);
      if (r >= v[j].first && r <= v[j].second) {
        poly.push_back(PT(r, -h));
      }
      l = (-h - f) * (-v[i].first) / (f - h);
      if (l >= v[j].first && l <= v[j].second) {
        poly.push_back(PT(l, -h));
      }
      if (v[j].first >= l && v[j].first <= r) {
        poly.push_back(PT(v[j].first, -h));
      }
      if (v[j].second >= l && v[j].second <= r) {
        poly.push_back(PT(v[j].second, -h));
      }
      r = (h + f) * (-v[j].second) / (-f + h);
      if (r >= v[i].first && r <= v[i].second) {
        poly.push_back(PT(r, h));
      }
      l = (h + f) * (-v[j].first) / (-f + h);
      if (l >= v[i].first && l <= v[i].second) {
        poly.push_back(PT(l, h));
      }
      if (v[i].first >= l && v[i].first <= r) {
        poly.push_back(PT(v[i].first, h));
      }
      if (v[i].second >= l && v[i].second <= r) {
        poly.push_back(PT(v[i].second, h));
      }
      sort(poly.begin(), poly.end(), cmp);
      convex(poly);
      res -= ComputeArea(poly);
    }
  }
  cout << fixed << setprecision(6) << res << '\n';
  return 0;
}
