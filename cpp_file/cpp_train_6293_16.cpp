#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, maxn = 100005;
long double f[maxn];
long double C(int n, int m) { return f[n] - f[m] - f[n - m]; }
int main() {
  f[0] = 0;
  for (int i = 1; i <= 1e5; i++) f[i] = f[i - 1] + log(1.0 * i);
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  long double ans = 0;
  for (int x = 0; x <= n; x++)
    for (int y = 0; y <= n; y++)
      if (n * (x + y) - x * y <= k) {
        int z = n * (x + y) - x * y;
        long double temp = C(n, x) + C(n, y) + C(m - z, k - z) - C(m, k);
        ans = min((long double)1e99, ans + exp(temp));
      }
  printf("%.10f\n", (double)ans);
  return 0;
}
