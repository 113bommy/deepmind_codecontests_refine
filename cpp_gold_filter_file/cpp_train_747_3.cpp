#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int p = 998244353;
int read() {
  int s = 0;
  char c = getchar(), lc = '+';
  while (c < '0' || '9' < c) lc = c, c = getchar();
  while ('0' <= c && c <= '9') s = s * 10 + c - '0', c = getchar();
  return lc == '-' ? -s : s;
}
void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x < 10)
    putchar(x + '0');
  else {
    write(x / 10);
    putchar(x % 10 + '0');
  }
}
void print(int x, char c = '\n') {
  write(x);
  putchar(c);
}
inline void add(int &x, int y) {
  x += y;
  if (x >= p) x -= p;
}
int power(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = 1LL * ret * a % p;
    a = 1LL * a * a % p;
    b /= 2;
  }
  return ret;
}
int fact[N], inv[N];
int C(int n, int m) {
  if (n < m || n < 0 || m < 0) return 0;
  return 1LL * fact[n] * inv[m] % p * inv[n - m] % p;
}
char a[N];
int l[N], r[N], x[N], y[N], ans = 0;
signed main(signed Recall, char *_902_[]) {
  (void)Recall, (void)_902_;
  scanf("%s", a + 1);
  int n = strlen(a + 1);
  for (int i = 1; i <= n; i++)
    l[i] = l[i - 1] + (a[i] == '('), x[i] = x[i - 1] + (a[i] == '?');
  for (int i = n; i >= 1; i--)
    r[i] = r[i + 1] + (a[i] == ')'), y[i] = y[i + 1] + (a[i] == '?');
  for (int i = fact[0] = 1; i <= n; i++) fact[i] = 1LL * fact[i - 1] * i % p;
  inv[n] = power(fact[n], p - 2);
  for (int i = n; i >= 1; i--) inv[i - 1] = 1LL * inv[i] * i % p;
  for (int i = 1; i < n; i++) {
    int l = ::l[i], x = ::x[i], r = ::r[i + 1], y = ::y[i + 1];
    add(ans, (1LL * l * C(x + y, y + r - l) +
              1LL * x * C(x + y - 1, y - l + r - 1)) %
                 p);
  }
  print(ans);
  return 0;
}
