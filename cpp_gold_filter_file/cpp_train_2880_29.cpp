#include <bits/stdc++.h>
using namespace std;
int n;
double p[110];
double ans;
int main() {
  scanf("%d", &n);
  for (int i = 0; i <= n; i++) scanf("%lf", p + i);
  if (~n & 1) ans = p[n / 2];
  for (int i = 0; i <= (n - 1) / 2; i++) {
    for (int j = n / 2 + 1; j <= n; j++) {
      ans =
          max(ans, (p[j] * (n - 2 * i) + p[i] * (2 * j - n)) / (2 * j - 2 * i));
    }
  }
  printf("%.9lf", ans);
  return 0;
}
