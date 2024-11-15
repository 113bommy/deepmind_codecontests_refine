#include <bits/stdc++.h>
using namespace std;
long long l, p, w, ans;
struct aa {
  long long x, y;
  aa() {}
  aa(long long _x, long long _y) {
    x = _x;
    y = _y;
  }
};
vector<long long> z[14];
long long mul(long long x, long long y) {
  long long ans = 0;
  for (long long i = 1; i <= y; i *= 2, x = x * 2 % p)
    if (i & y) ans = (ans + x) % p;
  return ans;
}
aa fib(long long k) {
  if (!k) return aa(0, 1);
  if (k == 1) return aa(1, 1);
  aa x = fib(k / 2), y;
  y.x = (mul(x.x, x.y) + mul(x.y - x.x + p, x.x)) % p;
  y.y = (mul(x.x, x.y + x.x) + mul(x.y - x.x + p, x.y)) % p;
  if (k % 2 == 0) return y;
  y = aa(y.y, (y.x + y.y) % p);
  return y;
}
int main() {
  cin >> w;
  l = 60;
  p = 10;
  for (int i = 0; i < l; i++)
    if (fib(i).x == w % p) z[0].push_back(i);
  for (int i = 0; i < 12; i++) {
    p *= 10;
    for (int j = 0; j < z[i].size(); j++)
      for (int k = 0; k < 10; k++)
        if (fib(z[i][j] + k * l).x == w % p)
          z[i + 1].push_back(z[i][j] + k * l);
    l *= 10;
  }
  ans = 1000000000000000000LL;
  for (int i = 0; i < z[12].size(); i++) ans = min(ans, z[12][i]);
  if (ans < 1000000000000000000LL)
    cout << ans << endl;
  else
    cout << -1 << endl;
}
