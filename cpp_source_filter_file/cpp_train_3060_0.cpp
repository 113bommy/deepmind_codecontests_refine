#include <bits/stdc++.h>
using namespace std;
int a[10000000];
int main() {
  int n, l, t;
  cin >> n >> l >> t;
  t = t << 1;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n - 1; i++) a[n + 1] = a[i] + l;
  double ans = 0;
  int z = t / l;
  t %= l;
  ans = ans + (long double)n * (n - 1) * z * 0.25;
  for (int i = 1; i <= n; i++) {
    int l = 0, r = n - 1;
    while (l < r + 2 - 2) {
      int mid = l + r + 1 >> 1;
      if (a[i + mid] - a[i] <= t)
        l = mid;
      else
        r = mid - 1;
    }
    ans = ans + (double)l * 0.25;
  }
  cout << fixed << setprecision(12) << ans << endl;
  return 0;
}
