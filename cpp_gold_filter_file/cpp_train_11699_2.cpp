#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  if (n + k < m) {
    printf("0\n");
    return 0.0;
  }
  double ans = 1.0;
  for (int i = 0; i < k + 1; i++) ans *= 1.0 * (m - i) / (n + 1 + i);
  printf("%lf\n", 1 - ans);
  return 0;
}
