#include <bits/stdc++.h>
using namespace std;
long long d[1000000], ans = 0, x, y, z, a, b, c, tmp, n, sum;
int tot = 0;
int main() {
  cin >> n;
  if (!(n % 3)) {
    n /= 3;
    for (x = 1; x * x <= n; x++)
      if (!(n % x)) d[++tot] = x;
    for (int i = 1; i <= tot; i++) {
      x = d[i];
      if (x * x * x > n) break;
      tmp = n / x;
      for (int j = i; j <= tot; j++) {
        if (tmp % d[j]) continue;
        y = d[j];
        z = tmp / y;
        sum = x + y + z;
        if (sum % 2) continue;
        if (z < y) break;
        if (x + y <= z) continue;
        a = sum - z;
        b = sum - y;
        c = sum - x;
        if (a == c)
          ans += 1;
        else if (a == b || b == c)
          ans += 3;
        else
          ans += 6;
      }
    }
  }
  cout << ans;
  return 0;
}
