#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long int INF = 1e18;
long long int k, f[6];
vector<vector<long long int>> dp, slide;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> k;
  for (int i = 0; i < (int)(6); i++) cin >> f[i];
  vector<vector<long long int>> dp(6);
  int from = 6, pot = 10;
  dp.resize(from + 1);
  dp[from].push_back(0);
  slide.resize(from + 1);
  slide[from].push_back(0);
  for (int i = (int)(from)-1; i >= ((int)0); i--) {
    dp[i].resize(pot);
    slide[i].resize(pot);
    long long int s = 9 * (k - 1);
    for (int n = 0; n < (int)(pot); n++) {
      if (n >= s) {
        int d = (n - s) % 10;
        if (d % 3)
          dp[i][n] = s / 3 * f[i] + dp[i + 1][(n - s - d) / 10];
        else
          dp[i][n] = (s + d) / 3 * f[i] + dp[i + 1][(n - s - d) / 10];
      }
      int d = n % 10;
      for (int r = 0; r < (int)(3); r++) {
        int start = 10 * r + d;
        if (start > n) continue;
        long long int add = f[i] * (start / 3 + (n - start) / 3);
        dp[i][n] = max(dp[i][n], slide[i + 1][(n - start) / 10] + add);
        int top = min(s - 1, (long long int)n);
        int diff = (top - start) % 30;
        if (diff < 0) diff += 30;
        top -= diff;
        for (int use = top, it = 0; it < 10 && use >= start; use -= 30, it++)
          dp[i][n] =
              max(dp[i][n], f[i] * (use / 3) + dp[i + 1][(n - use) / 10]);
      }
    }
    if (i) {
      int len = max(0LL, s / 10 - 5);
      for (int r = 0; r < (int)(3); r++) {
        deque<pair<int, long long int>> q;
        for (int j = r; j < pot; j += 3) {
          long long int put = dp[i][j] - f[i - 1] * (10 * j / 3);
          while (!q.empty() && q.back().second <= put) q.pop_back();
          q.emplace_back(j, put);
          while (!q.empty() && j - q.front().first >= len) q.pop_front();
          slide[i][j] = q.front().second;
          slide[i][j] = q.empty() ? -INF : q.front().second;
        }
      }
    }
    pot *= 10;
  }
  int q;
  cin >> q;
  while (q--) {
    int ni;
    cin >> ni;
    cout << dp[0][ni] << '\n';
  }
  return 0;
}
