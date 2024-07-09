#include <bits/stdc++.h>
using namespace std;
const long double eps = 0.000000000001;
int n, fl;
long long T, tt, t;
long double l, r, mx, tmx, c;
struct O {
  long long p, t;
  long double l, r;
} a[150005];
bool cmp(O a, O b) {
  return a.p * b.t == b.p * a.t ? a.p < b.p : a.p * b.t > b.p * a.t;
}
bool cms(O a, O b) { return a.p < b.p; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i].p);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i].t), T += a[i].t;
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1, j; i <= n; i = j) {
    tt = 0;
    for (j = i; j <= n && a[j].p * a[i].t == a[i].p * a[j].t; ++j)
      tt += a[j].t, a[j].l = -(long double)(t + a[j].t) * a[j].p / T;
    t += tt;
    for (j = i; j <= n && a[j].p * a[i].t == a[i].p * a[j].t; ++j)
      a[j].r = -(long double)t * a[j].p / T;
  }
  sort(a + 1, a + n + 1, cms);
  l = 0;
  r = 1;
  while (r - l > 0.00000000001) {
    mx = 0;
    c = (l + r) / 2;
    fl = 1;
    for (int i = 1, j; i <= n; i = j) {
      tmx = 0;
      for (j = i; j <= n && a[j].p == a[i].p; ++j) {
        if (a[j].r * c + a[j].p < mx - eps) {
          fl = 0;
          break;
        }
        tmx = max(tmx, a[j].l * c + a[j].p);
      }
      if (!fl) break;
      mx = max(mx, tmx);
    }
    if (fl)
      l = c;
    else
      r = c;
  }
  printf("%.9Lf\n", l);
  return 0;
}
