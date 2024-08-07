#include <bits/stdc++.h>
using namespace std;
int n, h;
double p;
int was[2002][2002][2][2];
double mem[2002][2002][2][2];
int a[2222];
int nl[2222], nr[2222];
double go(int x, int y, int xx, int yy) {
  int d = a[x - 1];
  if (xx) d += h;
  int xl = min(a[x] - d, h);
  d = a[y + 1];
  if (yy == 0) d -= h;
  int yr = min(d - a[y], h);
  if (x == y) {
    return p * xl + (1 - p) * yr;
  }
  if (was[x][y][xx][yy]) return mem[x][y][xx][yy];
  double ret = 1. / 2 * p * (xl + go(x + 1, y, 0, yy)) +
               1. / 2 * (1 - p) * (yr + go(x, y - 1, xx, 1));
  int g = nr[x];
  if (g < y) {
    ret += 1. / 2 * (1 - p) * (a[g] + h - a[x] + go(g + 1, y, 1, yy));
  } else {
    ret += 1. / 2 * (1 - p) * (a[y] - a[x] + yr);
  }
  g = nl[y];
  if (g > x) {
    ret += 1. / 2 * p * (a[y] - a[g] + h + go(x, g - 1, xx, 0));
  } else {
    ret += 1. / 2 * p * (a[y] - a[x] + xl);
  }
  was[x][y][xx][yy] = 1;
  mem[x][y][xx][yy] = ret;
  return ret;
}
int main() {
  cin >> n >> h >> p;
  for (int i = 0; i < n; i++) cin >> a[i];
  a[n++] = -5e8;
  a[n++] = 5e8;
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (i == 0 || a[i] - a[i - 1] > h)
      nl[i] = i;
    else
      nl[i] = nl[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (i == n - 1 || a[i + 1] - a[i] > h)
      nr[i] = i;
    else
      nr[i] = nr[i + 1];
  }
  double ans = go(1, n - 2, 0, 1);
  printf("%.10lf\n", ans);
  return 0;
}
