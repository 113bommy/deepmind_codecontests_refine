#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
const long long MOD = 1000000007;
int n, k;
long long ans;
long long fac[MAXN];
long long inv[MAXN];
long long f[MAXN];
long long sum[MAXN];
long long power(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i <= 1000000; i++) fac[i] = fac[i - 1] * i % MOD;
  inv[1000000] = power(fac[1000000], MOD - 2);
  for (int i = 1000000; i >= 1; i--) inv[i - 1] = inv[i] * i % MOD;
}
int main() {
  init();
  cin >> n >> k;
  for (int i = k + 1; i <= n; i++) {
    f[i] = i - k - 1;
    (f[i] += sum[i - 1] - sum[i - k - 1] + MOD) %= MOD;
    (f[i] *= fac[i - 2]) %= MOD;
    sum[i] = (sum[i - 1] + f[i] * inv[i - 1]) % MOD;
  }
  for (int i = k + 1; i <= n; i++)
    (ans += f[i] * fac[n - 1] % MOD * inv[i - 1]) %= MOD;
  cout << ans << endl;
  return 0;
}
