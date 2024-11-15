#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007, I2 = (mod + 1) / 2;
long long inv(long long x) {
  return x == 1 ? 1 : (mod - mod / x) * inv(mod % x) % mod;
}
struct F {
  long long a, b;
  F(long long a, long long b) : a(a), b(b) {}
  F operator+(const F &w) const { return F((a + w.a) % mod, (b + w.b) % mod); }
  F operator-(const F &w) const {
    return F((a - w.a + mod) % mod, (b - w.b + mod) % mod);
  }
  F operator*(const F &w) const {
    return F(a * w.a % mod, (a * w.b + b) % mod);
  }
  F operator^(const long long t) const {
    if (!t) return F(1, 0);
    F tmp = ((*this) * (*this)) ^ (t >> 1);
    return t & 1 ? tmp * (*this) : tmp;
  }
  F INV() { return F(inv(a), (mod - b) * inv(a) % mod); }
  long long calc() { return inv((1 - a + mod) % mod) * b % mod; }
  long long sub(long long x) { return (a * x + b) % mod; }
};
long long t, n, m;
long long pw(long long x, long long k) {
  if (!k) return 1;
  long long tmp = pw(x * x % mod, k >> 1);
  return k & 1 ? tmp * x % mod : tmp;
}
long long sum1(long long x, long long k) {
  if (x == 1) return k;
  return (1 - pw(x, k) + mod) * inv((1 - x + mod) % mod) % mod * x % mod;
}
long long sum2(long long x, long long k) {
  if (x == 1) return k * (k + 1) / 2 % mod;
  long long ret = pw(x, k), ix = inv(x);
  ret = ret * ix % mod *
        ((mod - k - 1) * pw(ix, k) % mod * inv((1 - ix + mod) % mod) % mod +
         (1 - pw(ix, k + 1) % mod + mod) *
             inv((1 - ix + mod) * (1 - ix + mod) % mod) % mod) %
        mod;
  return ret;
}
F calc(F w, long long k) {
  long long p = sum1(w.a, k);
  long long q = w.b * sum2(w.a, k) % mod;
  return F(p, q);
}
long long solve(long long n, long long k, F a, F b, F s1, F s2) {
  if (!k) {
    long long x = a.calc();
    return s2.sub(x) * n % mod;
  }
  F bb = b * (a ^ (n / k));
  bb = bb.INV();
  F aa = b * (a ^ (n / k - 1));
  aa = aa.INV();
  F p1 = calc(a, n / k), p2 = calc(a, n / k - 1);
  F ss1 = s1 + F(s2.a, 0) * p1 + F(0, s2.b * n / k % mod);
  F ss2 = s1 + F(s2.a, 0) * p2 + F(0, s2.b * (n / k - 1) % mod);
  return solve(k, n % k, aa, bb, ss1, ss2);
}
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld", &n, &m);
    printf("%lld\n",
           solve(n, m, F(1, 1), F(I2, 1), F(1, 0), F(1, 0)) * inv(n) % mod);
  }
  return 0;
}
