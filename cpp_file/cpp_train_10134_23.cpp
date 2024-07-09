#include <bits/stdc++.h>
using namespace std;
long double EPS = 0.000001;
long double get_time(int _a, int _d, int _v, int _t) {
  long double a = _a, d = _d, v = _v, t = _t;
  if (2.0 * d * a < v * v + EPS)
    t += sqrt(2.0 * d / a);
  else
    t += d / v + v / (2.0 * a);
  return t;
}
int main() {
  int n, a, d;
  scanf(" %d %d %d", &n, &a, &d);
  long double prev = 0.0;
  for (int i = 0; i < n; i++) {
    int t, v;
    scanf(" %d %d", &t, &v);
    long double T = get_time(a, d, v, t);
    if (T + EPS > prev) {
      printf("%Lf\n", T);
      prev = T;
    } else {
      printf("%Lf\n", prev);
    }
  }
  return 0;
}
