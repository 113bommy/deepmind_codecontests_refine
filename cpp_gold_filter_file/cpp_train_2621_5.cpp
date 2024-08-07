#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
  Point(double _x, double _y) : x(_x), y(_y) {}
  Point() {}
} C, TmpC;
vector<Point> P;
int x[900], y[900], z[900];
double R, TmpR;
int n, m;
Point chg(int a, int b, int c, int d, int e, int f) {
  if (a == 0 && b == 0) return Point(d, e);
  if (b == 0 && c == 0) return Point(e, f);
  if (a == 0 && c == 0) return Point(d, f);
  double t = (a * d + b * e + c * f + 0.0) / (a * a + b * b + c * c);
  double x = d - t * a, y = e - t * b, z = f - t * c;
  double aa = sqrt(x * x + y * y + z * z), bb = sqrt(b * b + c * c),
         cc = sqrt(x * x + (y + c) * (y + c) + (z - b) * (z - b));
  if (fabs(aa) < 1e-12) return Point(0, 0);
  double ang = acos((aa * aa + bb * bb - cc * cc) / (aa * bb * 2));
  if (x < 0) ang = -ang;
  return Point(aa * cos(ang), aa * sin(ang));
}
Point GetC(Point &A, Point &B, Point &C) {
  double a = A.x - B.x, b = A.y - B.y,
         c = A.x * A.x + A.y * A.y - B.x * B.x - B.y * B.y;
  c /= 2;
  double d = A.x - C.x, e = A.y - C.y,
         f = A.x * A.x + A.y * A.y - C.x * C.x - C.y * C.y;
  f /= 2;
  return Point((c * e - b * f) / (a * e - d * b),
               (a * f - d * c) / (a * e - b * d));
}
double Dis(Point &A, Point &B) {
  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> z[i];
  for (int j = 0; j < m; ++j) {
    int a, b, c;
    cin >> a >> b >> c;
    P.clear();
    for (int i = 0; i < n; ++i) P.push_back(chg(a, b, c, x[i], y[i], z[i]));
    random_shuffle(P.begin(), P.end());
    C = P[0];
    R = 0;
    for (int i = 1, j, k; i < n; ++i)
      if (Dis(P[i], C) > R + 1e-12) {
        C = P[i];
        R = 0;
        for (j = 0; j < i; ++j)
          if (Dis(P[j], C) > R + 1e-12) {
            C = Point((P[i].x + P[j].x) / 2, (P[i].y + P[j].y) / 2);
            R = Dis(P[j], C);
            for (k = 0; k < j; ++k)
              if (Dis(C, P[k]) > R + 1e-12)
                R = Dis(P[i], C = GetC(P[i], P[j], P[k]));
          }
      }
    cout << fixed << setprecision(9) << R << endl;
  }
  return 0;
}
