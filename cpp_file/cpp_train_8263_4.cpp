#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int n, c1, c2;
int a[10];
long long f[501];
long long c[501][501];
long long dp[501][501];
long long gao(int a, int b) {
  if (a == 0 && b == 0) {
    return 1;
  }
  if (dp[a][b] == -1) {
    long long& cur = dp[a][b] = 0;
    if (a > 0) {
      if (a >= 1) {
        for (int i = 0; i <= b; ++i) {
          cur = (cur + gao(a - 1, b - i) * c[b][i] % MOD * f[i]) % MOD;
        }
      }
      if (a >= 2) {
        for (int i = 0; i <= b; ++i) {
          cur = (cur +
                 gao(a - 2, b - i) * c[b][i] % MOD * (a - 1) % MOD * f[i + 1]) %
                MOD;
        }
      }
    } else {
      for (int i = 0; i < b; ++i) {
        cur = (cur + gao(a, b - i - 1) * c[b - 1][i] % MOD * f[i]) % MOD;
      }
    }
  }
  return dp[a][b];
}
int main() {
  for (int i = f[0] = 1; i <= 500; ++i) {
    f[i] = f[i - 1] * i % MOD;
  }
  for (int i = 0; i <= 500; ++i) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }
  c1 = c2 = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ++(a[i] == 1 ? c1 : c2);
  }
  memset(dp, -1, sizeof(dp));
  int res = gao(c1, c2) % MOD;
  printf("%d\n", res);
  return 0;
}
