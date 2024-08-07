#include <bits/stdc++.h>
int main() {
  int T, n, m;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    if (m > n / 2) m = n - m;
    int l = 0, r = n, mid, k;
    while (l < r) {
      mid = (l + r) / 2;
      long long res = 1LL * mid * m, x = n, y = 1;
      for (int i = 0; i <= mid && res >= 0 && x; i++)
        k = x < y ? x : y, x -= k, res -= k * i, y = y * (mid - i) / (i + 1);
      if (res < 0 || x)
        l = mid + 1;
      else
        r = mid;
    }
    printf("%d\n", l);
  }
  return 0;
}
