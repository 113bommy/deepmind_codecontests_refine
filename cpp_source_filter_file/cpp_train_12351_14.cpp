#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int inf = 1e9;
int n;
long long a, b, p;
long long cache[2001], strong[2001], lost[2001][2001];
long long power(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) res = res * a % mod;
    a = a * a % mod;
    p >>= 1;
  }
  return res;
}
long long inv(long long a) { return power(a, mod - 2); }
int main() {
  scanf("%d%lld%lld", &n, &a, &b);
  p = a * inv(b);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || j == i)
        lost[i][j] = 1;
      else
        lost[i][j] = (lost[i - 1][j - 1] * power(p, i - j) % mod +
                      lost[i - 1][j] * power((1 - p + mod) % mod, j) % mod) %
                     mod;
    }
  }
  strong[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++)
      strong[i] = (strong[i] + strong[j] * lost[i][j] % mod) % mod;
    strong[i] = (1 - strong[i] + mod) % mod;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++)
      cache[i] = (cache[i] + lost[i][j] * strong[j] % mod *
                                 ((j * (i - j) % mod + j * (j - 1) / 2 +
                                   cache[j] + cache[i - j]) %
                                  mod) %
                                 mod) %
                 mod;
    cache[i] = (cache[i] + strong[i] * (i * (i - 1) / 2) % mod) % mod *
               inv((1 - strong[i] + mod) % mod) % mod;
  }
  printf("%lld\n", cache[n]);
  return 0;
}
