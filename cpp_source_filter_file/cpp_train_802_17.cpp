#include <bits/stdc++.h>
using namespace std;
long long n, m, d, nn = 0, a[500069];
pair<long long, long long> spc[500069];
int main() {
  long long i, k, p;
  scanf("%lld%lld%lld", &n, &m, &d);
  for (i = 1; i <= n; i++) {
    scanf("%lld", a + i);
  }
  sort(a + 1, a + n + 1);
  nn++;
  spc[nn] = {a[1], 1};
  for (i = 1; i <= n; i++) {
    p = lower_bound(spc + 1, spc + nn + 1, make_pair(a[i] - d, 0ll)) - spc;
    if (p <= nn) {
      k = spc[p].second;
    } else {
      k = 1e18;
    }
    if (i - k + 1 >= m) {
      if (i == n) {
        printf("YES\n");
        return 0;
      }
      nn++;
      spc[nn] = {a[i + 1], i};
    }
  }
  printf("NO\n");
}
