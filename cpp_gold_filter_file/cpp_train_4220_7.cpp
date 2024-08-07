#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
inline int dec(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
inline int mult(int a, int b) {
  long long t = 1ll * a * b;
  if (t >= mod) t %= mod;
  return t;
}
inline int power(int a, int b) {
  int out = 1;
  while (b) {
    if (b & 1) out = mult(out, a);
    a = mult(a, a);
    b >>= 1;
  }
  return out;
}
int n, m, a1[100010][6], a2[100010][6];
long long f[32];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a1[i][j]);
    }
  }
  for (int i = 1; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a2[i][j]);
    }
  }
  memset(f, 0x3f, sizeof(f));
  f[0] = 0;
  for (int i = 1; i < m; i++) {
    for (int j = 0; j < (1 << n); j++) {
      for (int k = 0; k < n; k++) {
        if (!(j & (1 << k)))
          f[j ^ (1 << k)] = min(f[j ^ (1 << k)], f[j] + a1[i][k]);
      }
      for (int k = 0; k < n; k++) {
        if (((j >> k) ^ (j >> ((k + 1) % n))) & 1) f[j] += a2[i][k];
      }
    }
  }
  printf("%lld\n", f[(1 << n) - 1]);
  return 0;
}
