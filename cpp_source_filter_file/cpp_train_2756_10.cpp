#include <bits/stdc++.h>
using namespace std;
double a[110000], b[110000];
int n;
int check(double a1, double a2) {
  int i, cnt = 0;
  for (i = 1; i <= n; i++)
    if (!(fabs(a[i] - a1) < 1e-6)) {
      cnt++;
      a1 *= a2;
    }
  if (cnt == n) return 0;
  if (cnt == n - 1) return 1;
  return 2;
}
int main() {
  int i, ans = 2, tot = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%lf", &a[i]);
  for (i = 1; i <= n; i++)
    if (!(fabs(a[i]) < 1e-6)) b[++tot] = a[i];
  ans = min(check(0, 0), check(b[1], 0));
  if (tot >= 1) ans = min(ans, check(b[1], 1));
  if (tot >= 2) ans = min(ans, check(b[1], b[2] / b[1]));
  if (tot >= 3)
    ans = min(ans, min(check(b[1], b[3] / b[1]), check(b[2], b[3] / b[2])));
  printf("%d\n", ans);
  return 0;
}
