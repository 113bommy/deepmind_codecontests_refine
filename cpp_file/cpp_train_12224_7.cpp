#include <bits/stdc++.h>
using namespace std;
const long long N = 1005, mo = 1e9 + 7;
bool dy(long double x, long double y) { return (fabs(x - y) < 1e-9); }
struct node {
  long double x, y, k;
} mid[N * N];
long double x[N], y[N];
long long ans, tot;
bool cmp(node a, node b) {
  if (dy(a.x, b.x)) {
    if (dy(a.y, b.y)) {
      return a.k < b.k;
    }
    return a.y < b.y;
  }
  return a.x < b.x;
}
signed main() {
  long long n;
  scanf("%lld", &n);
  for (long long i = 1; i <= n; ++i) {
    long double a, b, c, d, e, f;
    scanf("%Lf%Lf%Lf%Lf", &a, &b, &c, &d);
    e = a / b;
    f = c / d;
    x[i] = e / (e * e + f * f);
    y[i] = f / (e * e + f * f);
  }
  for (long long i = 1; i <= n; ++i)
    for (long long j = i + 1; j <= n; ++j) {
      mid[++tot].x = x[i] + x[j];
      mid[tot].y = y[i] + y[j];
      mid[tot].k = dy(x[i], x[j]) ? 1e9 : (y[i] - y[j]) / (x[i] - x[j]);
    }
  sort(mid + 1, mid + tot + 1, cmp);
  long long i, j;
  for (i = 1; i <= tot; i = j) {
    long long cnt = 1;
    long long res = 1;
    for (j = i + 1;
         j <= tot && dy(mid[j].x, mid[i].x) && dy(mid[j].y, mid[i].y); j++) {
      if (dy(mid[j].k, mid[j - 1].k))
        cnt++;
      else
        res = res * (cnt + 1) % mo, cnt = 1;
    }
    res = res * (cnt + 1) % mo;
    ans = (ans + res - 1) % mo;
  }
  printf("%d\n", ans - tot);
}
