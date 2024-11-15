#include <bits/stdc++.h>
int ans, n, k, m;
bool its[99];
void count(long long l) {
  if (l <= n - m) ++ans, count(l * 10 + 4), count(l * 10 + 7);
}
bool isLucky(int n) {
  if (n == 0) return 0;
  while (n) {
    if (n % 10 != 4 && n % 10 != 7) return false;
    n /= 10;
  }
  return true;
}
int main() {
  int fac[15];
  fac[0] = 1;
  for (int i = 1; i <= 13; ++i) fac[i] = fac[i - 1] * i;
  scanf("%d %d", &n, &k);
  m = 1;
  while (fac[m] < k && m <= n) ++m;
  if (m > 13 || m > n)
    puts("-1");
  else {
    count(4), count(7);
    for (int i = 1; i <= m; ++i) {
      int x = 0, y = 1;
      while (k > fac[m - i]) k -= fac[m - i], ++y;
      for (int j = 1; j <= y; ++j) {
        ++x;
        while (its[x]) ++x;
      }
      its[x] = true;
      if (isLucky(n - m + i) && isLucky(n - m + x)) ++ans;
    }
    printf("%d\n", ans);
  }
  return 0;
}
