#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[4];
  char b[3];
  bool isok = true;
  cin >> a[0] >> a[1] >> a[2] >> a[3] >> b[0] >> b[1] >> b[2];
  long long ans = 1000000000000;
  sort(a, a + 4);
  for (; isok; isok = next_permutation(a, a + 4)) {
    long long res = a[0], k1 = 0, k2 = 0;
    for (int i = 0; i < 3; i++)
      if (b[i] == '+')
        res += a[i + 1];
      else
        res *= a[i + 1];
    ans = min(ans, res);
    res = 0;
    if (b[0] == '+')
      k1 = a[0] + a[1];
    else
      k1 = a[0] * a[1];
    if (b[1] == '+')
      k2 = a[2] + a[3];
    else
      k2 = a[2] * a[3];
    if (b[2] == '*')
      res = k1 * k2;
    else
      res = k1 + k2;
    ans = min(ans, res);
  }
  cout << ans;
  return 0;
}
