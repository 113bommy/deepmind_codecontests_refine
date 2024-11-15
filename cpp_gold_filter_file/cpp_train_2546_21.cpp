#include <bits/stdc++.h>
using namespace std;
struct wall {
  double x, y;
  bool operator<(const wall& rhs) const { return x < rhs.x; }
  wall(double x = 0, double y = 0) : x(x), y(y) {}
};
struct cann {
  double ang;
  int pos;
  bool operator<(const cann& rhs) const { return ang < rhs.ang; }
};
wall wal[100005];
cann bul[10005];
wall res[10005];
wall rt[10005];
double v;
int n, m;
double eval(double ang, double x) {
  return (x * sin(ang * 2) / 2 - 9.8 * x * x / (2 * v * v)) /
         (cos(ang) * cos(ang));
}
double fall(double ang) { return v * v * sin(ang * 2) / 9.8; }
double fcmp(double x) {
  if (fabs(x) < 1e-8) return 0;
  if (x > 0) return 1;
  return -1;
}
void work() {
  int i, p;
  p = 1;
  for (i = 1; i <= n; ++i) {
    while (p <= m && fcmp(eval(bul[i].ang, wal[p].x) - wal[p].y) >= 0) ++p;
    if (p > m || fcmp(eval(bul[i].ang, wal[p].x)) <= 0)
      rt[i] = wall(fall(bul[i].ang), 0);
    else
      rt[i] = wall(wal[p].x, eval(bul[i].ang, wal[p].x));
  }
}
int main() {
  int i;
  scanf("%d%lf", &n, &v);
  for (i = 1; i <= n; ++i) {
    scanf("%lf", &bul[i].ang);
    bul[i].pos = i;
  }
  scanf("%d", &m);
  for (i = 1; i <= m; ++i) scanf("%lf%lf", &wal[i].x, &wal[i].y);
  sort(&bul[1], &bul[n + 1]);
  sort(&wal[1], &wal[m + 1]);
  work();
  for (i = 1; i <= n; ++i) res[bul[i].pos] = rt[i];
  for (i = 1; i <= n; ++i) printf("%.8lf %.8lf\n", res[i].x, res[i].y);
  return 0;
}
