#include <bits/stdc++.h>
long long t, n, m;
bool check(int k) {
  long long o, i, x = 1, y = m * k, lef = n - 1;
  for (i = 1; i <= k && y / i > 0 && lef > 0; i++) {
    x = x * (k - i + 1) / i;
    o = y / i < x ? y / i : x;
    lef -= o, y -= o * i;
  }
  return lef <= 0;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    int l = 0, r = n, mid;
    while (l != r) {
      mid = (l + r) / 2;
      if (check(mid))
        r = mid;
      else
        l = mid + 1;
    }
    printf("%d\n", l);
  }
}
