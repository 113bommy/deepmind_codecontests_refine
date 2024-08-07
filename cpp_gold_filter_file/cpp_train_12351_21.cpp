#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
using namespace std;
long long power(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * power(a * a % md, b / 2, md) % md
                      : power(a * a % md, b / 2, md) % md));
}
const int xn = 2e3 + 10;
const int xm = -20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
int n, p, P, dp[xn][xn], pw[2][xn], f[xn], ans[xn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> p >> P;
  p = 1ll * p * power(P, mod - 2, mod) % mod;
  P = (1 - p + mod) % mod;
  pw[0][0] = pw[1][0] = 1;
  for (int i = 1; i < xn; ++i) {
    pw[0][i] = 1ll * pw[0][i - 1] * p % mod;
    pw[1][i] = 1ll * pw[1][i - 1] * P % mod;
  }
  dp[0][0] = dp[1][0] = dp[1][1] = f[1] = 1;
  for (int i = 2; i <= n; ++i) {
    dp[i][0] = f[i] = 1;
    for (int j = 1; j <= i; ++j) {
      dp[i][j] = (1ll * dp[i - 1][j - 1] * pw[0][i - j] % mod +
                  1ll * dp[i - 1][j] * pw[1][j] % mod) %
                 mod;
      if (i == j) continue;
      f[i] = (f[i] - 1ll * dp[i][j] * f[j] % mod + mod) % mod;
      ans[i] =
          (ans[i] + 1ll * dp[i][j] * f[j] % mod *
                        (j * (j - 1) / 2 + j * (i - j) + ans[i - j] + ans[j]) %
                        mod) %
          mod;
    }
    ans[i] = (ans[i] + 1ll * f[i] * i * (i - 1) / 2 % mod) % mod;
    ans[i] = 1ll * ans[i] * power(1 - f[i] + mod, mod - 2, mod) % mod;
  }
  cout << ans[n] << '\n';
  return 0;
}
