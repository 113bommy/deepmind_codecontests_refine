#include <bits/stdc++.h>
using namespace std;
int x[3], y123[3], r[3];
long double sqr(long double x) { return x * x; }
long double dist(long double x1, long double y1) {
  long double d1 = sqrt(sqr(x1 - x[0]) + sqr(y1 - y123[0])) / r[0];
  long double d2 = sqrt(sqr(x1 - x[1]) + sqr(y1 - y123[1])) / r[1];
  long double d3 = sqrt(sqr(x1 - x[2]) + sqr(y1 - y123[2])) / r[2];
  return sqr(d1 - d2) + sqr(d2 - d3) + sqr(d3 - d1);
}
int main() {
  long double eps = 0.00001, sx = 0, sy = 0;
  for (int i = 0; i < 3; i++) {
    cin >> x[i] >> y123[i] >> r[i];
    sx += x[i];
    sy += y123[i];
  }
  sx /= 3;
  sy /= 3;
  long double ans = dist(sx, sy);
  long double q = 10;
  while (q > eps) {
    bool f = true;
    for (int i = -1; i < 2; i++)
      for (int j = -1; j < 2; j++)
        if (dist(sx + i * q, sy + j * q) < ans) {
          ans = dist(sx + i * q, sy + j * q);
          sx += i * q;
          sy += j * q;
          f = false;
          break;
        }
    if (f) q /= 2;
  }
  if (ans > eps) return 0;
  cout.precision(5);
  cout << fixed << sx << " " << sy;
}
