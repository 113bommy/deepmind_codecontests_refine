#include <bits/stdc++.h>
using namespace std;
long long a, b, x, y, k, ans, n, m, p;
int main() {
  cin >> n >> m >> x >> y >> k;
  while (k--) {
    cin >> a >> b;
    if (!a)
      p = (b > 0) ? (m - y) / b : (y - 1) / -b;
    else if (!b)
      p = (a > 0) ? (n - x) / a : (x - 1) / -a;
    else
      p = min(((b > 0) ? (m - y) / b : (y - 1) / -b),
              ((a > 0) ? (n - x) / a : (x - 1) / -a));
    x += p * a, y += p * b, ans += p;
  }
  cout << ans << endl;
}
