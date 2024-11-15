#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const long long inf = (long long)(1e18) + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> dp(n + 1, inf);
  dp[0] = 0;
  for (int bit = 0; bit < 62; bit++) {
    if (bit) {
      sort(a.begin(), a.end(), [&](long long x, long long y) {
        return x % (1ll << bit) < y % (1ll << bit);
      });
    }
    vector<long long> ndp(n + 1, inf);
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + ((a[i] >> bit) & 1);
    }
    for (int i = 0; i <= n; i++) {
      for (int ch = 0; ch < 2; ch++) {
        int l_1 = pref[i];
        int l_0 = i - l_1;
        int r_1 = pref[n] - l_1;
        int r_0 = (n - i) - r_1;
        int go = 0;
        go += (ch - 0 - 1 < 0) * l_0;
        go += (ch - 1 - 1 < 0) * l_1;
        go += (ch - 0 < 0) * r_0;
        go += (ch - 1 < 0) * r_1;
        int cost = 0;
        cost += ((ch - 0 - 1) & 1) * l_0;
        cost += ((ch - 1 - 1) & 1) * l_1;
        cost += ((ch - 0) & 1) * r_0;
        cost += ((ch - 1) & 1) * r_1;
        ndp[go] = min(ndp[go], dp[i] + cost);
      }
    }
    dp = ndp;
  }
  cout << dp[0] << '\n';
}
