#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005, MOD = 1000000007;
int a[MAXN], fac[MAXN / 2], inv[MAXN / 2];
int C(int n, int m) {
  return (long long)fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  if (n == 1) {
    printf("%d", a[0]);
    return 0;
  }
  if (n & 1) {
    bool add = true;
    for (int i = 1; i < n; i++) {
      if (add)
        a[i - 1] = (a[i - 1] + a[i]) % MOD;
      else
        a[i - 1] = (a[i - 1] - a[i] + MOD) % MOD;
      add ^= 1;
    }
    n--;
  }
  fac[0] = 1;
  for (int i = 1; i < n / 2; i++) fac[i] = (long long)fac[i - 1] * i % MOD;
  inv[0] = inv[1] = 1;
  for (int i = 2; i < n / 2; i++)
    inv[i] = (long long)(MOD - MOD / i) * inv[MOD % i] % MOD;
  for (int i = 2; i < n / 2; i++) inv[i] = (long long)inv[i - 1] * inv[i] % MOD;
  int x = 0, y = 0;
  for (int i = 0; i < n; i += 2) {
    int c = C(n / 2 - 1, i / 2);
    x = (x + (long long)c * a[i]) % MOD;
    y = (y + (long long)c * a[i + 1]) % MOD;
  }
  if (n % 2)
    (x += y) %= MOD;
  else
    (x += MOD - y) %= MOD;
  printf("%d", x);
  return 0;
}
