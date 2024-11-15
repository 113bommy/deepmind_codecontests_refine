#include <bits/stdc++.h>
using namespace std;
void rot(int, int *, int *, int, int);
int xy2d(int n, int x, int y) {
  int rx, ry, s, d = 0;
  for (s = n / 2; s > 0; s /= 2) {
    rx = (x & s) > 0;
    ry = (y & s) > 0;
    d += s * s * ((3 * rx) ^ ry);
    rot(s, &x, &y, rx, ry);
  }
  return d;
}
void d2xy(int n, int d, int *x, int *y) {
  int rx, ry, s, t = d;
  *x = *y = 0;
  for (s = 1; s < n; s *= 2) {
    rx = 1 & (t / 2);
    ry = 1 & (t ^ rx);
    rot(s, x, y, rx, ry);
    *x += s * rx;
    *y += s * ry;
    t /= 4;
  }
}
void rot(int n, int *x, int *y, int rx, int ry) {
  int t;
  if (ry == 0) {
    if (rx == 1) {
      *x = n - 1 - *x;
      *y = n - 1 - *y;
    }
    t = *x;
    *x = *y;
    *y = t;
  }
}
int main() {
  int N, D;
  cin >> N >> D;
  int x, y;
  d2xy(800000000, D, &x, &y);
  cout << x << " " << y << endl;
  return 0;
}
