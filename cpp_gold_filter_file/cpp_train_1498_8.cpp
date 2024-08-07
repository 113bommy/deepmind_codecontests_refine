#include <bits/stdc++.h>
using namespace std;
const long long one = 1000000;
const long double fone = 1e6;
struct pr {
  int ss, sl, ts, tl;
  long long pf;
  long double ppf;
  bool operator<(const pr &a) const {
    return tl * pf * (one - a.pf) < a.tl * a.pf * (one - pf);
  }
} ps[1010];
pair<long long, long double> f[1616];
int main() {
  int n, t;
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; i++) {
    double pf;
    scanf("%d%d%d%d%lf", &ps[i].ss, &ps[i].sl, &ps[i].ts, &ps[i].tl, &pf);
    ps[i].pf = pf * one + 0.5;
    ps[i].ppf = pf;
  }
  sort(ps, ps + n);
  for (int i = 1; i <= t; i++) f[i] = make_pair(0ll, (long double)(-9e18));
  for (int i = 0; i < n; i++) {
    for (int j = t - ps[i].ts; j >= 0; j--) {
      f[j + ps[i].ts] =
          max(f[j + ps[i].ts],
              make_pair(f[j].first + ps[i].ss * one, f[j].second - ps[i].ts));
      if (j + ps[i].ts + ps[i].tl <= t)
        f[j + ps[i].ts + ps[i].tl] = max(
            f[j + ps[i].ts + ps[i].tl],
            make_pair(f[j].first + ps[i].ss * one + ps[i].sl * (one - ps[i].pf),
                      (f[j].second - ps[i].ts) * (ps[i].ppf) -
                          (j + ps[i].tl + ps[i].ts) * (1 - ps[i].ppf)));
    }
  }
  pair<long long, long double> ans = make_pair(0ll, (long double)(-9e18));
  for (int i = 0; i <= t; i++) ans = max(ans, f[i]);
  printf("%.10lf %.10lf", ans.first * 1e-6, (double)-ans.second);
}
