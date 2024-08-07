#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int MaxN = 1005;
const int MaxE = MaxN * 4;
const double pi = acos(-1.0);
const double pi2 = 2 * acos(-1.0);
inline int sgn(double x) { return x < -eps ? -1 : x > eps; }
pair<double, int> e[MaxE];
double x[MaxN], y[MaxN], r[MaxN];
int n, en, K, cnt;
inline bool comp(const pair<double, int>& lhs, const pair<double, int>& rhs) {
  if (sgn(lhs.first - rhs.first))
    return lhs.first < rhs.first;
  else
    return lhs.second < rhs.second;
}
inline void read() {
  for (int i = 0; i < n; i++) scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
}
inline double def(double x) {
  while (sgn(x) < 0) x += pi2;
  while (sgn(x - pi2) >= 0) x -= pi2;
  return x;
}
inline void add_e(double low, double high) {
  low = def(low);
  high = def(high);
  e[en++] = make_pair(low, 1);
  e[en++] = make_pair(high, -1);
  if (sgn(low - high) > 0) cnt++;
}
inline long long doit() {
  int ret = 1;
  for (int i = 0; i < n; i++) {
    en = 0;
    cnt = 0;
    e[en++] = make_pair(0, 1);
    e[en++] = make_pair(pi2, -1);
    for (int j = 0; j < n; j++)
      if (i ^ j) {
        double d = hypot(x[j] - x[i], y[j] - y[i]);
        double ang = atan2(y[j] - y[i], x[j] - x[i]);
        double alpha = pi / 2.0 - asin((r[i] - r[j]) / d);
        double beta = pi / 2.0 - asin((r[i] + r[j]) / d);
        add_e(ang - alpha, ang - beta);
        add_e(ang + beta, ang + alpha);
      }
    sort(e, e + en, comp);
    for (int j = 0; j < en; j++) {
      cnt += e[j].second;
      ret = max(ret, cnt);
    }
  }
  return (long long)K * (K + 1) / 2 + 1 + (long long)(ret - 1) * (K + 1) + n -
         ret;
}
int main() {
  while (scanf("%d%d", &n, &K) == 2) {
    read();
    printf("%I64d\n", doit());
  }
  return 0;
}
