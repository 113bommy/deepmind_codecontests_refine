#include <bits/stdc++.h>
using namespace std;
const int N = 5007;
int dp[N][N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s, t;
  cin >> s;
  int n = s.size();
  s = " " + s;
  for (int i = 1; i <= n; i++) dp[i][i] = 1;
  for (int l = 1; l < n; l++)
    for (int i = 2; i < n; i++) {
      int j = i + l;
      if (s[i] == s[j] && (dp[i + 1][j - 1] || l == 1)) dp[i][j] = 1;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << dp[r][r] - dp[l - 1][r] - dp[r][l - 1] + dp[l - 1][l - 1] << "\n";
  }
}
