#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
long long n, m, ta, tb, k;
long long a[N], b[N], ans;
int main() {
  cin >> n >> m >> ta >> tb >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  if (k >= n) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i <= min(n, k + 1); i++) {
    int l = 0, r = m + 1;
    while (r - l > 1) {
      int mm = (l + r) >> 1;
      if (b[mm] >= a[i] + ta)
        r = mm;
      else
        l = mm;
    }
    r += k - i + 1;
    if (r > m)
      ans = 1e18;
    else
      ans = max(ans, b[r] + tb);
  }
  if (ans == 1e18)
    cout << -1;
  else
    cout << ans;
  return 0;
}
