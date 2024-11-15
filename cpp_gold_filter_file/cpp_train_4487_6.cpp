#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[2 * n];
  for (int i = 0; i < 2 * n; i++) cin >> a[i];
  sort(a, a + 2 * n);
  long long ans = 1e18;
  for (int i = 0; i <= n; i++) {
    int h_m = i == 0 ? a[n] : a[0];
    int h_ = i == n ? a[n - 1] : a[2 * n - 1];
    long long temp = (a[i + n - 1] - a[i]) * 1LL * (h_ - h_m);
    ans = min(ans, temp);
  }
  cout << ans;
  return 0;
}
