#include <bits/stdc++.h>
using namespace std;
long long int dp[100][100], ans, n, h;
int main() {
  cin >> n >> h;
  for (int i = 0; i <= n; i++) {
    dp[0][i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int s = 0; s < i; s++) {
        dp[i][j] += (dp[i - s - 1][j - 1] * dp[s][j - 1]);
      }
    }
  }
  cout << (dp[n][n] - dp[n][h - 1]);
}
