#include <bits/stdc++.h>
using namespace std;
long long a[505], b[505], s[505];
int main() {
  long long n, k, sa = 0, sb = 0, ans = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    s[i] = a[i] + b[i];
    sa += a[i];
    ans += sa / k;
    sa %= k;
    sb += b[i];
    ans += sb / k;
    sb %= k;
  }
  int f = 0, t = 0;
  while (sa + sb >= k) {
    f = 0;
    for (int i = t; i < n; i++) {
      if ((a[i] >= sa) && (b[i] >= sb)) {
        f = 1;
        break;
      }
    }
    if (f) break;
    while ((t < n) && (a[t] + b[t] < k)) t++;
    if (t == n) break;
    if (a[t] < sa) {
      sa -= a[t];
      sb = (sb + a[t]) % k;
    } else {
      sb -= b[t];
      sa = (sa + b[t]) % k;
    }
    t++;
    f = 1;
  }
  cout << ans + f << endl;
  return 0;
}
