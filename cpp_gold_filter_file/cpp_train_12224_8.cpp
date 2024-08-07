#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int maxn = 1005, M = 1000000007;
inline int dcmp(const double &x) { return x > eps ? 1 : (x < -eps ? -1 : 0); }
int n, m;
struct point {
  double x, y;
  point(const double &xx = 0, const double &yy = 0) : x(xx), y(yy) {}
} p[maxn];
struct pp {
  double sx, sy, t;
  pp() {}
  pp(const double &x1, const double &x2, const double &x3)
      : sx(x1), sy(x2), t(x3){};
  inline bool operator<(const pp &o) const {
    return dcmp(sx - o.sx) ? sx < o.sx
                           : (dcmp(sy - o.sy) ? sy < o.sy : t < o.t);
  }
} q[maxn * maxn];
void init() {
  scanf("%d", &n);
  double x, y, a, b, c, d;
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    x = a / b, y = c / d;
    p[i] = point(x / (x * x + y * y), y / (x * x + y * y));
  }
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) {
      a = dcmp(p[i].x - p[j].x) ? (p[j].y - p[i].y) / (p[j].x - p[i].x) : 1e10;
      q[++m] = pp(p[i].x + p[j].x, p[i].y + p[j].y, a);
    }
  sort(q + 1, q + m + 1);
}
void work() {
  int ans = 0;
  for (int i = 1, j, c, t; i <= m; i = j) {
    c = t = 1;
    for (j = i + 1;
         dcmp(q[j].sx - q[i].sx) == 0 && dcmp(q[j].sy - q[i].sy) == 0; j++)
      if (dcmp(q[j].t - q[j - 1].t))
        c = (long long)c * (t + 1) % M, t = 1;
      else
        t++;
    c = (long long)c * (t + 1) % M;
    ans = (ans + c - 1) % M;
  }
  ans -= m;
  if (ans < 0) ans += M;
  printf("%d\n", ans);
}
int main() {
  init();
  work();
  return 0;
}
