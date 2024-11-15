#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  int b[110][110], dp[110][110][15][2];
  int i, j, p, r, cr, crp, d;
  char a;
  cin >> n >> m >> k;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      cin >> a;
      b[i][j] = a - '0';
    }
  memset(dp, -1, sizeof(dp));
  for (j = 0; j < m; j++) {
    cr = b[n - 1][j] % (k + 1);
    dp[n - 1][j][cr][0] = b[n - 1][j];
  }
  for (i = n - 2; i >= 0; i--) {
    for (j = 0; j < m; j++) {
      cr = b[i][j] % (k + 1);
      for (p = 0; p <= k; p++) {
        crp = (p - cr + k + 1) % (k + 1);
        r = -1;
        r = (j > 0) ? max(dp[i + 1][j - 1][crp][0], r) : r;
        r = (j < n - 1) ? max(dp[i + 1][j + 1][crp][0], r) : r;
        dp[i][j][p][0] = (r != -1) ? r + b[i][j] : -1;
        dp[i][j][p][1] =
            (r != -1 && j > 0 && dp[i + 1][j - 1][p][0] == r) ? j - 1 : j + 1;
      }
    }
  }
  d = -1;
  int maxVal = -1, val;
  for (i = 0; i < m; i++) {
    val = dp[0][i][0][0];
    if (val > maxVal) {
      maxVal = val;
      d = i;
    }
  }
  int prev;
  r = 0;
  if (d == -1)
    cout << d << endl;
  else {
    string s = "";
    for (i = 0; i < n - 1; i++) {
      prev = d;
      d = dp[i][d][r][1];
      r = (dp[i][prev][r][0] - b[i][prev] + k + 1) % (k + 1);
      if (d > prev)
        s = "L" + s;
      else
        s = "R" + s;
    }
    cout << maxVal << endl;
    cout << d + 1 << endl;
    cout << s << endl;
  }
  return 0;
}
