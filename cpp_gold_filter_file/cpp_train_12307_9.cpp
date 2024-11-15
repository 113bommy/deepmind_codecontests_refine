#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, k, ans;
int x[N], y[N], R[N];
pair<double, int> q[N * 2];
double eps = 1e-10;
int calc(double ang) {
  double dx = sin(ang);
  double dy = cos(ang);
  int top = 0;
  for (int i = (int)(1); i <= (int)(n); i++) {
    double tmp = x[i] * dx + y[i] * dy;
    q[++top] = make_pair(tmp - R[i], 1);
    q[++top] = make_pair(tmp + R[i], -1);
  }
  sort(q + 1, q + top + 1);
  int sum = 0, mx = 0;
  for (int i = (int)(1); i <= (int)(top); i++) mx = max(mx, sum += q[i].second);
  return mx;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = (int)(1); i <= (int)(n); i++)
    scanf("%d%d%d", &x[i], &y[i], &R[i]);
  double st = 0, ed = 2 * acos(-1), step = 0.0005;
  for (; step > eps;) {
    int mx = 0;
    double at;
    for (double i = st; i <= ed; i += step) {
      int vnow = calc(i);
      if (vnow > mx) mx = vnow, at = i;
    }
    ans = max(ans, mx);
    st = at - 5 * step;
    ed = at + 5 * step;
    step /= 5;
  }
  printf("%lld\n", 1ll * k * (k + 1) / 2 + n + 1ll * k * (ans - 1));
}
