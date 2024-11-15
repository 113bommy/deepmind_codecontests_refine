#include <bits/stdc++.h>
using namespace std;
long long dp[1000005];
int k;
int f[6];
int n;
int pw[6];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> k;
  for (int i = 0; i < 6; i++) cin >> f[i];
  cin >> n >> n;
  fill(dp, dp + 1000005, -1000000000000000009);
  dp[0] = 0;
  pw[0] = 1;
  for (int i = 1; i < 6; i++) pw[i] = pw[i - 1] * 10;
  for (int i = 0; i <= 5; i++) {
    long long cur = 1;
    long long left = 3 * (k - 1);
    while (left > 0) {
      cur = min(cur, left);
      long long val = cur * f[i];
      long long w = 1ll * pw[i] * 3 * cur;
      for (int j = n; j >= w; j--) dp[j] = max(dp[j], dp[j - w] + val);
      left -= cur;
      cur *= 2;
    }
  }
  long long ans = -1000000000000000009;
  for (int x = 0; x <= n; x++) {
    long long ff = 0;
    int tx = x;
    for (int i = 0; i <= 5; i++) {
      if (tx % 10 % 3 == 0) ff += 1ll * tx % 10 / 3 * f[i];
      tx /= 10;
    }
    ans = max(ans, ff + dp[n - x]);
  }
  cout << ans << endl;
}
