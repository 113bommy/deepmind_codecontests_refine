#include <bits/stdc++.h>
using namespace std;
const int dx44[6] = {0, -1, -1, 1, 1};
const int dy44[6] = {0, -1, 1, -1, 1};
const int dx4[6] = {0, 1, 0, -1};
const int dy4[6] = {1, 0, -1, 0};
const int dx8[9] = {0, -1, 0, 1, 0, 1, 1, -1, -1};
const int dy8[9] = {0, 0, 1, 0, -1, 1, -1, 1, -1};
const int dx82[9] = {0, -1, -1, 1, 1, 2, 2, -2, -2};
const int dy82[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};
void update(long long &x, long long v) {
  if (x == -1)
    x = v;
  else if (x > v)
    x = v;
}
long long po(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
}
void extgcd(long long a, long long b, long long &d, long long &x,
            long long &y) {
  if (!b) {
    d = a;
    x = 1;
  } else {
    extgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
long long inverse(long long a, long long n) {
  long long d, x, y;
  extgcd(a, n, d, x, y);
  return d == 1 ? (x + n) % n : -1;
}
const int maxn = 5e3 + 15;
const double PI = acos(-1.0);
const long long mod = 998244353;
long long n, k;
long long val[maxn];
long long dp[maxn][maxn];
void solve() {
  scanf("%lld", &(n));
  scanf("%lld", &(k));
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &(val[i]));
  }
  int mid = 2500;
  dp[0][mid] = 1;
  for (int i = 1; i <= n; i++) {
    for (int x = 1; x <= 5000; x++) {
      int xk = (i == 1 ? n : i - 1);
      if (val[i] == val[xk]) {
        dp[i][x] = dp[i - 1][x] * k % mod;
      } else {
        dp[i][x] =
            dp[i - 1][x + 1] + dp[i - 1][x - 1] + (k - 2) * dp[i - 1][x] % mod;
        dp[i][x] %= mod;
      }
    }
  }
  long long ans = 0;
  for (int i = 2501; i <= 5000; i++) {
    ans += dp[n][i];
    ans %= mod;
  }
  printf("%lld\n", ans);
}
int main() {
  solve();
  return 0;
}
