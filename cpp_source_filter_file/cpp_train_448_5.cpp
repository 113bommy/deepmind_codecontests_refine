#include <bits/stdc++.h>
using namespace std;
long long n, a[111111], ans, m, cx;
int main() {
  scanf("%d", &n);
  m = n - 1;
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  ans = 0;
  cx = (1 << 20);
  for (int i = 0; i < m; ++i) {
    while (i + cx > m) cx >>= 1;
    ans += a[i];
    a[i + cx] += a[i];
    printf("%d\n", ans);
  }
  return 0;
}
