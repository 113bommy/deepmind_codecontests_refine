#include <bits/stdc++.h>
using namespace std;
double dp[210][210][420];
int main() {
  int n, l, k;
  cin >> n >> l >> k;
  int a[n];
  double p[n];
  for (int i = 0; i < int(n); i++) {
    int x;
    cin >> x;
    p[i] = x / 100.0;
  }
  for (int i = 0; i < int(n); i++) cin >> a[i];
  dp[0][0][k + 203] = 1;
  for (int i = 0; i < int(n); i++) {
    for (int c = 0; c < int(411); c++) {
      for (int m = 0; m < int(201); m++) {
        if (c + a[i] >= 0) {
          dp[i + 1][m + 1][min(410, c + a[i])] += dp[i][m][c] * p[i];
        }
        dp[i + 1][m][c] += dp[i][m][c] * (1 - p[i]);
      }
    }
  }
  double ans = 0;
  for (int c = 203; c <= 410; c++)
    for (int m = l; m <= 200; m++) {
      ans += dp[n][m][c];
    }
  printf("%.20f\n", ans);
  return 0;
}
