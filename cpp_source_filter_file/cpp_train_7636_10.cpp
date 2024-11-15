#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y;
} a[40];
double eps = 1e-9;
bool check(point a, point b, point c) {
  if (fabs((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)) < eps)
    return true;
  return false;
}
int ch(point a, point b, point c) {
  double v = ((a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x));
  if (abs(v) < eps) return 0;
  if (v < -eps) return -1;
  return 1;
}
double xc, yc;
pair<double, double> center(point a, point b, point c) {
  double a1 = a.y - b.y, b1 = c.y - b.y,
         c1 = ((a.x + b.x) / 2 - (c.x + b.x) / 2);
  double a2 = b.x - a.x, b2 = b.x - c.x,
         c2 = ((a.y + b.y) / 2 - (b.y + c.y) / 2);
  if (fabs(a1) < eps) {
    yc = -c1 / b1;
    xc = (-c2 - b2 * yc) / a2;
    goto l;
  }
  if (fabs(a2) < eps) {
    yc = -c2 / b2;
    xc = (-c1 - b1 * yc) / a1;
    goto l;
  }
  yc = (c1 * a2 - a1 * c2) / (b2 * a1 - b1 * a2);
  xc = (-c1 - b1 * yc) / a1;
l:
  double v = xc;
  xc = (a.y - b.y) * v + (a.x + b.x) / 2;
  yc = (b.x - a.x) * v + (a.y + b.y) / 2;
}
bool solve(point a, point b, point c) {
  point d;
  d.x = b.x + b.x - c.x;
  d.y = b.y + b.y - c.y;
  point A, B, C, D;
  if (!check(a, b, d)) {
    center(a, b, d);
    B.x = xc;
    B.y = yc;
  } else
    return false;
  d.x = b.x + (b.x - a.x);
  d.y = b.y + b.y - a.y;
  if (!check(b, c, d)) {
    center(b, c, d);
    C.x = xc;
    C.y = yc;
  } else
    return false;
  A.x = a.x + a.x - B.x;
  A.y = a.y + a.y - B.y;
  D.x = c.x + c.x - C.x;
  D.y = c.y + c.y - C.y;
  double l = ch(A, B, C) + ch(B, C, D) + ch(C, D, A) + ch(D, A, B);
  if (l != 4 && l != -4) return false;
  printf("YES\n%.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf\n", A.x, A.y,
         B.x, B.y, C.x, C.y, D.x, D.y);
  return true;
}
int main() {
  int t, i;
  scanf("%d", &t);
  while (t--) {
    for (i = 0; i < 3; i++) scanf("%f%f", &a[i].x, &a[i].y);
    if (check(a[0], a[1], a[2]) ||
        !solve(a[0], a[1], a[2]) && !solve(a[0], a[2], a[1]) &&
            !solve(a[1], a[0], a[2]) && !solve(a[1], a[2], a[0]) &&
            !solve(a[2], a[0], a[1]) && !solve(a[2], a[1], a[0]))
      puts("NO\n");
  }
  return 0;
}
