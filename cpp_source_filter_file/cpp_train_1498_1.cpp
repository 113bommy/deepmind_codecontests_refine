#include <bits/stdc++.h>
const long double eps = 1e-10;
inline int sign(const long double x) { return x < -eps ? -1 : x > eps; }
int n, t;
struct submit {
  long double p;
  int ts, tl, ss, sl;
  bool operator<(const submit &o) const {
    return ts * p * (1 - o.p) < o.ts * o.p * (1 - p);
  }
} s[1009];
struct dp {
  long double s, t;
  void update(long double ns, long double nt) {
    if (sign(s - ns) < 0 || !sign(s - ns) && t > nt) s = ns, t = nt;
  }
} f[2009];
int main() {
  scanf("%d%d", &n, &t);
  for (int i = 1; i <= n; ++i) {
    double x;
    scanf("%d%d%d%d%lf", &s[i].ss, &s[i].sl, &s[i].ts, &s[i].tl, &x);
    s[i].p = x;
  }
  std::sort(s + 1, s + 1 + n);
  for (int i = 1; i <= n; ++i)
    for (int j = t, k; j; --j) {
      if ((k = j - s[i].ts - s[i].tl) >= 0)
        f[j].update(f[k].s + s[i].ss + s[i].sl * (1 - s[i].p),
                    (f[k].t + s[i].ts) * s[i].p + j * (1 - s[i].p));
      if ((k = j - s[i].ts) >= 0)
        f[j].update(f[k].s + s[i].ss, f[k].t + s[i].ts);
    }
  for (int i = 0; i <= t; ++i) f[t + 1].update(f[i].s, f[i].t);
  printf("%.18f %.18f\n", (double)f[t + 1].s, (double)f[t + 1].t);
}
