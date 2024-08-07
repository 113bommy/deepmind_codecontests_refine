#include <bits/stdc++.h>
struct {
  inline operator int() {
    int x;
    return scanf("%d", &x), x;
  }
  inline operator long long() {
    long long x;
    return scanf("%lld", &x), x;
  }
  template <class T>
  inline void operator()(T &x) {
    x = *this;
  }
  template <class T, class... A>
  inline void operator()(T &x, A &...a) {
    x = *this;
    this->operator()(a...);
  }
} read;
const int maxn = 200005, mod = 998244353;
int a[maxn];
long long fac[maxn], ifac[maxn];
long long powk[maxn];
inline long long power(long long x, int k) {
  if (k < 0) k += mod - 1;
  long long res = 1;
  while (k) {
    if (k & 1) (res *= x) %= mod;
    (x *= x) %= mod;
    k >>= 1;
  }
  return res;
}
void combinator_init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  ifac[n] = power(fac[n], -1);
  for (int i = n; i; i--) ifac[i - 1] = ifac[i] * i % mod;
}
int main() {
  int n = read, k = read;
  if (k == 1) return puts("0"), 0;
  for (int i = 1; i <= n; i++) read(a[i]);
  a[n + 1] = a[1];
  combinator_init(n);
  int m = 0;
  for (int i = 1; i <= n; i++) m += a[i] != a[i + 1];
  powk[0] = 1;
  for (int i = 1; i <= m; i++) powk[i] = powk[i - 1] * (k - 2) % mod;
  long long ans = 0;
  for (int x = 0; x * 2 <= m; x++)
    (ans += fac[m] * ifac[x] % mod * ifac[x] % mod * ifac[m - x - x] % mod *
            powk[m - x - x]) %= mod;
  ans = (power(k, m) - ans) * (mod + 1) / 2 % mod;
  (ans *= power(k, n - m)) %= mod;
  printf("%lld\n", ans);
}
