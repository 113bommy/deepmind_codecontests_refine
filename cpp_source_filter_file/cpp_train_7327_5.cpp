#include <bits/stdc++.h>
using namespace std;
inline int Read() {
  int x = 0, f = 1, c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const int MAXN = 1000005;
const int mod = 1e9 + 7;
int n, m, k, ans, minp, maxp, a[MAXN], bin[MAXN];
int main() {
  n = Read(), m = Read(), k = Read(), minp = n + 1, bin[0] = 1;
  for (int i = 1, x, y; i <= m; i++) {
    x = Read(), y = Read();
    if (y == x + k + 1)
      a[x]++, minp = min(minp, x), maxp = max(maxp, x);
    else if (y ^ x + 1)
      return puts("0"), 0;
  }
  if (maxp - minp > k) return puts("0"), 0;
  n -= k + 1;
  for (int i = 1; i <= n; i++)
    a[i] += a[i - 1], bin[i] = (bin[i - 1] << 1) % mod;
  if (!maxp) {
    ans = 1;
    for (int i = 1; i <= n; i++) ans = (ans + bin[min(i + k, n) - i]) % mod;
  } else
    for (int i = maxp - k; i <= minp; i++)
      ans = (ans + bin[min(i + k, n) - i - (a[min(i + k, n)] - a[i])]) % mod;
  return printf("%d\n", ans), 0;
}
