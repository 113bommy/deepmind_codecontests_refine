#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  int fh = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= fh;
}
struct Info {
  long long a, b, c;
} a[210], s[210];
long long n, t, K, f[210][210][2], g[210][210][2];
long long ne(long long x) { return x / K + (x % K != 0); }
int main() {
  read(n);
  read(t);
  read(K);
  for (int i = 1; i <= n; i++) {
    read(a[i].a);
    read(a[i].b);
    read(a[i].c);
  }
  a[n + 1].a = 1e17;
  a[n + 1].c = 1e17 * 2;
  for (int i = 1; i <= n + 1; i++) {
    s[i].a = s[i - 1].a + a[i].a;
    s[i].b = s[i - 1].b + a[i].b;
    s[i].c = s[i - 1].c + a[i].c;
  }
  for (int i = 1; i <= n + 1; i++)
    for (int j = 0; j <= t; j++)
      f[i][j][0] = f[i][j][1] = g[i][j][0] = g[i][j][1] = 1e17;
  for (int i = 1; i <= n + 1; i++) {
    f[i][0][0] = f[i][0][1] = g[i][0][0] = 0;
    if (ne(s[i - 1].a) * K <= s[i].a)
      g[i][0][1] = ne(s[i - 1].a);
    else
      g[i][0][1] = 1e17;
  }
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= t; j++) {
      for (int k = 0; k <= 1; k++) {
        if (j * a[i].b + a[i].a * k <= a[i].c) {
          if (f[i - 1][j][k] != 1e17) {
            f[i][j][k] = min(f[i][j][k], f[i - 1][j][k]);
            long long su = ne(s[i - 1].a * k + s[i - 1].b * j);
            if (su * K <= s[i].a * k + s[i].b * j)
              g[i][j][k] = min(g[i][j][k], su);
          }
        }
        for (int lt = 0; lt < j; lt++) {
          if (g[i][lt][k] != 1e17) {
            long long x = lt * s[i].b + s[i].a * k - g[i][lt][k] * K;
            long long y = a[i].c - (j - lt) * a[i].b - (x % K);
            if (y < 0) continue;
            long long z = min(x, (x % K) + (y / K) * K);
            long long no = (x - z) / K;
            if (f[i - 1][j - lt][0] != 1e17) {
              f[i][j][k] =
                  min(f[i][j][k], g[i][lt][k] + no + f[i - 1][j - lt][0]);
              long long n1 = ne(s[i - 1].b * (j - lt));
              if (n1 * K <= s[i - 1].b * (j - lt) + z)
                g[i][j][k] = min(g[i][j][k], g[i][lt][k] + no + n1);
            }
          }
        }
      }
    }
  }
  cout << f[n + 1][t][1] << endl;
  return 0;
}
