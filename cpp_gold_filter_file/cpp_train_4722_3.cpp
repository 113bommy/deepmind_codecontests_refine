#include <bits/stdc++.h>
using namespace std;
map<long long, long long> dp;
int main() {
  long long k, b;
  int n;
  cin >> k >> b >> n;
  dp[0] = 1;
  long long z = 0, tmp = 0;
  long long m = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    m = (m + x) % (k - 1);
    ans += dp[(m - b + k - 1) % (k - 1)];
    dp[m]++;
    if (!x)
      z += ++tmp;
    else
      tmp = 0;
  }
  if (b == 0)
    ans = z;
  else if (b == k - 1)
    ans -= z;
  cout << ans << endl;
  return 0;
}
