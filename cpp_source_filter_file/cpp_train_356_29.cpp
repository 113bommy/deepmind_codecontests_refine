#include <bits/stdc++.h>
using namespace std;
long double f[2333], p[2333], ans, ess;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 2333; i >= 0; i--) f[i] = 0, p[i] = 1.0 / i;
  f[1] = 1.0;
  for (int i = 1; i <= n; i++) {
    for (int j = 2000; j >= 0; j--) {
      if (fabs(f[j]) <= 1e-10) {
        f[j] = 0;
        continue;
      }
      ans += f[j] * j * (0.5 + p[j + 1]);
      ess = f[j] * p[j + 1] * p[k];
      f[j + 1] += ess;
      f[j] -= ess;
    }
  }
  printf("%.12lf\n", (double)ans);
  return 0;
}
