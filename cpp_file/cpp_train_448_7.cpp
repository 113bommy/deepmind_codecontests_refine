#include <bits/stdc++.h>
int main() {
  int n, i, a[100100], ans[100100], t;
  while (scanf("%d", &n) == 1) {
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (t = 1; t < n; t = t * 2) {
    }
    t = t / 2;
    a[0] = 0;
    ans[0] = 0;
    for (i = 1; i < n; i++) {
      if (i + t <= n) {
        ans[i] = ans[i - 1] + a[i];
        a[i + t] += a[i];
      } else {
        t = t / 2;
        ans[i] = ans[i - 1] + a[i];
        a[i + t] += a[i];
      }
    }
    for (i = 1; i < n; i++) printf("%d\n", ans[i]);
  }
  return 0;
}
