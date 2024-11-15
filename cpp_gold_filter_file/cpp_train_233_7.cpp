#include <bits/stdc++.h>
const long long mod = 998244353;
const long long MaxN = 6e5 + 10;
std::vector<long long> v;
std::pair<long long, long long> a[MaxN];
long long n, m, k, ans, c[MaxN], fac[MaxN], inv[MaxN];
long long lowbit(long long x) { return x & (-x); }
long long C(long long n, long long m) {
  if (n > m) return 0;
  return ((fac[m] * inv[n]) % mod) * inv[m - n] % mod;
}
void add(long long pos, long long val) {
  while (pos <= m) c[pos] += val, pos += lowbit(pos);
}
long long query(long long pos) {
  long long ret = 0;
  while (pos) ret += c[pos], pos -= lowbit(pos);
  return ret;
}
long long read() {
  long long x = 0;
  char ch = getchar();
  while (ch > '9' || ch < '0') ch = getchar();
  while (ch <= '9' && ch >= '0')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return x;
}
long long fast_pow(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % mod;
    a = (a * a) % mod, b >>= 1;
  }
  return ret;
}
void prework() {
  for (int i = 1; i <= n; i++)
    v.push_back(a[i].first), v.push_back(a[i].second);
  std::sort(v.begin(), v.end()),
      v.erase(std::unique(v.begin(), v.end()), v.end());
  for (int i = 1; i <= n; i++) {
    a[i].first =
        std::lower_bound(v.begin(), v.end(), a[i].first) - v.begin() + 1;
    a[i].second =
        std::lower_bound(v.begin(), v.end(), a[i].second) - v.begin() + 1;
    m = std::max(a[i].first, m), m = std::max(a[i].second, m);
  }
  inv[0] = fac[0] = 1;
  for (int i = 1; i <= 300000; i++) fac[i] = fac[i - 1] * i % mod;
  inv[300000] = fast_pow(fac[300000], mod - 2);
  for (int i = 299999; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
int main() {
  n = read(), k = read();
  if (k == 1) return 0 * printf("%lld\n", n);
  for (int i = 1; i <= n; i++) a[i].first = read(), a[i].second = read();
  std::sort(a + 1, a + n + 1), prework();
  for (int i = 1; i <= n; i++) {
    long long x = i - 1 - query(a[i].first - 1);
    ans = (((ans) + (C(k - 1, x))) % mod), add(a[i].second, 1);
  }
  printf("%lld\n", ans);
  return 0;
}
