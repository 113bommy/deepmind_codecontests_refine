#include <bits/stdc++.h>
using namespace std;
int n, t;
struct ty {
  int ss, sl, ts, tl;
  long double p;
} s[1010];
struct ty2 {
  long double maxx, mint1, mint2, mint3;
} ans[1010][1600], tmp;
bool cmp(ty c1, ty c2) {
  return (long double)c1.tl / c1.p - c1.tl < (long double)c2.tl / c2.p - c2.tl;
}
bool operator<(ty2 c1, ty2 c2) {
  if (c1.maxx - c2.maxx < 1e-10 && c2.maxx - c1.maxx < 1e-10)
    return c1.mint1 + c1.mint2 > c2.mint1 + c2.mint2;
  return c1.maxx < c2.maxx;
}
int main() {
  int i, j;
  double x;
  scanf("%d%d", &n, &t);
  for (i = 1; i <= n; ++i) {
    scanf("%d%d%d%d%lf", &s[i].ss, &s[i].sl, &s[i].ts, &s[i].tl, &x);
    s[i].p = 1.0 - x;
  }
  sort(s + 1, s + n + 1, cmp);
  for (i = 1; i <= n; ++i) {
    for (j = 0; j <= t; ++j) ans[i][j] = ans[i - 1][j];
    for (j = s[i].ts; j <= t; ++j) {
      tmp = ans[i - 1][j - s[i].ts];
      tmp.maxx += s[i].ss;
      tmp.mint1 += s[i].ts;
      if (ans[i][j] < tmp) ans[i][j] = tmp;
    }
    for (j = s[i].ts + s[i].tl; j <= t; ++j) {
      tmp = ans[i - 1][j - s[i].ts - s[i].tl];
      tmp.maxx += s[i].ss + s[i].p * s[i].sl;
      tmp.mint1 += s[i].ts;
      tmp.mint3 += s[i].tl;
      tmp.mint2 = tmp.mint2 * (1.0 - s[i].p) + s[i].p * tmp.mint3;
      if (ans[i][j] < tmp) ans[i][j] = tmp;
    }
  }
  printf("%.20lf %.20lf\n", (double)ans[n][t].maxx,
         (double)ans[n][t].mint1 + ans[n][t].mint2);
  return 0;
}
