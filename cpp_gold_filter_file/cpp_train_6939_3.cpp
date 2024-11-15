#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a, b, f[200010], g[200010];
struct orz {
  long long w, h, c;
} x[200010];
inline bool cmp(orz a, orz b) { return a.w < b.w || a.w == b.w && a.h < b.h; }
inline long long gcd(long long n, long long m) { return m ? gcd(m, n % m) : n; }
inline long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
inline long long calc(long long n) {
  int i, j, k = 1;
  for (i = 2; (long long)i * i <= n; i++)
    if (n % i == 0) {
      j = 1;
      while (n % i == 0) n /= i, j++;
      k *= j;
    }
  if (n > 1) k *= 2;
  return k;
}
int main() {
  int i, j, k = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%lld%lld%lld", &x[i].w, &x[i].h, &x[i].c);
  sort(x + 1, x + n + 1, cmp);
  for (i = 1; i <= n && (i == 1 || x[i].w == x[i - 1].w); i++)
    ;
  i--;
  if (n % i) {
    printf("0\n");
    return 0;
  }
  m = n / i;
  n = i;
  swap(n, m);
  for (i = m + 1; i <= n * m; i++)
    if (x[i].h != x[i - m].h) break;
  if (i <= n * m) {
    printf("0\n");
    return 0;
  }
  for (i = 1, a = 0; i <= m; i++) a = gcd(a, x[i].c);
  for (i = m + 1, b = 1; i <= n * m; i += m)
    b = lcm(b, x[1].c / gcd(x[1].c, x[i].c));
  if (a % b) {
    printf("0\n");
    return 0;
  }
  f[1] = b;
  for (i = 1; i <= m; i++) g[i] = x[i].c / f[1];
  for (i = 2; i <= n; i++) f[i] = x[(i - 1) * m + 1].c / g[1];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (x[(i - 1) * m + j].c != f[i] * g[j]) k = 1;
  if (k) {
    printf("0\n");
    return 0;
  }
  printf("%d\n", calc(a / b));
  return 0;
}
