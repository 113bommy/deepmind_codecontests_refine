#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int MAXN = 510;
int dp[MAXN][MAXN];
int c[MAXN][MAXN];
int main() {
  int cnt1, cnt2;
  cnt1 = cnt2 = 0;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if (a == 1)
      cnt1++;
    else
      cnt2++;
  }
  dp[0][0] = 1;
  c[0][0] = 1;
  for (int i = 0; i <= cnt2; i++)
    for (int j = 0; j <= cnt2; j++) {
      if (i) c[i][j] = (c[i][j] + c[i - 1][j]) % MOD;
      if (i && j) c[i][j] = (c[i][j] + c[i - 1][j - 1] * 1LL * j) % MOD;
    }
  for (int i = 0; i <= cnt1; i++)
    for (int j = 0; j <= cnt2; j++) {
      if (i) {
        dp[i][j] = 0;
        for (int k = 0; k <= j; k++)
          dp[i][j] = (dp[i][j] + dp[i - 1][j - k] * 1LL * c[j][k]) % MOD;
        if (i >= 2) {
          dp[i][j] = (dp[i][j] + dp[i - 2][j] * (i - 1)) % MOD;
          for (int k = 1; k <= j; k++)
            dp[i][j] = (dp[i][j] + (dp[i - 2][j - k] * 1LL * c[j][k]) % MOD *
                                       (i - 1) * (k + 1)) %
                       MOD;
        }
      } else {
        if (j) dp[i][j] = (dp[i][j - 1] * 1LL * j) % MOD;
      }
    }
  printf("%d\n", dp[cnt1][cnt2]);
  ;
  return 0;
}
