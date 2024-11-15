#include <bits/stdc++.h>
using namespace std;
const int N = 2.7e5, mo = 1e9 + 7;
long long w[N], r[N], lgM = 10, M = 1 << lgM, n, k;
long long jc[N], ny[N];
long long a[N], b[N], f[N], g[N], ans[N];
long long power(long long a, long long b = mo - 2) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mo;
    a = a * a % mo;
    b >>= 1;
  }
  return ans;
}
void dft(long long *a) {
  static long long b[N];
  for (int i = 0; i < M; i++) b[i] = a[i];
  for (int i = 0; i < M; i++) {
    long long p = 1;
    a[i] = 0;
    for (int j = 0; j < M; j++) {
      a[i] = (a[i] + b[j] * p) % mo;
      p = p * (mo - i - 1) % mo;
    }
  }
}
long long h[N];
void idft(long long *a) {
  memset(h, 0, sizeof h);
  for (int i = 0; i < M; i++) b[i] = a[i], a[i] = 0;
  h[0] = 1;
  for (int i = 0; i < M; i++) {
    for (int j = i + 1; j; j--) h[j] = (h[j] * (i + 1) + h[j - 1]) % mo;
    h[0] = h[0] * (i + 1) % mo;
  }
  for (int i = 0; i < M; i++) {
    long long inv = power(i + 1);
    h[0] = h[0] * inv % mo;
    for (int j = 1; j <= M; j++) h[j] = (h[j] - h[j - 1] + mo) * inv % mo;
    long long p = 1;
    for (int j = 0; j < M; j++) {
      if (i != j) p = p * (j - i + mo) % mo;
    }
    p = power(p) * b[i] % mo;
    for (int x = 0; x < M; x++) a[x] = (a[x] + p * h[x]) % mo;
    for (int j = M; j; j--) h[j] = (h[j] * (i + 1) + h[j - 1]) % mo;
    h[0] = h[0] * (i + 1) % mo;
  }
}
void gen(int n, long long *f) {
  for (int i = 0; i <= n; i++)
    if (n - i >= i) f[i] = jc[n - i] * ny[i] % mo * ny[n - 2 * i] % mo;
}
int main() {
  cin >> n;
  k = 1;
  jc[0] = 1;
  for (int i = 1; i <= n + 1; i++) jc[i] = jc[i - 1] * i % mo;
  ny[n + 1] = power(jc[n + 1]);
  for (int i = n + 1; i >= 1; i--) ny[i - 1] = ny[i] * i % mo;
  gen(n / k + 1, f);
  gen(n / k, g);
  dft(f);
  dft(g);
  for (int i = 0; i < M; i++)
    f[i] = power(f[i], n % k * 2) * power(g[i], (k - n % k) * 2) % mo;
  idft(f);
  for (int i = 0; i <= n; i++) f[i] = f[i] * jc[i] % mo * jc[n - i] % mo;
  dft(f);
  memset(g, 0, sizeof g);
  for (int i = 0; i <= n; i++) g[n - i] = ny[i] * ((i & 1 ? mo - 1 : 1)) % mo;
  dft(g);
  for (int i = 0; i < M; i++) ans[i] = f[i] * g[i] % mo;
  idft(ans);
  cin >> k;
  cout << ans[k + n] * ny[k] % mo << endl;
}
