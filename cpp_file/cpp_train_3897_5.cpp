#include <bits/stdc++.h>
using namespace std;
long long dp[3005][3005], p[3005];
int main() {
  int n, k, i, j;
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> p[i];
  for (i = 1; i <= k; i++) {
    long long M = -16843009000000;
    for (j = 1; j <= n; j++) {
      M = max(M, dp[i - 1][j - 1] - p[j]);
      dp[i][j] = max(dp[i][j - 1], M + p[j]);
    }
  }
  cout << dp[k][n] << endl;
  return 0;
}
