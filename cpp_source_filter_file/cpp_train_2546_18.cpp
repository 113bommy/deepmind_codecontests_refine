#include <bits/stdc++.h>
using namespace std;
const double g = 9.8;
int n, v, m;
struct cannon {
  double a;
  int yw;
} a[10001];
struct wall {
  double x, y;
} b[100001];
double ansx[10001], ansy[10001];
int cmp(cannon x, cannon y) { return x.a < y.a; }
int cmp2(wall x, wall y) { return x.x < y.x || x.x == y.x && x.y < y.y; }
int main() {
  int i, j, k;
  scanf("%d%d", &n, &v);
  for (i = 1; i <= n; i++) {
    scanf("%lf", &a[i].a);
    a[i].yw = i;
  }
  scanf("%d", &m);
  for (i = 1; i <= m; i++) scanf("%lf%lf", &b[i].x, &b[i].y);
  sort(a + 1, a + n + 1, cmp);
  sort(b + 1, b + m + 1, cmp2);
  for (i = 1, j = 1; i <= n; i++) {
    double t, x, y;
    while (j <= n) {
      t = b[j].x / (v * cos(a[i].a));
      y = t * v * sin(a[i].a) - g * t * t / 2;
      if (y > b[j].y - 1e-4)
        j++;
      else
        break;
    }
    if (j > n || y <= 0) {
      t = v * sin(a[i].a) * 2 / g;
      ansx[a[i].yw] = v * cos(a[i].a) * t;
      ansy[a[i].yw] = 0;
    } else {
      ansx[a[i].yw] = b[j].x;
      ansy[a[i].yw] = y;
    }
  }
  for (i = 1; i <= n; i++) printf("%lf %lf\n", ansx[i], ansy[i]);
  return 0;
}
