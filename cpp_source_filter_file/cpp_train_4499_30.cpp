#include <bits/stdc++.h>
using namespace std;
const int MAX = 7;
long long a[MAX], dp[MAX][2];
bool k[MAX];
int main() {
  a[0] = a[1] = 1;
  for (int i = 2; i < MAX; i++) a[i] = a[i - 1] + a[i - 2];
  int t;
  cin >> t;
  while (t--) {
    memset(k, 0, sizeof k);
    long long n, p, l = 0, ans = 0;
    cin >> n;
    for (int i = MAX - 1; i >= 1 && n; i--)
      if (n >= a[i]) k[i] = true, n -= a[i];
    dp[l][0] = 1;
    for (int i = 0; i < MAX; i++)
      if (k[i]) {
        dp[i][0] = dp[l][0] + dp[l][1];
        dp[i][1] = (i - l - 1) / 2 * dp[l][0] + (i - l) / 2 * dp[l][1];
        ans = dp[i][0] + dp[i][1], l = i;
      }
    cout << ans << '\n';
  }
}
