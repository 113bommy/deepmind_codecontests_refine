#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 7;
int a[maxn];
int dp[2][57][107];
int premaxx[maxn][57];
int n, k, p;
void solve() {
  for (int i = 1; i <= n; i++) premaxx[i][1] = (premaxx[i - 1][1] + a[i]) % p;
  dp[1][1][a[1]] = a[1];
  for (int i = 1; i <= n; i++) {
    memset(dp[i % 2], 0, sizeof(dp[i % 2]));
    for (int ki = 2; ki <= k; ki++) {
      if (ki > i) continue;
      for (int pi = 0; pi < p; pi++) {
        int pt = dp[(i - 1) % 2][ki][pi] - pi + (pi + a[i]) % p;
        int px = (pi + a[i]) % p;
        dp[i % 2][ki][px] = max(dp[i % 2][ki][px], pt);
        premaxx[i][ki] = max(premaxx[i][ki], dp[i % 2][ki][px]);
        dp[i % 2][ki][a[i]] =
            max(dp[i % 2][ki][a[i]], premaxx[(i - 1)][ki - 1] + a[i]);
        premaxx[i][ki] = max(premaxx[i][ki], dp[i % 2][ki][a[i]]);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k >> p;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] %= p;
  }
  solve();
  cout << premaxx[n][k] << endl;
  return 0;
}
