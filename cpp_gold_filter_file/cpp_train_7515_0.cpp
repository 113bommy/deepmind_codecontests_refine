#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int p[maxn];
int vis[maxn], cnt;
const int S = 20;
long long mult_mod(long long a, long long b, long long c) {
  a %= c;
  b %= c;
  long long ret = 0;
  while (b) {
    if (b & 1) {
      ret += a;
      ret %= c;
    }
    a <<= 1;
    if (a >= c) a %= c;
    b >>= 1;
  }
  return ret;
}
long long pow_mod(long long x, long long n, long long mod) {
  if (n == 1) return x % mod;
  x %= mod;
  long long tmp = x;
  long long ret = 1;
  while (n) {
    if (n & 1) ret = mult_mod(ret, tmp, mod);
    tmp = mult_mod(tmp, tmp, mod);
    n >>= 1;
  }
  return ret;
}
bool check(long long a, long long n, long long x, long long t) {
  long long ret = pow_mod(a, x, n);
  long long last = ret;
  for (int i = 1; i <= t; i++) {
    ret = mult_mod(ret, ret, n);
    if (ret == 1 && last != 1 && last != n - 1) return true;
    last = ret;
  }
  if (ret != 1) return true;
  return false;
}
bool Miller_Rabin(long long n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if ((n & 1) == 0) return false;
  long long x = n - 1;
  long long t = 0;
  while ((x & 1) == 0) {
    x >>= 1;
    t++;
  }
  for (int i = 0; i < S; i++) {
    long long a = rand() % (n - 1) + 1;
    if (check(a, n, x, t)) return false;
  }
  return true;
}
long long factor[maxn];
int tol;
long long gcd(long long a, long long b) {
  if (a == 0) return 1;
  if (a < 0) return gcd(-a, b);
  while (b) {
    long long t = a % b;
    a = b;
    b = t;
  }
  return a;
}
long long Pollard_rho(long long x, long long c) {
  long long i = 1, k = 2;
  long long x0 = rand() % x;
  long long y = x0;
  while (1) {
    i++;
    x0 = (mult_mod(x0, x0, x) + c) % x;
    long long d = gcd(y - x0, x);
    if (d != 1 && d != x) return d;
    if (y == x0) return x;
    if (i == k) {
      y = x0;
      k += k;
    }
  }
}
void findfac(long long n) {
  if (n == 1) return;
  if (Miller_Rabin(n)) {
    factor[tol++] = n;
    return;
  }
  long long p = n;
  while (p >= n) p = Pollard_rho(p, rand() % (n - 1) + 1);
  findfac(p);
  findfac(n / p);
}
long long a[maxn], b[maxn], s[maxn];
int main() {
  int n;
  cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }
  tol = 0;
  findfac(sum);
  long long ans = 4e18;
  for (int i = 0; i < tol; i++) {
    long long ss = 0;
    long long d = factor[i];
    for (int j = 1; j <= n; j++) {
      b[j] = a[j] % d;
    }
    for (int j = 1; j <= n; j++) {
      ss += min(d - b[j], b[j]);
      b[j + 1] = (b[j + 1] + b[j] % d + d) % d;
    }
    ans = min(ans, ss);
  }
  if (ans == 4e18)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
