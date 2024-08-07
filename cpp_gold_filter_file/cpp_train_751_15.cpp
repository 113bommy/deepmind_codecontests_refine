#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, MOD = 998244353;
long long inv[N], p[N];
int a[N];
long long bp(long long a, long long p) {
  long long r = 1;
  while (p > 0) {
    if (p & 1) r = r * a % MOD;
    a = a * a % MOD;
    p >>= 1;
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int m = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m += a[i];
  }
  for (int i = 1; i < N; i++) {
    inv[i] = bp(i, MOD - 2);
  }
  for (int i = 0; i < m; i++) {
    p[i] = 1;
    if (i > 0) p[i] = (p[i] + p[i - 1] * i % MOD * inv[m]) % MOD;
    long long den =
        (1 - i * inv[m] % MOD + MOD -
         (m - i) * (long long)(n - 2) % MOD * inv[m] % MOD * inv[n - 1] % MOD +
         MOD) %
        MOD;
    p[i] = p[i] * bp(den, MOD - 2) % MOD;
  }
  for (int i = m - 2; i >= 0; i--) {
    p[i] = (p[i] + p[i + 1]) % MOD;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + p[a[i]]) % MOD;
  }
  ans = (ans - p[0] * (n - 1) % MOD + MOD) % MOD;
  ans = ans * inv[n] % MOD;
  cout << ans << "\n";
  return 0;
}
