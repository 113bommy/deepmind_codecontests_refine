#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long f[60][60][2], c[60][60], ans;
int n, k, rs, rm, s;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i <= n; ++i) c[i][0] = 1ll;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= i; ++j)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  f[0][0][0] = f[1][0][0] = 1ll;
  for (int i = 2; i <= n; ++i)
    for (int j = 0; j <= i / 2; ++j)
      for (int ls = 0; ls * 2 < i; ++ls)
        for (int lm = 0; lm <= ls / 2; ++lm) {
          rs = i - ls - 1;
          rm = j - lm;
          s = (c[i - 1][ls] * rs) % mod;
          if (ls) s = (s * ls) % mod;
          if (ls == rs) s = (s * 500000004) % mod;
          if (!ls) {
            f[i][j][0] = (f[i][j][0] + f[rs][rm - 1][1] * s % mod) % mod;
            f[i][j][1] = (f[i][j][1] + f[rs][rm][0] * s % mod) % mod;
          } else {
            if (lm && rm)
              f[i][j][0] = (f[i][j][0] + f[ls][lm - 1][1] * f[rs][rm - 1][1] %
                                             mod * s % mod) %
                           mod;
            if (lm)
              f[i][j][1] = (f[i][j][1] +
                            f[ls][lm - 1][1] * f[rs][rm][0] % mod * s % mod) %
                           mod;
            if (rm)
              f[i][j][1] = (f[i][j][1] +
                            f[ls][lm][0] * f[rs][rm - 1][1] % mod * s % mod) %
                           mod;
            f[i][j][1] =
                (f[i][j][1] + f[ls][lm][0] * f[rs][rm][0] % mod * s % mod) %
                mod;
          }
        }
  ans = f[n][k][0];
  if (k) ans = (ans + f[n][k - 1][1]) % mod;
  printf("%I64d\n", ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
