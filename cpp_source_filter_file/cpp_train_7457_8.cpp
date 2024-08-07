#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
long long mpow(long long a, long long n, long long M) {
  if (n == 0) return 1;
  long long t = mpow(a, n / 2, M);
  if (n % 2) return t * t % M * a % M;
  return t * t % M;
}
long long getphi(long long x) {
  long long ans = x;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      ans = ans * (i - 1) / i;
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) ans = ans * (x - 1) / x;
  return ans;
}
long long phi[1002];
int n, m;
int w[N], q, l, r;
int lim, cur;
long long mode(long long x, long long y) {
  if (x < y) return x;
  return x % y + y;
}
long long cac(int l, int r, int dep) {
  if (l == r) return w[l];
  if (dep == lim) return 0;
  long long t = cac(l + 1, r, dep + 1);
  long long ans = 1, x = w[l];
  while (t) {
    if (t & 1) ans = mode(ans * x, phi[dep]);
    x = mode(x * x, phi[dep]);
    t >>= 1;
  }
  return ans;
}
int main() {
  scanf("%d %d", &n, &m);
  lim = 0, cur = m;
  phi[0] = m;
  while (m > 1) {
    phi[++lim] = m = getphi(m);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w[i]);
  }
  scanf("%d", &q);
  while (q--) {
    scanf("%d %d", &l, &r);
    printf("%lld\n", cac(l, r, 0) % phi[0]);
  }
}
